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
from flask import Flask, request, jsonify, render_template, Response

app = Flask(__name__)

# Configuración
CARPETA = os.path.dirname(os.path.abspath(__file__))
DB = os.path.join(CARPETA, "detecciones.db")
FORMATO = "%Y-%m-%d %H:%M:%S"
TIPOS_VALIDOS = {"obstaculo", "persona", "animal"}

ANIMALES = {"bird", "cat", "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe"}
CONFIANZA_MINIMA = 0.5
TAMANO_YOLO = 416
SEGUNDOS_RESULTADO_VALIDO = 3

estado_lentes = {"ultima_conexion": None, "bateria": None, "camara_ultima_foto": None}

modelo = None
hilo_yolo = ThreadPoolExecutor(max_workers=1)
ultima_imagen = None
ultimo_resultado = {"tipo": "nada", "hora": 0.0}


# YOLO
def obtener_modelo():
    global modelo
    if modelo is None:
        from ultralytics import YOLO
        modelo = YOLO(os.path.join(CARPETA, "yolo11n.pt"))
    return modelo


def detectar(imagen):
    return obtener_modelo()(imagen, conf=CONFIANZA_MINIMA, imgsz=TAMANO_YOLO, verbose=False)[0]


def precargar_modelo():
    hilo_yolo.submit(detectar, np.zeros((240, 320, 3), np.uint8)).result()
    print("YOLO listo")


def ip_local():
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
            s.connect(("8.8.8.8", 80))
            return s.getsockname()[0]
    except OSError:
        return "127.0.0.1"


# Base de datos
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


# Recibe las detecciones del ESP32
@app.route("/api/deteccion", methods=["POST"])
def registrar_deteccion():
    datos = request.get_json(silent=True)
    if not datos or "distancia" not in datos:
        return jsonify({"error": "Falta la distancia"}), 400

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


# Recibe las fotos de la ESP32-CAM y las analiza con YOLO
@app.route("/api/imagen", methods=["POST"])
def analizar_imagen():
    global ultima_imagen

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


# El ESP32 consulta lo último que vio la cámara
@app.route("/api/resultado")
def ver_resultado():
    if ultimo_resultado["hora"] == 0:
        segundos = -1
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


# Video en vivo para la página
@app.route("/api/video")
def ver_video():
    def generar():
        enviada = None
        while True:
            foto = ultima_imagen
            if foto is not None and foto is not enviada:
                enviada = foto
                yield (b"--frame\r\nContent-Type: image/jpeg\r\nContent-Length: "
                       + str(len(foto)).encode() + b"\r\n\r\n" + foto + b"\r\n")
            time.sleep(0.03)

    return Response(generar(), mimetype="multipart/x-mixed-replace; boundary=frame")


@app.route("/api/ultima-imagen")
def ver_ultima_imagen():
    if ultima_imagen is None:
        return "", 204
    return Response(ultima_imagen, mimetype="image/jpeg")


# Historial de detecciones con filtros y páginas
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
        filtro += " AND CAST(substr(fecha_hora, 12, 2) AS INTEGER) = ?"
        parametros.append(hora)

    with conectar() as conn:
        if pagina is None:
            limite = request.args.get("limite", 200, type=int)
            filas = conn.execute(
                "SELECT * FROM detecciones" + filtro + " ORDER BY id DESC LIMIT ?",
                parametros + [limite],
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


# Borra todas las detecciones
@app.route("/api/detecciones", methods=["DELETE"])
def borrar_detecciones():
    with conectar() as conn:
        borradas = conn.execute("DELETE FROM detecciones").rowcount
        conn.execute("DELETE FROM sqlite_sequence WHERE name = 'detecciones'")
    return jsonify({"ok": True, "borradas": borradas})


# Estado de conexión de los lentes
@app.route("/api/estado", methods=["GET", "POST"])
def estado():
    if request.method == "POST":
        datos = request.get_json(silent=True) or {}
        estado_lentes["ultima_conexion"] = datetime.now().strftime(FORMATO)
        if "bateria" in datos:
            estado_lentes["bateria"] = datos["bateria"]
        return jsonify({"ok": True})
    return jsonify(estado_lentes)


# Exporta las detecciones a CSV
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


# Página principal
@app.route("/")
def inicio():
    return render_template("index.html")


if __name__ == "__main__":
    crear_tabla()
    threading.Thread(target=precargar_modelo, daemon=True).start()

    ip = ip_local()
    print("=" * 50)
    print("Página:            http://localhost:5000")
    print(f"IP para credenciales.h:  {ip}")
    print("=" * 50)

    app.run(host="0.0.0.0", port=5000, threaded=True)
