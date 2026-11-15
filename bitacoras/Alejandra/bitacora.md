# Proyecto: LENTES INTELIGENTES ASISTIVOS

# Bitácora de: Alejandra Quintanilla Muñíz

## Día 1 [30/09/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Tuvimos la primera reunión del proyecto, donde cada una presentó las ideas que había pensado.
- Revisamos las propuestas según su utilidad, cuál nos interesaba más y cuál era posible desarrollar con nuestros recursos.
- Elegimos hacer unos lentes inteligentes para personas no videntes, que detecten los obstáculos en su camino y les avisen con alertas sonoras.
- Hicimos una primera lista de materiales: un ESP32, un sensor ultrasónico y un buzzer. La cámara quedó anotada como un posible complemento para más adelante.
- **Individual** investigué en internet ejemplos de lentes y otros dispositivos de asistencia para personas no videntes, para conocer cómo funcionaban y qué componentes utilizaban. Después compartí con el grupo los ejemplos más útiles como referencia para nuestro proyecto.

### Avances

- Quedó definido el tema del proyecto.
- Establecimos el propósito: que los lentes ayuden a la persona a identificar obstáculos cercanos y desplazarse con más seguridad.
- Tenemos una lista inicial de componentes.

### Dificultades encontradas

- Elegir una sola idea representó un reto, porque buscábamos un proyecto útil que también estuviera a nuestro alcance.
- Todavía no conocíamos bien los componentes ni cuáles eran los más adecuados.

### Soluciones implementadas

- Cada una dio su punto de vista y analizamos las ventajas y limitaciones de cada propuesta hasta llegar a un acuerdo.
- Buscamos información básica sobre los componentes y revisamos proyectos similares para decidir con más seguridad.

### Decisiones técnicas

- En la primera versión, los lentes usarían un sensor ultrasónico para detectar obstáculos y un buzzer para dar las alertas.
- El ESP32 se encargaría de controlar todo, y la cámara se dejó como una opción para ampliar el proyecto más adelante.

### Pruebas efectuadas

- No hicimos pruebas, porque la reunión se dedicó a definir la idea y organizar los materiales.

### Aprendizajes obtenidos

- Comprendí que escuchar todas las propuestas antes de decidir ayuda a llegar a una mejor idea.
- Aprendí que antes de armar un prototipo hay que investigar y entender para qué sirve cada componente.
- Revisar dispositivos similares me ayudó a tener una idea más clara de lo que podíamos lograr.


### Próximos pasos

- Investigar cómo funcionan el ESP32, el sensor ultrasónico y el buzzer.
- Identificar qué componentes faltan para las primeras pruebas.
- Revisar cómo se conectan y se programan.


## Día 2 [01/10/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Comenzamos a probar los componentes que elegimos para el proyecto.
- Probamos por separado el ESP32, el sensor ultrasónico HC-SR04 y el buzzer, para entender cómo funciona cada uno.
- Revisamos los pines y la alimentación de cada componente para saber cómo debíamos conectarlos.
- Empezamos los primeros diagramas del circuito en Wokwi, Proteus y Tinkercad, para visualizar cómo quedaría conectado el prototipo.
- Analizamos qué conexiones se necesitaban para que los componentes pudieran trabajar juntos más adelante.

### Avances

- Entendimos mejor el funcionamiento de los componentes principales.
- Realizamos las primeras pruebas y comenzamos a organizar las conexiones del circuito.
- Tenemos una primera versión de los diagramas, que nos servirá como guía para armar el prototipo físico.
- Identificamos los pines del ESP32 que íbamos a usar para conectar el sensor y el buzzer.

### Dificultades encontradas

- Al inicio se me hizo complicado identificar algunos pines y entender cómo conectar correctamente los componentes.
- Ningún programa de simulación tenía todos los componentes que necesitábamos.
- Todavía teníamos dudas sobre algunas conexiones para que los componentes funcionaran juntos.

### Soluciones implementadas

- Revisamos la información técnica de los componentes y los probamos uno por uno para comprender mejor sus conexiones.
- Dividimos las simulaciones entre varios programas: en Wokwi trabajamos el ESP32, el sensor ultrasónico y el buzzer, y en Proteus y Tinkercad revisamos la alimentación y otras conexiones del circuito.
- Usamos los diagramas como referencia para ubicar las conexiones que había que revisar en las siguientes pruebas.

### Decisiones técnicas

- Mantuvimos el ESP32 como controlador principal, el sensor HC-SR04 para detectar obstáculos y el buzzer para las alertas sonoras.
- Decidimos repartir las simulaciones entre distintos programas, ya que ninguno nos permitía representar todo el circuito.
- Tomamos los primeros diagramas como base para continuar con el montaje del prototipo.

### Pruebas efectuadas

- Probamos de forma individual el ESP32, el sensor ultrasónico y el buzzer.
- Revisamos las conexiones de los pines y la alimentación de los componentes.
- Hicimos las primeras simulaciones del circuito en Wokwi, Proteus y Tinkercad.

### Aprendizajes obtenidos

- Aprendí a identificar mejor los pines y las conexiones de los componentes electrónicos.
- Comprendí que es importante probar cada componente por separado antes de conectarlos todos.
- Aprendí a usar distintos programas de simulación y a buscar alternativas cuando una herramienta no tiene todo lo necesario.

### Próximos pasos

- Revisar y mejorar los primeros diagramas del circuito.
- Seguir probando cómo funcionan los componentes al trabajar juntos.
- Preparar las conexiones para comenzar a montar el prototipo físico.

## Día 3 [02/10/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Nos reunimos con el profesor Eddier López en la sala de profesores, y nos ayudó a conectar los componentes con los que veníamos trabajando.
- Con su ayuda conectamos el ESP32, el sensor ultrasónico HC-SR04 y el buzzer para probarlos juntos por primera vez.
- Usamos Arduino IDE para escribir y cargar el código que hacía funcionar los componentes.
- Probamos el circuito conectado para comprobar que funcionara y entender cómo se comunicaban los componentes entre sí.
- Conversamos sobre nuevas funciones para los lentes y decidimos agregar una ESP32-CAM, para que el proyecto no se quedara solo en detectar obstáculos con el sensor.
- Vimos que la cámara nos permitiría ampliar el proyecto con el reconocimiento de personas, animales y objetos.

### Avances

- Conectamos los componentes principales e hicimos las primeras pruebas desde Arduino IDE.
- Avanzamos en la programación del ESP32, el sensor y el buzzer.
- Entendimos mejor cómo debían conectarse los componentes para trabajar juntos.
- Ampliamos la idea inicial del proyecto al incorporar una cámara para el reconocimiento de personas, animales y objetos.

### Dificultades encontradas

- Se me hizo difícil entender cómo conectar todos los componentes y cómo escribir el código para que funcionaran correctamente.
- Al agregar la ESP32-CAM tuvimos que cambiar parte de lo planeado, porque los primeros diagramas no incluían este componente.
- Todavía no sabíamos cómo programar la cámara ni cómo integrarla con el resto del proyecto.

### Soluciones implementadas

- Con la ayuda del profesor revisamos las conexiones y fuimos haciendo pruebas en Arduino IDE para comprender cómo funcionaba cada componente.
- Conversamos sobre cómo incorporar la ESP32-CAM y ajustamos la idea del proyecto para incluir las nuevas funciones.
- Acordamos investigar primero el funcionamiento de la cámara antes de integrarla con los demás componentes.

### Decisiones técnicas

- Mantuvimos el ESP32, el sensor ultrasónico y el buzzer para detectar obstáculos y dar las alertas sonoras.
- Decidimos incorporar una ESP32-CAM para agregar el reconocimiento de personas, animales y objetos.
- Acordamos modificar los diagramas del circuito para incluir la cámara.

### Pruebas efectuadas

- Probamos las conexiones del ESP32 con el sensor ultrasónico y el buzzer.
- Escribimos y cargamos el código en Arduino IDE para comprobar que los componentes funcionaran conectados.
- Hicimos las primeras pruebas del circuito físico con la ayuda del profesor.

### Aprendizajes obtenidos

- Aprendí a conectar mejor los componentes y a usar Arduino IDE para programarlos y probarlos.
- Comprendí mejor cómo trabajan juntos el sensor ultrasónico, el ESP32 y el buzzer.
- Me di cuenta de que durante un proyecto pueden surgir ideas nuevas que hacen cambiar lo que se tenía planeado.

### Próximos pasos

- Investigar cómo funciona la ESP32-CAM y qué necesitamos para incorporarla.
- Actualizar los diagramas del circuito para incluir la cámara.
- Seguir con las pruebas y la programación de los componentes para avanzar con el prototipo.
