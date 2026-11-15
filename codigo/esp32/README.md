# ESP32 principal (sensor HC-SR04 y buzzer)

Código del ESP32 que detecta los obstáculos con el sensor ultrasónico, avisa con el buzzer y consulta al servidor si la cámara vio una persona o un animal.

## Conexiones

| Componente | Pin del ESP32 |
|---|---|
| Buzzer pasivo (+) | GPIO 18 |
| HC-SR04 TRIG | GPIO 13 |
| HC-SR04 ECHO | GPIO 21 |
| VIN y GND del ESP32 | Rieles + y − de la protoboard |
| VCC y GND del sensor, − del buzzer | Rieles + y − de la protoboard |

## Cómo cargarlo

1. Copiar `credenciales_ejemplo.h` con el nombre `credenciales.h` y poner el nombre y la clave del Wi-Fi y la IP de la laptop donde corre el servidor.
2. Abrir `lentes_principal/lentes_principal.ino` en Arduino IDE.
3. Elegir la placa **ESP32 Dev Module** y el puerto COM que aparece al conectar el ESP32 por USB.
4. Subir el código y abrir el Monitor Serial a 115200 baudios.

## Cómo funciona

- Mide la distancia 5 veces por segundo y filtra las lecturas para ignorar errores del sensor.
- Si hay algo a menos de 150 cm, el buzzer pita más rápido mientras más cerca está, en cuatro niveles.
- Una máquina de estados (sin obstáculo, alertando, estable) silencia la alerta si el obstáculo se queda quieto 2 segundos y la vuelve a activar si se acerca. A menos de 25 cm suena siempre.
- Cada segundo consulta al servidor qué vio la cámara; si es una persona o un animal, da dos pitidos (si ya está pitando por distancia, no los repite).
- La comunicación con el servidor corre en una tarea aparte, en el otro núcleo del ESP32, para que el sensor y el buzzer no se traben aunque el Wi-Fi esté lento o el servidor apagado.