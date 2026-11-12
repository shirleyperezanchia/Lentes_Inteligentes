# Servidor local

Servidor desarrollado en Python con Flask, que se ejecuta en la laptop durante el uso de los lentes. Sus funciones principales son:

1. Recibir las imágenes enviadas por la ESP32-CAM y analizarlas con el modelo YOLO para identificar si corresponden a una persona, un animal o un obstáculo.
2. Informar al ESP32 el resultado del análisis, para que el buzzer genere la alerta correspondiente.
3. Almacenar cada detección (tipo, distancia, fecha y hora) en una base de datos SQLite y presentarla en una página web.

## Requisitos

- Python 3.13.
- La laptop, la ESP32-CAM y el ESP32 deben estar conectados a la misma red Wi-Fi.

## Ejecución

Desde esta carpeta, ejecutar en la terminal:

    python -m venv venv
    venv\Scripts\activate
    pip install -r requirements.txt
    python app.py

La primera instalación puede tardar varios minutos, ya que incluye la descarga de YOLO. En las siguientes ejecuciones solo es necesario activar el entorno virtual y ejecutar `python app.py`.

Al iniciar, el servidor muestra la dirección IP de la laptop. Esta dirección debe colocarse en `SERVIDOR_IP` dentro de los archivos `credenciales.h` del ESP32 y de la ESP32-CAM.

La página web está disponible en http://localhost:5000. Si Windows solicita permiso en el firewall, se debe permitir el acceso en redes públicas y privadas para que la cámara pueda enviar las imágenes.

## Rutas del servidor

| Ruta | Descripción |
|---|---|
| `POST /api/imagen` | Recibe la imagen de la cámara y devuelve el resultado de YOLO |
| `GET /api/resultado` | Indica al ESP32 lo detectado por la cámara en los últimos segundos |
| `POST /api/deteccion` | Registra una detección enviada por el ESP32 con su distancia |
| `GET /api/detecciones` | Consulta el historial, con filtros por tipo, día y hora, y paginación |
| `GET/POST /api/estado` | Registra y consulta el estado de conexión de los lentes y la cámara |
| `GET /api/exportar` | Descarga todas las detecciones en formato CSV |
| `GET /` | Página web con el resumen y el historial de detecciones |
