# Documentación del proyecto


1. Descripción del proyecto

Este proyecto consiste en el desarrollo de un prototipo de lentes inteligentes diseñado para apoyar a personas con discapacidad visual en la identificación de obstáculos y el reconocimiento de su entorno, el sistema utiliza un microcontrolador ESP32 conectado a un sensor ultrasónico HC-SR04, encargado de medir la distancia de los obstáculos, y un buzzer que emite alertas sonoras según su cercanía.
Además, incorpora una ESP32-CAM que captura imágenes del entorno y permite procesarlas mediante el modelo de inteligencia artificial YOLO para reconocer personas, animales y objetos.
El proyecto también cuenta con un servidor desarrollado en Python utilizando Flask, una base de datos SQLite y una página web para consultar los registros de detecciones.
El prototipo fue desarrollado como parte del Proyecto Integrador del curso Paradigmas de Programación de la Universidad Nacional de Costa Rica, aplicando conocimientos de programación e integración de sistemas.

## 2. Componentes y tecnologías utilizadas

Para desarrollar el prototipo utilizamos los siguientes componentes electrónicos y herramientas de software.

### Componentes electrónicos

Componente - Función 
ESP32 DevKit: Controla el sensor ultrasónico y las alertas sonoras. 
ESP32-CAM: Captura imágenes del entorno para su reconocimiento. 
Sensor HC-SR04: Mide la distancia entre los lentes y los obstáculos. 
Buzzer: Emite sonidos de alerta cuando detecta obstáculos cercanos. 
Adaptador FT232RL: Permite programar la ESP32-CAM desde la computadora. 
Protoboard: Facilita las conexiones entre los componentes electrónicos. 
Cables jumper: Conectan los diferentes dispositivos del circuito. 

### Tecnologías y herramientas

Tecnología de uso en el proyecto 
Arduino IDE: Programación del ESP32 y la ESP32-CAM. 
C/C++: Desarrollo del código de los microcontroladores. 
Python: Procesamiento de imágenes e integración del sistema. 
YOLO: Reconocimiento de personas, animales y objetos. 
Flask: Desarrollo del servidor web. 
SQLite: Almacenamiento de registros de detecciones.
HTML, CSS y JavaScript: Desarrollo de la interfaz web. 
GitHub: Almacenamiento del código, documentación y evidencias. 
Cirkit Designer:	Elaboración del diagrama de conexiones de los componentes electrónicos del prototipo.
draw.io: Diseño del diagrama de arquitectura y representación del funcionamiento general del sistema.


## 3. Arquitectura y funcionamiento del sistema

El prototipo de lentes inteligentes está compuesto por dos partes principales: un sistema de detección de obstáculos y un sistema de reconocimiento de imágenes.

### Detección de obstáculos

El ESP32 DevKit recibe las mediciones del sensor ultrasónico HC-SR04, que calcula la distancia entre el usuario y los obstáculos cercanos. Según la distancia detectada, el ESP32 controla el buzzer para emitir alertas sonoras que advierten sobre la proximidad de un objeto.

### Reconocimiento de imágenes

La ESP32-CAM se encarga de capturar imágenes del entorno. Estas pueden enviarse mediante una conexión Wi-Fi al servidor desarrollado en Python con Flask, donde se utiliza YOLO para reconocer personas, animales y objetos.
El sistema también incorpora una base de datos SQLite y una interfaz web para gestionar y consultar los registros de detecciones.

### Diagramas del sistema

Para representar el funcionamiento y las conexiones del prototipo se elaboraron dos diagramas:

- Diagrama de arquitectura (draw\.io): muestra los componentes principales del sistema y cómo se comunican entre sí.
- Diagrama de conexiones (Cirkit Designer): representa las conexiones electrónicas del ESP32, ESP32-CAM, sensor ultrasónico, buzzer y demás componentes.

## 4. Implementación y paradigmas de programación

Para el desarrollo del prototipo se aplicaron tres paradigmas de programación: orientado a eventos, concurrente y cliente-servidor. Cada uno cumple una función diferente dentro del sistema y permite organizar las tareas de detección, alerta y comunicación entre los dispositivos.

### Programación orientada a eventos

Se implementó mediante una máquina de estados que controla el comportamiento del sistema según las mediciones del sensor ultrasónico HC-SR04.

El programa contempla tres estados: sin obstáculo, alertando y estable. Cuando se detecta un obstáculo dentro de los 150 cm, el buzzer emite pitidos cuyo ritmo aumenta conforme disminuye la distancia.

Si el obstáculo permanece estable durante dos segundos, la alerta se silencia para evitar sonidos innecesarios. Sin embargo, cuando la distancia es inferior a 25 cm, el buzzer continúa emitiendo pitidos.

También se utilizan filtros de mediana y lecturas consecutivas para reducir errores de medición y evitar alertas provocadas por variaciones aisladas.

### Programación concurrente

Se aprovecharon los dos núcleos del ESP32 principal para distribuir las tareas del sistema.

- **Núcleo 0:** gestiona la comunicación con el servidor, las consultas HTTP, el envío de detecciones y la actualización del estado de conexión.
- **Núcleo 1:** realiza las mediciones del sensor ultrasónico, el filtrado de datos, los cambios de estado y el control del buzzer.

Para comunicar ambas tareas se utiliza una cola de detecciones con capacidad para diez registros y una variable compartida que almacena el resultado del reconocimiento de imágenes.

Esta distribución permite que las mediciones y las alertas sonoras continúen funcionando aunque la conexión Wi-Fi presente dificultades o el servidor no esté disponible.

### Arquitectura cliente-servidor

La comunicación entre los dispositivos se realiza mediante una API desarrollada con Flask y utilizando el protocolo HTTP.

La ESP32-CAM actúa como cliente al capturar y enviar fotografías en formato JPEG al servidor, donde se procesan mediante YOLO. El ESP32 principal consulta los resultados del reconocimiento, envía las detecciones junto con las distancias medidas e informa periódicamente sobre su estado de conexión.

Por su parte, el servidor gestiona la información y utiliza SQLite para almacenar los registros de detecciones. Estos pueden consultarse desde la interfaz web, que permite visualizar el historial, aplicar filtros, comprobar el estado de los dispositivos y exportar los datos en formato CSV.

La integración de estos tres paradigmas permite distribuir las responsabilidades del sistema y mantener la detección de obstáculos de manera independiente del procesamiento de imágenes.

## 5. Instalación y ejecución del proyecto

Para ejecutar el prototipo de lentes inteligentes se necesitan los componentes electrónicos conectados de extremo a extremo por medio de jumpers, una computadora para ejecutar el servidor y una conexión de red local que permita la comunicación entre los dispositivos.

### Requisitos

- ESP32 DevKit, ESP32-CAM, sensor HC-SR04 y buzzer correctamente conectados.
- Arduino IDE para cargar los programas de los microcontroladores.
- Python y las bibliotecas necesarias para ejecutar el servidor Flask y el modelo YOLO.
- Una computadora que funcione como servidor.
- Una red Wi-Fi que permita la comunicación entre la ESP32-CAM y el servidor.

### Procedimiento general

1. Verificar las conexiones de los componentes electrónicos.
2. Cargar los programas correspondientes al ESP32 DevKit y a la ESP32-CAM mediante Arduino IDE.
3. Configurar la conexión Wi-Fi y la dirección del servidor.
4. Iniciar el servidor desarrollado con Flask en la computadora.
5. Encender los dispositivos y comprobar su comunicación con el servidor.
6. Realizar pruebas de detección de obstáculos, alertas sonoras y reconocimiento de imágenes.
7. Consultar los registros disponibles desde la interfaz web.

