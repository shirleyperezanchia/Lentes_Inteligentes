from flask import Flask, request, jsonify, render_template, Response
import sqlite3
import csv
import io
import os
import socket
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime

import cv2
import numpy as np

app = Flask(__name__)
# La base de datos y el modelo se guardan siempre junto a este archivo, sin importar desde dónde se ejecute
CARPETA = os.path.dirname(os.path.abspath(__file__))
DB = os.path.join(CARPETA, "detecciones.db")
FORMATO = "%Y-%m-%d %H:%M:%S"
TIPOS_VALIDOS = {"obstaculo", "persona", "animal"}

# Clases de YOLO (dataset COCO) que contamos como animales
ANIMALES = {"bird", "cat", "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe"}
CONFIANZA_MINIMA = 0.5

# Pasado este tiempo sin fotos nuevas, el resultado de YOLO se considera viejo
SEGUNDOS_RESULTADO_VALIDO = 3

# Último estado de cada parte (se guarda en memoria)
estado_lentes = {"ultima_conexion": None, "bateria": None, "camara_ultima_foto": None}

modelo = None
# YOLO trabaja siempre en un mismo hilo, una foto a la vez. Si se usa desde un hilo nuevo por cada foto,
# va acumulando memoria y el servidor se cae después de unos minutos.
hilo_yolo = ThreadPoolExecutor(max_workers=1)
ultima_imagen = None  # foto más reciente de la cámara, con los recuadros de YOLO dibujados (JPEG)
# Último resultado de YOLO, para que el ESP32 principal lo consulte
ultimo_resultado = {"tipo": "nada", "hora": 0.0}


def obtener_modelo():
    # YOLO se carga una sola vez (tarda unos segundos)
    global modelo
    if modelo is None:
        from ultralytics import YOLO
        modelo = YOLO(os.path.join(CARPETA, "yolo11n.pt"))
    return modelo


def detectar(imagen):
    return obtener_modelo()(imagen, conf=CONFIANZA_MINIMA, verbose=False)[0]


def precargar_modelo():
    # Se carga YOLO al encender el servidor, así la primera foto de la cámara no espera ~30 segundos
    hilo_yolo.submit(detectar, np.zeros((240, 320, 3), np.uint8)).result()
    print("YOLO listo")


def ip_local():
    # IP de esta compu en la red Wi-Fi (la que va en credenciales.h). No envía nada por internet.
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
            s.connect(("8.8.8.8", 80))
            return s.getsockname()[0]
    except OSError:
        return "127.0.0.1"


def conectar():
    conn = sqlite3.connect(DB)
    conn.row_factory = sqlite3.Row
    return conn


def crear_tabla():
    with conectar() as conn:
        conn.execute("""
            CREATE TABLE IF NOT EXISTS detecciones (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                fecha_hora TEXT NOT NULL,
                distancia REAL,
                tipo TEXT
            )
        """)


def guardar_deteccion(distancia, tipo):
    fecha_hora = datetime.now().strftime(FORMATO)
    with conectar() as conn:
        conn.execute(
            "INSERT INTO detecciones (fecha_hora, distancia, tipo) VALUES (?, ?, ?)",
            (fecha_hora, distancia, tipo),
        )
    estado_lentes["ultima_conexion"] = fecha_hora


# Los lentes (ESP32) envían aquí cada detección
@app.route("/api/deteccion", methods=["POST"])
def registrar_deteccion():
    datos = request.get_json(silent=True)
    if not datos or "distancia" not in datos:
        return jsonify({"error": "Falta la distancia"}), 400

    # null = la cámara vio algo más lejos de lo que alcanza a medir el sensor
    distancia = datos["distancia"]
    if distancia is not None:
        try:
            distancia = float(distancia)
        except (TypeError, ValueError):
            return jsonify({"error": "La distancia debe ser un número o null"}), 400

    tipo = datos.get("tipo", "obstaculo")
    if tipo not in TIPOS_VALIDOS:
        return jsonify({"error": f"Tipo inválido. Usa: {', '.join(TIPOS_VALIDOS)}"}), 400

    guardar_deteccion(distancia, tipo)
    return jsonify({"ok": True}), 201


# La ESP32-CAM envía aquí cada foto y YOLO responde si hay persona, animal o nada.
# Si además se envía ?distancia=85 y se detecta algo, se guarda en la base de datos.
@app.route("/api/imagen", methods=["POST"])
def analizar_imagen():
    global ultima_imagen

    # Acepta la foto como archivo de formulario (campo "imagen") o como bytes JPEG directos (ESP32-CAM)
    archivo = request.files.get("imagen")
    datos = archivo.read() if archivo else request.get_data()
    if not datos:
        return jsonify({"error": "No llegó ninguna imagen"}), 400

    imagen = cv2.imdecode(np.frombuffer(datos, np.uint8), cv2.IMREAD_COLOR)
    if imagen is None:
        return jsonify({"error": "La imagen no es válida"}), 400

    resultado = hilo_yolo.submit(detectar, imagen).result()
    objetos = [resultado.names[int(clase)] for clase in resultado.boxes.cls]

    if "person" in objetos:
        tipo = "persona"
    elif any(objeto in ANIMALES for objeto in objetos):
        tipo = "animal"
    else:
        tipo = "nada"

    _, jpg = cv2.imencode(".jpg", resultado.plot())
    ultima_imagen = jpg.tobytes()
    ultimo_resultado["tipo"] = tipo
    ultimo_resultado["hora"] = time.time()
    estado_lentes["camara_ultima_foto"] = datetime.now().strftime(FORMATO)

    distancia = request.args.get("distancia", type=float)
    if tipo != "nada" and distancia is not None:
        guardar_deteccion(distancia, tipo)

    return jsonify({"tipo": tipo, "objetos": objetos})


# El ESP32 principal (sensor y buzzer) pregunta aquí qué vio YOLO hace poco.
# Responde, por ejemplo: {"persona": true, "animal": false, "tipo": "persona", "segundos": 0.8}
@app.route("/api/resultado")
def ver_resultado():
    if ultimo_resultado["hora"] == 0:
        segundos = -1  # todavía no ha llegado ninguna foto
        tipo = "nada"
    else:
        segundos = round(time.time() - ultimo_resultado["hora"], 1)
        tipo = ultimo_resultado["tipo"] if segundos <= SEGUNDOS_RESULTADO_VALIDO else "nada"
    return jsonify({
        "persona": tipo == "persona",
        "animal": tipo == "animal",
        "tipo": tipo,
        "segundos": segundos,
    })


# Última foto analizada, para verla en la página
@app.route("/api/ultima-imagen")
def ver_ultima_imagen():
    if ultima_imagen is None:
        return "", 204
    return Response(ultima_imagen, mimetype="image/jpeg")


# Consulta de detecciones, con filtros opcionales: ?tipo=persona&fecha=2026-10-21&hora=14&limite=50
# Con ?pagina=2&por_pagina=20 devuelve esa página y el total: {"detecciones": [...], "total": 87, "paginas": 5}
@app.route("/api/detecciones")
def listar_detecciones():
    tipo = request.args.get("tipo")
    fecha = request.args.get("fecha")
    hora = request.args.get("hora", type=int)
    pagina = request.args.get("pagina", type=int)

    filtro = " WHERE 1=1"
    parametros = []
    if tipo:
        filtro += " AND tipo = ?"
        parametros.append(tipo)
    if fecha:
        filtro += " AND fecha_hora LIKE ?"
        parametros.append(fecha + "%")
    if hora is not None:
        # fecha_hora es "AAAA-MM-DD HH:MM:SS": la hora son los caracteres 12 y 13
        filtro += " AND CAST(substr(fecha_hora, 12, 2) AS INTEGER) = ?"
        parametros.append(hora)

    with conectar() as conn:
        if pagina is None:
            limite = request.args.get("limite", 200, type=int)
            filas = conn.execute(
                "SELECT * FROM detecciones" + filtro + " ORDER BY id DESC LIMIT ?", parametros + [limite]
            ).fetchall()
            return jsonify([dict(f) for f in filas])

        por_pagina = max(1, request.args.get("por_pagina", 20, type=int))
        total = conn.execute("SELECT COUNT(*) FROM detecciones" + filtro, parametros).fetchone()[0]
        paginas = max(1, (total + por_pagina - 1) // por_pagina)
        pagina = min(max(1, pagina), paginas)
        filas = conn.execute(
            "SELECT * FROM detecciones" + filtro + " ORDER BY id DESC LIMIT ? OFFSET ?",
            parametros + [por_pagina, (pagina - 1) * por_pagina],
        ).fetchall()
    return jsonify({
        "detecciones": [dict(f) for f in filas],
        "total": total,
        "pagina": pagina,
        "paginas": paginas,
    })


# Los lentes avisan que siguen encendidos (y su batería); la página lo consulta
@app.route("/api/estado", methods=["GET", "POST"])
def estado():
    if request.method == "POST":
        datos = request.get_json(silent=True) or {}
        estado_lentes["ultima_conexion"] = datetime.now().strftime(FORMATO)
        if "bateria" in datos:
            estado_lentes["bateria"] = datos["bateria"]
        return jsonify({"ok": True})
    return jsonify(estado_lentes)


# Descarga todas las detecciones en CSV (útil para las pruebas)
@app.route("/api/exportar")
def exportar():
    with conectar() as conn:
        filas = conn.execute("SELECT * FROM detecciones ORDER BY id").fetchall()

    salida = io.StringIO()
    escritor = csv.writer(salida)
    escritor.writerow(["id", "fecha_hora", "distancia", "tipo"])
    escritor.writerows([tuple(f) for f in filas])
    return Response(
        salida.getvalue(),
        mimetype="text/csv",
        headers={"Content-Disposition": "attachment; filename=detecciones.csv"},
    )


# Página web (dashboard)
@app.route("/")
def inicio():
    return render_template("index.html")


if __name__ == "__main__":
    crear_tabla()
    threading.Thread(target=precargar_modelo, daemon=True).start()

    ip = ip_local()
    print("=" * 50)
    print(f"Página:            http://localhost:5000")
    print(f"IP para credenciales.h:  {ip}")
    print("=" * 50)

    # 0.0.0.0 permite que el ESP32 y el celular se conecten desde la misma red.
    # Sin modo debug para que YOLO no se cargue dos veces; si cambian el código, reinicien el servidor.
    app.run(host="0.0.0.0", port=5000, threaded=True)
