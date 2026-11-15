# Servidor local

Este es el servidor de los lentes. Está hecho en Python con Flask y corre en la laptop mientras se usan los lentes. Se encarga de tres cosas:

1. Recibir las fotos de la ESP32-CAM y pasarlas por YOLO para ver si hay una persona, un animal o un obstáculo.
2. Avisarle al ESP32 qué vio la cámara, para que el buzzer suene como corresponde.
3. Guardar cada detección (tipo, distancia, fecha y hora) en una base de datos SQLite y mostrarla en una página web.

## Qué se necesita

- Python 3.13.
- Que la laptop, la ESP32-CAM y el ESP32 estén en la misma red Wi-Fi.

## Cómo ejecutarlo

En la terminal, dentro de esta carpeta:

    python -m venv venv
    venv\Scripts\activate
    pip install -r requirements.txt
    python app.py

La primera vez tarda varios minutos porque se descarga YOLO. Después solo hay que activar el entorno virtual y correr `python app.py`.

Cuando arranca, el servidor muestra la IP de la laptop. Esa IP va en `SERVIDOR_IP`, dentro del `credenciales.h` del ESP32 y de la ESP32-CAM.

La página se abre en http://localhost:5000. Si Windows pide permiso en el firewall, hay que permitirlo en redes públicas y privadas; si no, la cámara no puede mandar las fotos.

El archivo `index.html` tiene que estar dentro de la carpeta `templates`, junto a `app.py`. La base de datos `detecciones.db` no hay que crearla: el servidor la crea solo la primera vez.

## Rutas del servidor

| Ruta | Para qué sirve |
|---|---|
| `POST /api/imagen` | Recibe la foto de la cámara y responde lo que vio YOLO |
| `GET /api/resultado` | Le dice al ESP32 qué vio la cámara en los últimos segundos |
| `POST /api/deteccion` | Guarda una detección que manda el ESP32, con su distancia |
| `GET /api/detecciones` | Muestra el historial, con filtros por tipo, día y hora, y por páginas |
| `DELETE /api/detecciones` | Borra todas las detecciones (botón "Limpiar datos") |
| `GET/POST /api/estado` | Guarda y muestra si los lentes y la cámara están conectados |
| `GET /api/video` | Muestra la cámara en vivo en la página |
| `GET /api/exportar` | Descarga las detecciones en un archivo CSV |
| `GET /` | La página con el resumen y el historial |
