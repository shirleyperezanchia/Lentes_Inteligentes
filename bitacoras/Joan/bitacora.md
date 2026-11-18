# PROYECTO: PROTOTIPO LENTES INTELIGENTES ASISTIVOS

# Bitácora de: Joan Francisco Eras Cruz

## Día 4 [22/10/2026]

### Integrantes presentes
- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez
- Joan Eras

### Actividades realizadas
- Nos reunimos para seguir con el proyecto, esta vez enfocándonos en la ESP32-CAM y en cómo enviar sus imágenes a un servidor.
- Alejandra creó el servidor que usaríamos para recibir las imágenes de la cámara y lo probamos enviándole imágenes para comprobar que funcionara.
- Trabajamos con la ESP32-CAM y el adaptador FT232RL, revisando las conexiones necesarias para programar la cámara desde Arduino IDE.
- Aprendimos que el pin IO0 se conecta a GND solo mientras se carga el código; después hay que desconectarlo para que la cámara funcione normalmente.
- Comprobamos que la ESP32-CAM tomaba fotografías, pero tuvimos problemas con la conexión a internet y no logramos verlas en el servidor.
- Joan comenzó a trabajar en la parte escrita del proyecto mientras continuaban las pruebas de los componentes.
- Como no logramos resolver el problema de conexión durante la reunión, Dana probó la cámara en su casa con otra red.

### Avances
- El servidor quedó creado y comprobamos que recibía imágenes de prueba.
- Programamos la ESP32-CAM con Arduino IDE y verificamos que tomaba fotografías.
- Identificamos que el problema podía estar relacionado con la conexión a internet.
- Joan comenzó el trabajo escrito del proyecto.
- Dana comprobó desde su casa, con otra red, que la cámara funcionaba.

### Dificultades encontradas
- La cámara tomaba las fotos, pero no lográbamos enviarlas y verlas en el servidor.
- Los problemas con la conexión a internet no nos dejaron comprobar el funcionamiento completo del sistema.
- Al principio no sabíamos si la falla estaba en el código de la cámara, en el servidor o en la red.

### Soluciones implementadas
- Probamos el servidor por separado, enviándole imágenes de prueba, para asegurarnos de que las recibía.
- Comprobamos desde Arduino IDE que la cámara tomaba fotos, aunque todavía no llegaran al servidor.
- Decidimos probar la cámara con otra red, y Dana hizo la prueba desde su casa.
- Con esa prueba confirmamos que la cámara funcionaba, lo que indicó que el problema podía estar en la red utilizada durante la reunión.

### Decisiones técnicas
- Decidimos usar un servidor para recibir las imágenes de la ESP32-CAM y luego utilizarlas para reconocer personas, animales y objetos.
- Mantuvimos el FT232RL como adaptador para programar la cámara desde Arduino IDE.
- Acordamos probar con distintas redes antes de seguir con la integración del sistema.
- Dejamos pendiente la prueba completa entre la cámara y el servidor hasta poder hacer nuevas pruebas.

### Pruebas efectuadas
- Enviamos imágenes de prueba al servidor y comprobamos que las recibía.
- Cargamos el código de la ESP32-CAM desde Arduino IDE y verificamos que tomaba fotografías.
- Intentamos enviar las fotos de la cámara al servidor, pero no llegaron por los problemas de conexión.
- Dana probó la cámara en su casa con otra red y comprobó que funcionaba. Esa prueba permitió verificar la cámara, pero no la comunicación con el servidor.

### Aprendizajes obtenidos
- Aprendí cómo funciona la comunicación entre una cámara y un servidor para enviar imágenes.
- Comprendí mejor cómo programar la ESP32-CAM con el FT232RL y la importancia de conectar bien el pin IO0.
- Me di cuenta de que la conexión a internet puede afectar las pruebas, aunque los componentes estén funcionando bien.
- Aprendí que probar cada parte por separado ayuda a encontrar dónde está el problema.

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
- Como ya sabíamos que la cámara funcionaba y el servidor estaba listo, retomamos las pruebas de comunicación y empezamos a trabajar con YOLO para reconocer personas, animales y objetos en las imágenes.
- Modificamos el código de la ESP32-CAM desde la computadora de Dana para mejorar la captura de imágenes y el envío al servidor.
- En las pruebas vimos que el reconocimiento todavía fallaba, porque a veces no identificaba bien lo que aparecía en la imagen.
- Acomodamos los componentes uno al lado del otro y tomamos sus medidas para calcular el espacio que ocuparía una carcasa.
- Con esas medidas, Alejandra comenzó un diseño en 3D para organizar los componentes y tener una idea de cómo quedaría el prototipo.
- Al revisar el proyecto con el profesor Eddier, notamos que usar baterías sería más complicado de lo esperado porque algunos componentes necesitan voltajes distintos.
- Analizamos la posibilidad de usar una o varias baterías, pero esto implicaba adaptar la alimentación y ocupar más espacio.
- Finalmente, descartamos las baterías y el diseño de la carcasa en 3D. Optamos por un montaje más sencillo, con una protoboard más pequeña y los componentes conectados a una fuente de alimentación externa.
- Al terminar la reunión, Alejandra se llevó los componentes a su casa para continuar las pruebas de YOLO y revisar los problemas de reconocimiento.

### Avances
- Retomamos las pruebas de la ESP32-CAM con el servidor después de los problemas anteriores.
- Ajustamos el código de la cámara y empezamos a usar YOLO para reconocer personas, animales y objetos.
- Tomamos las medidas de los componentes y comenzamos un primer diseño en 3D, que luego descartamos.
- Identificamos los problemas de alimentar el circuito con baterías y definimos una alternativa más sencilla.
- Decidimos usar una protoboard más pequeña para ocupar menos espacio y organizar mejor los componentes.

### Dificultades encontradas
- YOLO no siempre reconocía correctamente a las personas, animales y objetos.
- Tuvimos que revisar y modificar el código de la cámara para poder seguir con las pruebas.
- Alimentar todos los componentes con una sola batería era complicado, porque no todos necesitan el mismo voltaje.
- Usar más de una batería habría ocupado más espacio y complicado el montaje de los lentes.
- Después de tomar las medidas y empezar el diseño en 3D, tuvimos que descartarlo porque la distribución planeada ya no era conveniente.
- La protoboard grande ocupaba demasiado espacio para el montaje que queríamos.

### Soluciones implementadas
- Ajustamos el código de la ESP32-CAM y seguimos probando su comunicación con el servidor.
- Decidimos seguir probando YOLO para identificar qué afectaba el reconocimiento.
- Después de analizar la alimentación, decidimos no usar baterías y mantener los componentes conectados a una fuente externa.
- Descartamos la carcasa en 3D y optamos por una estructura más sencilla con una protoboard pequeña.

### Decisiones técnicas
- Mantuvimos YOLO para reconocer personas, animales y objetos en las imágenes de la ESP32-CAM.
- Decidimos seguir ajustando el código de la cámara para mejorar su funcionamiento.
- Descartamos las baterías por las diferencias de voltaje entre los componentes y el espacio extra que ocuparían.
- Acordamos usar una fuente de alimentación externa.
- Decidimos no seguir con la carcasa en 3D y usar un montaje más sencillo.
- Elegimos una protoboard más pequeña para facilitar el montaje de los lentes.

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
- Aprendí que antes de diseñar una carcasa hay que tener definidas la alimentación y la distribución de los componentes.
- Comprendí que simplificar el montaje facilita las conexiones y las pruebas.

### Próximos pasos
- Conseguir la protoboard pequeña para pasar los componentes y seguir con el montaje.
- Planear cómo acomodar los componentes y las conexiones en la nueva protoboard.
- Preparar un diseño físico más sencillo para los lentes, tomando en cuenta que seguirán conectados a una fuente externa.
- Seguir probando y ajustando YOLO para mejorar el reconocimiento.

## Día 11 [17/11/2026]

### Integrantes presentes
- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez
- Joan Eras

### Actividades realizadas
- Realizamos las pruebas finales del prototipo en distintos espacios del campus, probando el reconocimiento de YOLO con personas, objetos y figuras de animales.
- Como la red de la universidad no permitía que los dispositivos se comunicaran entre sí, compartimos internet desde la laptop para conectar la ESP32-CAM, el ESP32 y el servidor.
- Recopilamos los resultados de las pruebas y los registros guardados en la base de datos.
- Avanzamos en el artículo agregando los resultados de las pruebas.
- Joan midió el sensor y el buzzer, comparando la distancia real con la que registraba el ESP32, y ajustó el código para que la alerta volviera a sonar cuando un obstáculo se acerca o se aleja.
- Dejamos lista la presentación del proyecto.

### Avances
- Se completaron las pruebas finales del prototipo.
- Avanzamos en el artículo con los resultados de las pruebas.
- Se completó la tabla de pruebas del sensor y del buzzer con mediciones reales.
- La alerta del buzzer ahora reacciona mejor a los cambios de distancia.
- La presentación del proyecto quedó lista.

### Dificultades encontradas
- La red de la universidad seguía impidiendo la comunicación entre los dispositivos.
- Durante las mediciones, el sensor detectaba primero otros objetos cercanos, lo que afectaba algunas lecturas.
- La alerta solo volvía a sonar cuando el obstáculo se acercaba, por lo que algunos cambios de distancia no se notaban.
- El puerto USB del ESP32 se trababa en ocasiones y no dejaba cargar el código ni abrir el Monitor Serial.

### Soluciones implementadas
- Creamos una red propia compartiendo internet desde la laptop.
- Hicimos las mediciones apuntando el sensor hacia un espacio libre para evitar que detectara otros objetos.
- Se ajustó el código para que un cambio de distancia mayor a 15 cm volviera a activar la alerta, tanto al acercarse como al alejarse el obstáculo.
- Desconectamos y volvimos a conectar el USB para destrabar el puerto.

### Decisiones técnicas
- Usar la red compartida desde la laptop para las pruebas y la presentación.
- Bajar el margen de movimiento a 15 cm y reactivar la alerta tanto al acercarse como al alejarse.
- Registrar en la tabla del sensor el valor más frecuente y el rango observado, porque las lecturas variaban algunos centímetros.

### Pruebas efectuadas
- Probamos el reconocimiento con YOLO en distintos espacios de la universidad.
- Medimos el sensor a 10, 20, 30, 50 y 100 cm, observando también el comportamiento del buzzer.
- Probamos el comportamiento de las alertas con obstáculos quietos, en movimiento y sin conexión Wi-Fi.

### Aprendizajes obtenidos
- Aprendí a documentar las pruebas con datos reales, aunque las lecturas no fueran idénticas.
- Comprendí que el sensor ultrasónico detecta primero el objeto más cercano y que eso influye en cómo hay que hacer las mediciones.
- Aprendí que probar cada parte por separado ayuda a encontrar más rápido dónde está el problema.

### Próximos pasos
- Montar el stand para presentar el proyecto final.
