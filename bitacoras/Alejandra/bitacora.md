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

## Día 4 [22/10/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez
- Joan Eras

### Actividades realizadas

- Nos reunimos para seguir con el proyecto, esta vez enfocadas en la ESP32-CAM y en cómo enviar sus imágenes a un servidor.
- **Individual:** creé el servidor que usaríamos para recibir las imágenes de la cámara, y lo probamos enviándole imágenes para comprobar que funcionara.
- Trabajamos con la ESP32-CAM y el adaptador FT232RL, revisando las conexiones necesarias para programar la cámara desde Arduino IDE.
- Aprendimos que el pin IO0 se conecta a GND solo mientras se carga el código, y que después hay que desconectarlo para que la cámara funcione normalmente.
- Comprobamos que la ESP32-CAM tomaba fotografías, pero al enviarlas al servidor tuvimos problemas con la conexión a internet y no pudimos verlas.
- Mientras hacíamos las pruebas, Joan comenzó a trabajar en la parte escrita del proyecto.
- Como no logramos resolver el problema de conexión en la reunión, Dana probó la cámara en su casa con otra red, para saber si la falla era de la cámara o de la conexión.

### Avances

- El servidor quedó creado y comprobamos que recibía las imágenes de prueba.
- Programamos la ESP32-CAM con Arduino IDE y verificamos que tomaba fotografías.
- Identificamos que el problema probablemente estaba en la conexión a internet, ya que las imágenes de la cámara no llegaban al servidor.
- Joan comenzó el trabajo escrito del proyecto.
- Dana comprobó desde su casa, con otra red, que la cámara sí funcionaba.

### Dificultades encontradas

- La cámara tomaba las fotos, pero no lográbamos enviarlas y verlas en el servidor.
- Los problemas con la conexión a internet no nos dejaron comprobar el funcionamiento completo del sistema.
- Al principio no sabíamos si la falla estaba en el código de la cámara, en el servidor o en la red.

### Soluciones implementadas

- Probamos el servidor por separado, enviándole imágenes de prueba, para asegurarnos de que las recibía.
- Comprobamos desde Arduino IDE que la cámara tomaba fotos, aunque todavía no llegaran al servidor.
- Decidimos probar la cámara con otra red, y Dana hizo la prueba desde su casa.
- Con esa prueba confirmamos que la cámara funcionaba, lo que indicaba que el problema estaba en la red que usamos durante la reunión.

### Decisiones técnicas

- Decidimos usar un servidor para recibir las imágenes de la ESP32-CAM y luego usarlas para reconocer personas, animales y objetos.
- Mantuvimos el FT232RL como adaptador para programar la cámara desde Arduino IDE.
- Acordamos probar con distintas redes antes de seguir con la integración del sistema.
- Dejamos pendiente la prueba completa entre la cámara y el servidor hasta poder hacer nuevas pruebas.

### Pruebas efectuadas

- Enviamos imágenes de prueba al servidor y comprobamos que las recibía.
- Cargamos el código de la ESP32-CAM desde Arduino IDE y verificamos que tomaba fotografías.
- Intentamos enviar las fotos de la cámara al servidor, pero no llegaron por los problemas de conexión.
- Dana probó la cámara en su casa con otra red y comprobó que funcionaba. Esta prueba solo sirvió para verificar la cámara, porque desde ahí no tenía acceso al servidor.

### Aprendizajes obtenidos

- Aprendí cómo funciona la comunicación entre una cámara y un servidor para enviar imágenes.
- Comprendí mejor cómo programar la ESP32-CAM con el FT232RL y la importancia de conectar bien el pin IO0.
- Me di cuenta de que la conexión a internet puede afectar las pruebas, aunque los componentes estén funcionando bien.
- Aprendí que cuando algo falla conviene probar cada parte por separado para encontrar dónde está el problema.

### Próximos pasos

- Reunirnos de nuevo para probar la conexión entre la ESP32-CAM y el servidor.
- Comprobar si las imágenes llegan al servidor usando otra red.
- Empezar a trabajar con YOLO para reconocer personas, animales y objetos cuando el servidor ya reciba las imágenes.
- Seguir avanzando con el trabajo escrito y la integración de los componentes.

## Día 5 [23/10/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez
- Joan Eras

### Actividades realizadas

- Nos reunimos en la soda para seguir con el proyecto y hacer nuevas pruebas con la ESP32-CAM y el servidor.
- Como ya sabíamos que la cámara funcionaba y yo había dejado el servidor funcionando, retomamos las pruebas de comunicación y empezamos a trabajar con YOLO para reconocer personas, animales y objetos en las imágenes.
- Modificamos el código de la ESP32-CAM desde la computadora de Dana para mejorar la captura de imágenes y el envío al servidor.
- En las pruebas vimos que el reconocimiento todavía fallaba, porque a veces no identificaba bien lo que aparecía en la imagen.
- Acomodamos los componentes uno al lado del otro y tomamos sus medidas para calcular el espacio de una carcasa.
- **Individual:** con esas medidas comencé un diseño en 3D para organizar los componentes y tener una idea de cómo quedaría el prototipo.
- Al revisar el proyecto con el profesor Eddier, notamos que usar baterías sería más complicado de lo esperado, porque algunos componentes necesitan voltajes distintos.
- Con una sola batería habría que adaptar la alimentación, y con varias ocuparíamos más espacio, así que descartamos esa idea.
- Por eso también dejamos de lado el diseño en 3D y optamos por un montaje más sencillo, con una protoboard más pequeña y los componentes conectados a una fuente de alimentación externa.
- **Individual:** continué con las pruebas de YOLO para revisar los problemas de reconocimiento.

### Avances

- Retomamos las pruebas de la ESP32-CAM con el servidor después de los problemas anteriores.
- Ajustamos el código de la cámara desde la computadora de Dana.
- Empezamos a usar YOLO para reconocer personas, animales y objetos.
- Tomamos las medidas de los componentes y comencé un primer diseño en 3D, que después descartamos.
- Identificamos los problemas de alimentar el circuito con baterías y definimos una alternativa más sencilla.
- Decidimos usar una protoboard más pequeña para ocupar menos espacio y organizar mejor los componentes.

### Dificultades encontradas

- YOLO no siempre reconocía correctamente a las personas, animales y objetos.
- Tuvimos que revisar y modificar el código de la cámara para poder seguir con las pruebas.
- Alimentar todos los componentes con una sola batería era complicado, porque no todos necesitan el mismo voltaje.
- Usar más de una batería habría ocupado más espacio y complicado el montaje de los lentes.
- Después de tomar las medidas y empezar el diseño en 3D, tuvimos que descartarlo porque la distribución planeada ya no era la más conveniente.
- La protoboard grande ocupaba demasiado espacio para el montaje que queríamos.

### Soluciones implementadas

- Ajustamos el código de la ESP32-CAM y seguimos probando su comunicación con el servidor.
- Decidimos seguir probando YOLO para encontrar qué afectaba el reconocimiento.
- Continué las pruebas del sistema en casa para revisarlo con más calma.
- Después de analizar la alimentación, decidimos no usar baterías y mantener los componentes conectados a una fuente externa.
- Descartamos la carcasa en 3D y optamos por una estructura más sencilla con una protoboard pequeña.

### Decisiones técnicas

- Mantuvimos YOLO para reconocer personas, animales y objetos en las imágenes de la ESP32-CAM.
- Decidimos seguir ajustando el código de la cámara para mejorar su funcionamiento.
- Descartamos las baterías por las diferencias de voltaje entre los componentes y el espacio extra que ocuparían.
- Acordamos usar una fuente de alimentación externa.
- Decidimos no seguir con la carcasa en 3D y usar un montaje más sencillo.
- Elegimos una protoboard más pequeña, que todavía teníamos que conseguir, para facilitar el montaje de los lentes.

### Pruebas efectuadas

- Retomamos las pruebas de comunicación entre la ESP32-CAM y el servidor.
- Modificamos el código de la cámara y volvimos a probar su funcionamiento.
- Probamos el reconocimiento con YOLO y vimos que en algunos casos no identificaba bien a las personas, animales u objetos.
- Medimos los componentes y revisamos su distribución para el diseño inicial de la carcasa.
- Analizamos qué necesitaba cada componente para alimentarse y cuál era la opción más conveniente.

### Aprendizajes obtenidos

- Aprendí que el reconocimiento de imágenes no siempre funciona bien en las primeras pruebas y que hay que ajustarlo para mejorar los resultados.
- Comprendí que los componentes pueden necesitar voltajes distintos y que eso hay que tomarlo en cuenta al decidir cómo alimentarlos.
- Me di cuenta de que las baterías no siempre son la opción más sencilla cuando se trabaja con varios componentes.
- Aprendí que antes de diseñar una carcasa hay que tener definidas la alimentación y la distribución de los componentes, para no hacer diseños que después no se usen.
- Comprendí que simplificar el montaje facilita las conexiones y las pruebas.

### Próximos pasos

- Conseguir la protoboard pequeña para pasar los componentes y seguir con el montaje.
- Planear cómo acomodar los componentes y las conexiones en la nueva protoboard.
- Preparar un diseño físico más sencillo para los lentes, tomando en cuenta que seguirán conectados a una fuente externa.
- Seguir probando y ajustando YOLO para mejorar el reconocimiento.

## Día 6 [30/10/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Nos reunimos para seguir con el proyecto, ya que por fin teníamos la protoboard pequeña que estábamos esperando.
- Pasamos los componentes y las conexiones de la protoboard grande a la pequeña, como habíamos decidido en la reunión anterior para simplificar el montaje.
- Al terminar de acomodarlos, probamos de nuevo que todo siguiera funcionando después del cambio.
- Seguimos haciendo pruebas con YOLO, porque todavía había problemas para reconocer personas, animales y objetos.
- Decidimos colocar los componentes sobre unos lentes para tener una primera idea de cómo quedaría el proyecto.
- Hicimos un montaje provisional con los materiales que teníamos a mano y probamos los lentes para ver cómo funcionaban los componentes colocados sobre ellos.
- Revisamos cómo quedaban distribuidos los cables y los componentes, para identificar qué mejorar antes del montaje definitivo.

### Avances

- Pasamos los componentes a la protoboard pequeña, lo que redujo el espacio que ocupa el circuito.
- Hicimos el primer montaje físico de los lentes inteligentes.
- Comprobamos que los componentes siguieran funcionando después de cambiar la protoboard.
- Avanzamos con las pruebas de YOLO para mejorar el reconocimiento de personas, animales y objetos.
- Pudimos ver cómo quedaría aproximadamente el prototipo y qué hay que mejorar para el montaje final.
- Empezamos a aplicar la idea de una estructura más sencilla, sin la carcasa en 3D ni las baterías que habíamos considerado antes.

### Dificultades encontradas

- YOLO todavía tenía problemas para reconocer a las personas, animales y objetos, porque en algunas ocasiones no los detectaba.
- El montaje de los lentes fue improvisado, porque aún no teníamos una forma definitiva de sujetar y acomodar los componentes.
- Al pasar las conexiones a la protoboard pequeña tuvimos que cuidar más la distribución de los cables por el poco espacio.
- Aunque los componentes quedaron sobre los lentes, faltaba mejorar su organización y estabilidad.

### Soluciones implementadas

- Revisamos las conexiones después de pasar los componentes, para asegurarnos de que estuvieran bien colocados.
- Seguimos probando YOLO para identificar en qué situaciones fallaba el reconocimiento.
- Usamos los materiales que teníamos para hacer un montaje provisional sobre los lentes y comprobar cómo funcionaría el prototipo.
- Anotamos lo que había que mejorar en la distribución y sujeción de los componentes para el montaje definitivo.
- Mantuvimos la estructura sencilla con la protoboard pequeña, sin agregar elementos que ocuparan demasiado espacio.

### Decisiones técnicas

- Decidimos quedarnos con la protoboard pequeña para el montaje final, porque ocupa menos espacio y facilita organizar los componentes.
- Mantuvimos YOLO para reconocer personas, animales y objetos, aunque todavía necesita mejoras.
- Acordamos usar el montaje provisional como referencia para preparar una versión más ordenada y estable de los lentes.
- Seguimos trabajando con los componentes conectados a una fuente de alimentación externa, como habíamos definido.
- Mantuvimos la decisión de no usar baterías ni carcasa en 3D, porque el diseño sencillo se adapta mejor a lo que tenemos ahora.

### Pruebas efectuadas

- Probamos las conexiones de los componentes después de pasarlos a la protoboard pequeña.
- Hicimos nuevas pruebas con YOLO para revisar el reconocimiento de personas, animales y objetos.
- Colocamos los componentes sobre unos lentes y probamos cómo funcionaban en el montaje provisional.
- Revisamos la distribución de los componentes para definir qué cambiar antes del montaje final.

### Aprendizajes obtenidos

- Aprendí que al cambiar a una protoboard más pequeña hay que organizar mejor las conexiones y revisar que todo siga funcionando.
- Comprendí que no basta con que los componentes funcionen por separado: también hay que pensar en cómo acomodarlos físicamente.
- Me di cuenta de que el reconocimiento de imágenes necesita más pruebas y ajustes para dar mejores resultados.
- Aprendí que un montaje provisional ayuda a encontrar problemas que no se habían considerado antes de la versión final.
- Comprendí que un diseño más sencillo facilita el montaje y permite concentrarse en mejorar el funcionamiento del sistema.

### Próximos pasos

- Hacer un montaje de los lentes más ordenado, firme y definitivo.
- Buscar una mejor forma de acomodar y sujetar los componentes para que el prototipo quede estable.
- Seguir probando y ajustando YOLO para mejorar el reconocimiento de personas, animales y objetos.

## Día 7 [12/11/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Nos reunimos para comenzar el montaje definitivo de los lentes, tomando como referencia el montaje provisional de la reunión anterior.
- Acomodamos la protoboard pequeña, el sensor ultrasónico, el buzzer y la ESP32-CAM sobre los lentes, buscando que quedaran más firmes y ordenados.
- Revisamos las conexiones conforme íbamos colocando los componentes, para asegurarnos de que ninguna se soltara.
- **Individual:** hice el diagrama de conexiones del prototipo en Cirkit Designer, una página que sí tenía todos los componentes que necesitábamos.
- Al terminar la reunión, Shirley se llevó el prototipo a su casa.

### Avances

- Comenzamos el montaje definitivo de los lentes.
- Los componentes quedaron mejor distribuidos que en el montaje provisional.
- Terminé el diagrama completo de conexiones, con todos los componentes del prototipo.

### Dificultades encontradas

- Por el poco espacio, fue complicado acomodar todos los componentes y cables sin que se movieran.
- No alcanzamos a terminar el montaje en una sola reunión.
- En los programas que habíamos usado antes (Wokwi, Proteus y Tinkercad) no estaban todos los componentes, así que no podíamos hacer el diagrama completo.

### Soluciones implementadas

- Fuimos colocando los componentes uno por uno y revisando las conexiones después de cada cambio.
- Acordamos terminar el montaje en la siguiente reunión.
- Buscamos otra herramienta y encontramos Cirkit Designer, que sí tenía todos los componentes, y con ella hice el diagrama completo.

### Decisiones técnicas

- Mantuvimos la protoboard pequeña y la alimentación externa por USB, como habíamos definido antes.
- Colocamos el sensor y la cámara al frente de los lentes, para que detecten lo que está delante de la persona.
- Decidimos usar Cirkit Designer para el diagrama de conexiones, porque permite representar el circuito completo en un solo lugar.

### Pruebas efectuadas

- Revisamos que los componentes siguieran funcionando después de colocarlos sobre los lentes.
- Comparé el diagrama con las conexiones reales del prototipo para comprobar que coincidieran.

### Aprendizajes obtenidos

- Aprendí que en el montaje final hay que cuidar tanto el funcionamiento como la estabilidad de los componentes.
- Comprendí que mantener ordenados los cables facilita encontrar fallas.
- Me di cuenta de que vale la pena buscar otras herramientas cuando las que se usan no tienen todo lo necesario.

### Próximos pasos

- Terminar el montaje de los lentes.
- Agregar el diagrama de conexiones al artículo y al repositorio.
- Avanzar con el artículo.

## Día 8 [13/11/2026]

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Nos reunimos para terminar el montaje de los lentes que habíamos comenzado el día anterior.
- Probamos que el sensor, el buzzer y la cámara siguieran funcionando con el prototipo ya armado.
- Trabajamos un poco en el artículo del proyecto.
- **Individual:** me llevé el prototipo a mi casa y mejoré el montaje, acomodando mejor los componentes y los cables para que quedaran más firmes.

### Avances

- Terminamos de armar los lentes.
- Comprobamos que el prototipo funcionaba después del montaje.
- Avanzamos con el artículo.
- Mejoré la distribución y la estabilidad de los componentes.

### Dificultades encontradas

- Algunos componentes y cables todavía quedaban un poco sueltos después del montaje.
- La red de la universidad seguía dando problemas para probar la comunicación con el servidor.

### Soluciones implementadas

- Me llevé el prototipo a mi casa para revisar con más calma su distribución y reforzar lo que estaba suelto.

### Decisiones técnicas

- Mantuvimos la distribución general del montaje y dejamos solo ajustes de orden y estabilidad.

### Pruebas efectuadas

- Probamos el funcionamiento del sensor, el buzzer y la cámara con el prototipo armado.
- Después de mejorar el montaje en mi casa, revisé que las conexiones siguieran funcionando.

### Aprendizajes obtenidos

- Comprendí que después de armar el prototipo hay que volver a probar todo, porque al mover los componentes alguna conexión puede fallar.
- Aprendí que pequeños ajustes en la distribución hacen que el prototipo sea más estable y cómodo.

### Próximos pasos

- Terminar de mejorar el montaje.
- Probar el sistema completo con una red más estable.
- Seguir con el artículo.

## Día 9 [14/11/2026]

### Integrantes presentes

- Individual (en casa)

### Actividades realizadas

- **Individual:** trabajé en el artículo del proyecto, avanzando en las secciones pendientes y revisando las citas y referencias en formato IEEE.

### Avances

- Avancé en la redacción del artículo.

### Dificultades encontradas

- Encontrar fuentes académicas confiables que respaldaran cada parte del proyecto llevó más tiempo de lo esperado.

### Soluciones implementadas

- Busqué artículos en revistas y en Google Académico, y revisé que las citas fueran textuales y coincidieran con sus referencias.

### Decisiones técnicas

- No se tomaron decisiones técnicas, ya que el día se dedicó al artículo.

### Pruebas efectuadas

- No se realizaron pruebas del prototipo.

### Aprendizajes obtenidos

- Aprendí a citar en formato IEEE y a revisar que cada cita corresponda con su referencia al final del artículo.

### Próximos pasos

- Terminar el montaje de los lentes.
- Comprobar que todo el sistema funcione.
- Seguir con el artículo.

## Día 10 [15/11/2026]

### Integrantes presentes

- Individual (en casa)

### Actividades realizadas

- **Individual:** terminé el montaje de los lentes y comprobé que todos los componentes quedaran firmes y bien conectados.
- **Individual:** modifiqué los dos códigos de Arduino:
  - En el ESP32 ajusté los tiempos y las distancias del buzzer, para que pite más rápido según la cercanía y se silencie a los 2 segundos cuando el obstáculo está quieto.
  - En la ESP32-CAM reduje la pausa entre fotos, para que las imágenes lleguen al servidor casi en tiempo real.
- **Individual:** hice cambios en el servidor y la página: agregué la cámara en vivo, un botón para limpiar los datos antes de la presentación y una ventana de confirmación para no borrarlos por accidente.
- **Individual:** probé el sistema completo con la red de mi casa: sensor, buzzer, cámara, servidor y página.
- **Individual:** trabajé bastante en el artículo, avanzando en las secciones pendientes y revisando lo que faltaba corregir.

### Avances

- El montaje de los lentes quedó terminado.
- El sistema completo funcionó correctamente con una red estable.
- Las alertas del buzzer responden más rápido y molestan menos con obstáculos quietos.
- La página muestra la cámara casi en vivo y permite limpiar los datos de prueba.
- Avancé de forma importante en el artículo.

### Dificultades encontradas

- La red de la universidad no funciona bien para el proyecto: no deja que la cámara y los lentes se comuniquen con el servidor. Esta es la dificultad más grande que encontramos y nos preocupa, porque podría afectar la presentación.
- El buzzer tardaba en silenciarse y los pitidos eran lentos.
- Las imágenes de la cámara llegaban con mucho retraso a la página.

### Soluciones implementadas

- Hice las pruebas con la red de mi casa y confirmé que el prototipo funciona, el problema está en la red de la universidad.
- Ajusté los tiempos del buzzer en el código del ESP32.
- Reduje la pausa entre fotos en el código de la ESP32-CAM y agregué el video en vivo a la página.

### Decisiones técnicas

- Bajé a 2 segundos el tiempo para silenciar el buzzer y aceleré los pitidos en cada rango de distancia.
- Agregué el botón de limpiar datos con confirmación, para empezar la presentación con la página vacía sin perder datos por error.
- Decidí hacer las pruebas completas en una red estable mientras se busca una solución para la red de la universidad.

### Pruebas efectuadas

- Probé la conexión del ESP32 y la ESP32-CAM con el servidor.
- Comprobé que el buzzer respondiera según la distancia y se silenciara con obstáculos quietos.
- Verifiqué que la página mostrara las detecciones, la cámara en vivo y el estado de los lentes.
- Probé el botón de limpiar datos y su ventana de confirmación.

### Aprendizajes obtenidos

- Comprendí que muchas fallas no vienen del código ni de los componentes, sino de la red.
- Aprendí que los tiempos de las alertas influyen mucho en lo útil que resulta el prototipo para la persona.
- Me di cuenta de que probar cada parte por separado ayuda a encontrar rápido dónde está el problema.

### Próximos pasos

- Subir a GitHub la parte de los códigos que me corresponde.
- Terminar el artículo con los resultados, la discusión y las conclusiones.
