# Código

En esta carpeta está el código de las tres partes de los lentes:

- **esp32:** el código del ESP32 que usa el sensor ultrasónico para medir la distancia y hace sonar el buzzer.
- **esp32cam:** el código de la cámara, que toma fotos y se las manda al servidor.
- **servidor:** el servidor en Python con Flask, donde YOLO revisa las fotos y donde está la página web con el historial.

Las tres partes se comunican por Wi-Fi, así que la laptop del servidor, el ESP32 y la cámara tienen que estar en la misma red. La cámara le manda las fotos al servidor, YOLO dice si hay una persona o un animal, y el ESP32 le pregunta al servidor qué vio la cámara para avisar con el buzzer.

Para que funcione, primero se enciende el servidor y después se carga el código en el ESP32 y en la cámara. En cada carpeta están las instrucciones.