# PROYECTO: PROTOTIPO LENTES INTELIGENTES ASISTIVOS

# Bitácora de: Shirley Pérez Anchia
#DÍA 1 – 30 DE SEPTIEMBRE DE 2026

###Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Este día nos reunimos las tres para conversar sobre las ideas que teníamos para desarrollar nuestro proyecto de Paradigmas de Programación.
- Cada una compartió sus propuestas y estuvimos analizando cuál podría ser más útil y, al mismo tiempo, posible de realizar con los recursos y conocimientos que teníamos.
- Después de discutir las diferentes opciones, elegimos desarrollar unos lentes inteligentes dirigidos a personas con discapacidad visual, con el propósito de ayudarles a detectar obstáculos cercanos mediante alertas sonoras.
- También comenzamos a investigar qué materiales electrónicos necesitaríamos para construir el prototipo. Entre los primeros componentes que consideramos estaban el ESP32, el sensor ultrasónico HC-SR04 y un buzzer.
- Además, hablamos sobre la posibilidad de incorporar una cámara más adelante, aunque todavía no teníamos definido cómo la utilizaríamos.

### Avances

- Logramos ponernos de acuerdo sobre la idea principal del proyecto.
- Definimos que nuestro prototipo estaría orientado a apoyar a personas con discapacidad visual mediante la detección de obstáculos.
- Elaboramos una primera lista de materiales que nos serviría como referencia para comenzar a trabajar.
- Establecimos una idea inicial de cómo podría funcionar el sistema utilizando un sensor y alertas sonoras.

### Dificultades encontradas

- Al inicio nos costó decidir cuál de las ideas desarrollar, porque queríamos realizar algo que tuviera una utilidad real, pero que también estuviera dentro de nuestras posibilidades.
- No teníamos mucho conocimiento sobre algunos de los componentes electrónicos que podríamos necesitar, por lo que todavía había dudas sobre cuáles serían los más adecuados.
- También debíamos considerar qué tan complicado podría ser integrar la programación con los componentes físicos.

### Soluciones implementadas

- Conversamos entre las tres sobre las ventajas y dificultades de cada propuesta hasta llegar a una decisión con la que todas estuvimos de acuerdo.
- Comenzamos a buscar información sobre los componentes electrónicos y sus funciones para comprender mejor cómo podríamos utilizarlos.
- Decidimos iniciar con una propuesta sencilla y considerar nuevas funciones conforme avanzáramos con las pruebas.

### Decisiones técnicas

- Elegimos utilizar un ESP32 como controlador principal del prototipo.
- Consideramos el sensor ultrasónico HC-SR04 para medir la distancia de los obstáculos y un buzzer para emitir las alertas sonoras.
- Acordamos que, inicialmente, el sistema avisaría cuando hubiera un obstáculo cerca de la persona.
- Dejamos abierta la posibilidad de incorporar una cámara para ampliar las funciones del proyecto en una etapa posterior.

### Pruebas efectuadas

- Durante este primer día no realizamos pruebas físicas ni de programación, ya que nos concentramos en seleccionar la idea, investigar los materiales y definir cómo queríamos desarrollar el proyecto.

### Aprendizajes obtenidos

- Comprendí que antes de comenzar a programar o conectar componentes es importante tener claro qué problema queremos resolver y cómo podría funcionar nuestra solución.
- También aprendí que escuchar las propuestas de mis compañeras nos permite analizar diferentes posibilidades y tomar mejores decisiones.
- Esta primera reunión me ayudó a conocer algunos de los componentes que podríamos utilizar y a comprender que necesitaríamos investigar su funcionamiento antes de comenzar con las conexiones.

### Próximos pasos

- Investigar con mayor detalle el funcionamiento del ESP32, el sensor ultrasónico y el buzzer.
- Revisar cuáles materiales necesitaríamos conseguir para realizar las primeras pruebas.
- Comenzar a conocer los pines y las conexiones de los componentes.
- Organizar las primeras pruebas para comprobar si los dispositivos funcionan correctamente.





## DÍA 2 – 1 DE OCTUBRE DE 2026


### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Este día nos reunimos nuevamente las tres para comenzar a conocer mejor los componentes que habíamos seleccionado para nuestro proyecto.
- Estuvimos realizando las primeras pruebas por separado con el ESP32, el sensor ultrasónico HC-SR04 y el buzzer, para comprender cómo funcionaba cada uno antes de conectarlos todos.
- Revisamos los pines de los componentes, especialmente los que se utilizan para la alimentación y para enviar o recibir señales.
- También comenzamos a trabajar en los primeros diagramas del circuito utilizando herramientas como Wokwi, Proteus y Tinkercad, con la intención de visualizar cómo podríamos organizar las conexiones.
- Mientras realizábamos estas actividades, fuimos conversando sobre las conexiones que necesitaríamos para que el sensor pudiera detectar obstáculos y el buzzer emitiera las alertas.

### Avances

- Conseguimos familiarizarnos mejor con los componentes electrónicos que utilizaríamos.
- Realizamos las primeras comprobaciones de funcionamiento del ESP32, el sensor ultrasónico y el buzzer.
- Comenzamos a identificar los pines que necesitaríamos para conectar los dispositivos.
- Elaboramos los primeros diagramas que nos servirían como referencia para el montaje físico.
- Logramos tener una idea más clara de cómo se relacionarían los componentes dentro del prototipo.

### Dificultades encontradas

- Al principio nos confundimos con algunos pines, porque todavía no conocíamos bien sus funciones ni cómo debíamos conectarlos.
- También tuvimos dificultades al utilizar los programas de simulación, ya que no todos incluían los componentes que necesitábamos.
- Nos costó encontrar una herramienta donde pudiéramos representar todo el circuito de la manera que queríamos.
- Todavía teníamos dudas sobre cómo organizar la alimentación y las conexiones entre los dispositivos.

### Soluciones implementadas

- Fuimos revisando la información de los componentes y comparando sus pines para comprender mejor cómo debían conectarse.
- Realizamos las pruebas por separado para identificar con mayor facilidad cualquier problema.
- En lugar de depender de un solo programa, decidimos utilizar distintas herramientas para trabajar las partes del circuito.
- Utilizamos Wokwi para representar el ESP32, el sensor ultrasónico y el buzzer, mientras que Proteus y Tinkercad nos ayudaron a revisar otras conexiones y aspectos de la alimentación.

### Decisiones técnicas

- Mantuvimos el ESP32 como controlador principal, ya que sería el encargado de recibir la información del sensor y controlar las alertas sonoras.
- Confirmamos que utilizaríamos el HC-SR04 para medir la distancia de los obstáculos y el buzzer para avisar cuando estuvieran cerca.
- Decidimos trabajar con diferentes programas de simulación porque no encontramos uno que incluyera todos los componentes que necesitábamos.
- Acordamos utilizar los diagramas como guía para realizar posteriormente las conexiones físicas.

### Pruebas efectuadas

- Realizamos pruebas iniciales con el ESP32 para familiarizarnos con su funcionamiento.
- Probamos por separado el sensor ultrasónico HC-SR04 y el buzzer.
- Revisamos las conexiones de alimentación y los pines que utilizaríamos.
- Comenzamos a probar los diagramas y las conexiones mediante Wokwi, Proteus y Tinkercad.
- Identificamos aspectos que todavía necesitábamos revisar antes de conectar todos los componentes.

### Aprendizajes obtenidos

- Aprendí a reconocer mejor los pines del ESP32 y a comprender la importancia de identificar correctamente las conexiones antes de realizarlas.
- Comprendí mejor cómo funciona el sensor ultrasónico y de qué manera podríamos utilizarlo para detectar obstáculos.
- También conocí mejor el funcionamiento del buzzer y su utilidad para generar alertas sonoras.
- Me di cuenta de que no siempre encontraremos todos los componentes en un mismo programa de simulación y que es necesario buscar alternativas.
- Esta experiencia me ayudó a comprender por qué es importante probar los componentes individualmente antes de integrarlos en un circuito completo.

### Próximos pasos

- Continuar revisando y mejorando los diagramas del circuito.
- Realizar nuevas pruebas para comprender cómo pueden trabajar juntos el ESP32, el sensor y el buzzer.
- Preparar las conexiones necesarias para comenzar el montaje físico del prototipo.
- Consultar las dudas que todavía teníamos sobre la programación y las conexiones de los componentes.




## DÍA 3 – 2 DE OCTUBRE DE 2026

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Este día nos reunimos las tres con el profesor Eddier López en la sala de profesores para continuar trabajando en las conexiones de nuestro proyecto.
- Con la orientación del profesor, estuvimos conectando el ESP32, el sensor ultrasónico HC-SR04 y el buzzer, para comprobar cómo funcionaban juntos.
- Utilizamos Arduino IDE para escribir y cargar los códigos que necesitábamos para realizar las pruebas con los componentes.
- Durante la reunión fuimos revisando las conexiones y haciendo pruebas para entender mejor cómo el ESP32 recibía la información del sensor y activaba el buzzer.
- También conversamos con el profesor sobre cómo podríamos mejorar nuestra propuesta, ya que hasta ese momento los lentes estaban pensados principalmente para detectar obstáculos cercanos.
- A partir de esa conversación, decidimos agregar una ESP32-CAM para ampliar las funciones del proyecto y trabajar posteriormente en el reconocimiento de personas, animales y objetos.

### Avances

- Logramos conectar el ESP32, el sensor ultrasónico y el buzzer para realizar las primeras pruebas en conjunto.
- Conseguimos cargar y ejecutar los códigos desde Arduino IDE.
- Comprendimos mejor cómo se relacionan los componentes y cómo deben conectarse para funcionar correctamente.
- Decidimos ampliar la propuesta inicial incorporando una cámara, con la intención de que los lentes pudieran brindar más información sobre el entorno.

### Dificultades encontradas

- Al principio todavía teníamos algunas dudas sobre las conexiones de los componentes y cómo debíamos programarlos para que trabajaran juntos.
- Nos costó comprender algunas partes del código y relacionarlas con el funcionamiento físico del sensor y del buzzer.
- Al decidir incorporar la ESP32-CAM, nos dimos cuenta de que tendríamos que modificar los diagramas que habíamos comenzado a elaborar.
- También necesitábamos investigar cómo funcionaba la cámara y qué componentes adicionales serían necesarios para programarla.

### Soluciones implementadas

- Con la ayuda del profesor revisamos las conexiones y realizamos las pruebas necesarias para comprender mejor el funcionamiento del circuito.
- Fuimos observando los resultados de los códigos cargados en Arduino IDE para relacionar las instrucciones con las respuestas de los componentes.
- Conversamos sobre las posibilidades de incorporar la cámara y decidimos investigar su funcionamiento antes de intentar conectarla.
- Acordamos actualizar los diagramas del circuito para incluir los nuevos componentes.

### Decisiones técnicas

- Mantuvimos el ESP32 como controlador del sensor ultrasónico HC-SR04 y del buzzer, ya que estos seguirían encargándose de detectar obstáculos y emitir alertas sonoras.
- Decidimos incorporar una ESP32-CAM para capturar imágenes y posteriormente implementar el reconocimiento de personas, animales y objetos.
- Acordamos que la cámara complementaría las funciones del sensor ultrasónico, en lugar de sustituirlo.
- Determinamos que sería necesario modificar los diagramas y revisar las conexiones adicionales para integrar la cámara al prototipo.

### Pruebas efectuadas

- Realizamos pruebas físicas con el ESP32, el sensor ultrasónico y el buzzer conectados.
- Escribimos y cargamos códigos mediante Arduino IDE para comprobar el funcionamiento de los componentes.
- Observamos cómo respondía el circuito durante las pruebas realizadas con la orientación del profesor.
- Revisamos las conexiones para identificar posibles errores y comprender mejor la comunicación entre los dispositivos.

### Aprendizajes obtenidos

- Aprendí a utilizar mejor Arduino IDE para cargar programas al ESP32 y realizar pruebas con los componentes electrónicos.
- Comprendí cómo el sensor ultrasónico puede enviar información al ESP32 para que este active una alerta mediante el buzzer.
- Esta reunión me ayudó a entender mejor la importancia de revisar las conexiones físicas y el código cuando trabajamos con varios componentes.
- También comprendí que una idea inicial puede cambiar durante el desarrollo del proyecto y que debemos estar dispuestas a investigar y adaptar nuestra propuesta cuando encontramos nuevas posibilidades.
- Me pareció importante conocer cómo podríamos aprovechar una cámara para complementar la detección de obstáculos y mejorar las funciones de los lentes inteligentes.

### Próximos pasos

- Investigar el funcionamiento de la ESP32-CAM y los componentes necesarios para programarla.
- Revisar cómo podríamos incorporar la cámara al circuito que ya habíamos comenzado a construir.
- Actualizar los diagramas para representar los nuevos componentes.
- Continuar realizando pruebas con el ESP32, el sensor ultrasónico y el buzzer.
- Investigar cómo podríamos implementar el reconocimiento de personas, animales y objetos mediante las imágenes capturadas por la cámara.



## DÍA 4 – 22 DE OCTUBRE DE 2026


### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez
- Joan Eras

### Actividades realizadas

- Este día nos reunimos para continuar avanzando con nuestro proyecto, principalmente con la ESP32-CAM y la forma en que podríamos enviar las imágenes que capturaba hacia un servidor.
- Alejandra se encargó de crear el servidor que utilizaríamos para recibir las imágenes. Mientras tanto, estuvimos realizando pruebas y revisando cómo funcionaría la comunicación entre la cámara y el servidor.
- También trabajamos con la ESP32-CAM y el adaptador FT232RL, revisando las conexiones necesarias para programar la cámara desde Arduino IDE.
- Durante las pruebas aprendimos que el pin IO0 de la ESP32-CAM debía conectarse a GND para cargar el programa y que después era necesario desconectarlo para que la cámara pudiera ejecutarlo normalmente.
- Logramos comprobar que la ESP32-CAM podía capturar fotografías, pero cuando intentamos enviarlas al servidor tuvimos problemas con la conexión a internet y no conseguimos visualizarlas.
- Por otra parte, Joan comenzó a trabajar en la documentación escrita del proyecto mientras nosotras continuábamos con las pruebas de los componentes.
- Como no logramos solucionar el problema de conexión durante la reunión, Dana se llevó la cámara a su casa para probarla utilizando otra red de internet.

### Avances

- Conseguimos avanzar con la programación de la ESP32-CAM utilizando Arduino IDE y el adaptador FT232RL.
- Comprobamos que la cámara podía capturar fotografías.
- Alejandra logró crear el servidor y realizamos pruebas enviándole imágenes para comprobar que podía recibirlas.
- Aprendimos a identificar las conexiones necesarias para programar la cámara y ponerla en funcionamiento.
- Aunque todavía no logramos visualizar las fotografías de la ESP32-CAM en el servidor, conseguimos identificar que la conexión a internet podía estar afectando las pruebas.
- Dana pudo comprobar posteriormente desde su casa que la cámara funcionaba utilizando otra red.

### Dificultades encontradas

- Uno de los principales problemas fue que, aunque la ESP32-CAM lograba capturar fotografías, no conseguíamos enviarlas y visualizarlas correctamente en el servidor.
- Tuvimos dificultades con la conexión a internet que estábamos utilizando durante la reunión.
- Al principio no sabíamos si el problema se debía al código de la cámara, al servidor o a la red.
- También tuvimos que prestar bastante atención a las conexiones del FT232RL y de la ESP32-CAM, especialmente al procedimiento necesario para cargar el programa.

### Soluciones implementadas

- Revisamos las conexiones de la ESP32-CAM y el FT232RL para asegurarnos de que estuvieran correctamente colocadas.
- Realizamos pruebas desde Arduino IDE para comprobar que la cámara podía capturar fotografías.
- Probamos el servidor enviándole imágenes de prueba y verificamos que podía recibirlas.
- Como seguíamos sin poder visualizar las fotografías enviadas directamente desde la cámara, decidimos comprobar su funcionamiento utilizando otra red de internet.
- Dana se llevó la ESP32-CAM a su casa y logró verificar que funcionaba con una conexión diferente. Esto nos permitió considerar que el problema podía estar relacionado con la red utilizada durante nuestra reunión.

### Decisiones técnicas

- Decidimos utilizar un servidor para recibir las imágenes capturadas por la ESP32-CAM y posteriormente procesarlas para reconocer personas, animales y objetos.
- Mantuvimos el FT232RL como adaptador para programar la ESP32-CAM mediante Arduino IDE.
- Acordamos realizar pruebas utilizando diferentes conexiones a internet para identificar qué estaba afectando la comunicación.
- Decidimos continuar trabajando por separado con la cámara y el servidor antes de intentar integrar completamente el reconocimiento de imágenes.
- Mantuvimos pendiente la comprobación del envío de fotografías desde la cámara hasta el servidor.

### Pruebas efectuadas

- Revisamos las conexiones entre la ESP32-CAM y el FT232RL.
- Cargamos el programa de la cámara utilizando Arduino IDE.
- Comprobamos que la ESP32-CAM lograba capturar fotografías.
- Realizamos pruebas enviando imágenes al servidor y verificamos que este podía recibirlas.
- Intentamos enviar las fotografías capturadas por la cámara al servidor, pero no logramos visualizarlas correctamente debido a los problemas de conexión.
- Dana realizó una prueba adicional desde su casa utilizando otra red de internet y comprobó el funcionamiento de la cámara. Sin embargo, esta prueba no permitió confirmar la comunicación con el servidor, ya que no tenía acceso a él desde su casa.

### Aprendizajes obtenidos

- Aprendí mejor cómo funciona la ESP32-CAM y cómo se utiliza el FT232RL para programarla desde Arduino IDE.
- Comprendí la importancia de conectar correctamente los pines TX, RX e IO0 y de distinguir entre el modo de programación y el funcionamiento normal de la cámara.
- También entendí mejor cómo se pueden enviar imágenes desde un dispositivo hacia un servidor para posteriormente procesarlas.
- Me di cuenta de que cuando un sistema no funciona como esperamos, no necesariamente significa que el código esté incorrecto, ya que también pueden influir factores como la conexión a internet.
- Aprendí que realizar pruebas por separado nos ayuda a identificar mejor dónde se encuentra un problema y evita que tengamos que modificar todo el sistema sin saber qué está fallando.

### Próximos pasos

- Volver a realizar pruebas de comunicación entre la ESP32-CAM y el servidor.
- Comprobar si podemos enviar y visualizar las fotografías utilizando una conexión a internet diferente.
- Continuar revisando el código de la cámara y su comunicación con el servidor.
- Comenzar a trabajar con YOLO para implementar el reconocimiento de personas, animales y objetos.
- Seguir avanzando con la integración de los componentes y la documentación del proyecto.



## DÍA 5 – 23 DE OCTUBRE DE 2026


### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez
- Joan Eras

### Actividades realizadas

- Este día nos reunimos los cuatro integrantes en la soda para continuar trabajando en nuestro proyecto, principalmente con la ESP32-CAM, el servidor y el reconocimiento de imágenes.
- Como ya habíamos comprobado que la cámara podía capturar fotografías y que el servidor funcionaba, retomamos las pruebas de comunicación entre ambos.
- Comenzamos a trabajar con YOLO para intentar reconocer personas, animales y objetos mediante las imágenes capturadas por la cámara.
- Estuvimos realizando modificaciones en el código de la ESP32-CAM desde la computadora de Dana, buscando mejorar la captura de imágenes y su comunicación con el servidor.
- Durante las pruebas observamos que el reconocimiento todavía presentaba algunos problemas, porque en ciertas ocasiones no lograba identificar correctamente lo que aparecía en las imágenes.
- También nos pusimos a acomodar los componentes uno junto al otro y a tomar sus medidas, ya que queríamos calcular cuánto espacio necesitaríamos para colocarlos sobre los lentes.
- Con las medidas que obtuvimos, Alejandra comenzó a elaborar un diseño en 3D para tener una idea de cómo podríamos organizar los componentes dentro de una carcasa.
- Sin embargo, al conversar con el profesor Eddier, nos dimos cuenta de que utilizar baterías sería más complicado de lo que pensábamos, debido a las diferencias de voltaje que necesitaban los componentes.
- Analizamos la posibilidad de utilizar una o varias baterías, pero esto implicaba realizar adaptaciones en la alimentación y ocupar más espacio.
- Finalmente, decidimos descartar las baterías y el diseño de la carcasa en 3D. En su lugar, acordamos utilizar una protoboard más pequeña y mantener los componentes conectados a una fuente de alimentación externa.
- Al terminar la reunión, Alejandra se llevó los componentes a su casa para continuar realizando pruebas con YOLO y revisar los problemas de reconocimiento.

### Avances

- Logramos continuar con las pruebas de comunicación entre la ESP32-CAM y el servidor.
- Realizamos modificaciones en el código de la cámara y comenzamos a probar el reconocimiento de personas, animales y objetos mediante YOLO.
- Identificamos algunas dificultades que todavía presentaba el sistema al reconocer las imágenes.
- Tomamos las medidas de los componentes y comenzamos a planificar cómo podríamos acomodarlos físicamente.
- Analizamos las opciones de alimentación del prototipo y comprendimos mejor las dificultades de utilizar baterías.
- Llegamos a un acuerdo para simplificar el diseño, utilizando una protoboard más pequeña y una fuente de alimentación externa.

### Dificultades encontradas

- Durante las pruebas con YOLO notamos que el reconocimiento no siempre funcionaba correctamente, ya que algunas personas, animales u objetos no eran identificados.
- Tuvimos que revisar y modificar el código de la ESP32-CAM para continuar realizando pruebas.
- Nos dimos cuenta de que no todos los componentes necesitaban el mismo voltaje, lo que complicaba la posibilidad de alimentarlos con una sola batería.
- También consideramos utilizar varias baterías, pero esto aumentaría el espacio ocupado y dificultaría el montaje.
- Aunque ya habíamos comenzado a tomar medidas y a trabajar en un diseño en 3D, tuvimos que reconsiderarlo porque la distribución que habíamos planeado dejó de ser conveniente.
- Además, observamos que la protoboard grande ocupaba demasiado espacio para el tipo de prototipo que queríamos construir.

### Soluciones implementadas

- Continuamos realizando pruebas con YOLO y modificamos el código de la cámara para observar si mejoraba el reconocimiento de imágenes.
- Decidimos seguir revisando los problemas de reconocimiento antes de considerar que esa parte del sistema estaba terminada.
- Alejandra se llevó los componentes para continuar realizando pruebas desde su casa.
- Después de analizar las dificultades de alimentación, acordamos no utilizar baterías y mantener una fuente de alimentación externa.
- Descartamos la carcasa en 3D que habíamos comenzado a diseñar y optamos por un montaje más sencillo.
- Decidimos conseguir una protoboard más pequeña para reducir el espacio que ocuparían los componentes y facilitar su organización.

### Decisiones técnicas

- Mantuvimos YOLO como herramienta para implementar el reconocimiento de personas, animales y objetos.
- Acordamos continuar ajustando el código de la ESP32-CAM para mejorar la captura y el procesamiento de imágenes.
- Decidimos no utilizar baterías debido a las dificultades relacionadas con la alimentación y el espacio disponible.
- Elegimos mantener una fuente de alimentación externa para continuar desarrollando y probando el prototipo.
- Descartamos el diseño de la carcasa en 3D porque ya no se adaptaba a la nueva organización que habíamos decidido.
- Acordamos utilizar una protoboard más pequeña, que todavía necesitábamos conseguir, para facilitar el montaje físico de los lentes.

### Pruebas efectuadas

- Retomamos las pruebas de comunicación entre la ESP32-CAM y el servidor.
- Realizamos modificaciones en el código de la cámara desde la computadora de Dana.
- Probamos el reconocimiento de personas, animales y objetos mediante YOLO y observamos que todavía presentaba algunas dificultades.
- Acomodamos los componentes y tomamos sus medidas para calcular el espacio que necesitaríamos.
- Revisamos las necesidades de alimentación de los dispositivos para valorar si era conveniente utilizar baterías.
- Analizamos diferentes posibilidades de distribución de los componentes antes de decidir cambiar el diseño físico del prototipo.

### Aprendizajes obtenidos

- Aprendí que el reconocimiento de imágenes mediante YOLO no siempre funciona correctamente desde las primeras pruebas y que es necesario realizar ajustes para mejorar los resultados.
- Comprendí mejor la importancia de revisar el código y realizar varias pruebas antes de dar por terminada una función del proyecto.
- También aprendí que debemos considerar los voltajes que necesita cada componente antes de decidir cómo vamos a alimentar un circuito.
- Me di cuenta de que no basta con pensar en cómo funcionará el sistema, sino que también debemos tomar en cuenta el espacio que ocuparán los dispositivos y cómo los vamos a acomodar físicamente.
- Esta reunión me ayudó a comprender que, aunque ya hayamos comenzado un diseño, a veces es necesario modificarlo o descartarlo cuando encontramos una alternativa más práctica.
- También entendí que simplificar el montaje puede ayudarnos a concentrarnos en mejorar el funcionamiento del prototipo.

### Próximos pasos

- Conseguir la protoboard más pequeña para trasladar los componentes y continuar con el montaje.
- Revisar cómo podríamos organizar las conexiones en la nueva protoboard.
- Preparar una estructura más sencilla para colocar los componentes sobre los lentes.
- Mantener el uso de una fuente de alimentación externa.
- Continuar realizando pruebas con YOLO para mejorar el reconocimiento de personas, animales y objetos.
- Seguir revisando la comunicación entre la ESP32-CAM y el servidor.


## DÍA 6 – 30 DE OCTUBRE DE 2026

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Este día nos reunimos nuevamente las tres para continuar trabajando en nuestro proyecto, ya que finalmente habíamos recibido la protoboard más pequeña que estábamos esperando.
- Comenzamos a trasladar los componentes y las conexiones que teníamos en la protoboard grande hacia la nueva, tratando de acomodarlos de manera que ocuparan menos espacio.
- Mientras realizábamos el cambio, estuvimos revisando las conexiones para asegurarnos de colocar correctamente cada componente y evitar errores.
- Una vez que terminamos de organizar el circuito, realizamos nuevas pruebas para comprobar que los dispositivos siguieran funcionando después del cambio de protoboard.
- También continuamos trabajando con YOLO, ya que todavía teníamos algunas dificultades con el reconocimiento de personas, animales y objetos.
- Después decidimos colocar los componentes sobre unos lentes para observar cómo podría quedar físicamente nuestro prototipo.
- Utilizamos los materiales que teníamos disponibles para realizar un primer montaje provisional y estuvimos probando cómo quedaban acomodados los dispositivos.
- Durante las pruebas nos dimos cuenta de que todavía necesitábamos mejorar la distribución de los cables y encontrar una manera más firme de sujetar los componentes.

### Avances

- Logramos trasladar los componentes de la protoboard grande a una más pequeña, reduciendo el espacio que ocupaba el circuito.
- Conseguimos organizar nuevamente las conexiones y realizar pruebas para comprobar su funcionamiento.
- Realizamos nuestro primer montaje físico provisional de los lentes inteligentes.
- Continuamos realizando pruebas con YOLO para observar cómo respondía el reconocimiento de personas, animales y objetos.
- Pudimos visualizar mejor cómo quedarían los componentes colocados sobre los lentes y cuáles aspectos necesitaríamos mejorar.
- Avanzamos con la idea de utilizar un diseño más sencillo, sin baterías ni una carcasa en 3D.

### Dificultades encontradas

- Al pasar los componentes a la protoboard pequeña, tuvimos que prestar más atención a la distribución de los cables, porque el espacio disponible era menor.
- Durante las pruebas con YOLO observamos que el sistema todavía presentaba problemas para reconocer correctamente algunas personas, animales y objetos.
- Como todavía no teníamos una estructura definitiva para sujetar los componentes, el montaje de los lentes fue provisional.
- Nos costó encontrar una distribución que permitiera acomodar los dispositivos sin que los cables quedaran demasiado desordenados.
- Aunque logramos colocar los componentes sobre los lentes, todavía necesitábamos mejorar su estabilidad para que el montaje fuera más adecuado.

### Soluciones implementadas

- Revisamos las conexiones de cada componente mientras los trasladábamos a la protoboard pequeña para evitar equivocarnos.
- Después de terminar el cambio, realizamos pruebas para comprobar que los dispositivos continuaran funcionando.
- Seguimos probando YOLO para observar en cuáles situaciones presentaba problemas de reconocimiento.
- Utilizamos los materiales que teníamos disponibles para sujetar provisionalmente los componentes sobre los lentes.
- Fuimos observando cómo quedaban distribuidos los dispositivos e identificamos los aspectos que necesitaríamos mejorar.
- Mantuvimos la decisión de trabajar con una estructura sencilla que nos permitiera continuar haciendo ajustes sin complicar demasiado el montaje.

### Decisiones técnicas

- Decidimos mantener la protoboard pequeña para el montaje del prototipo, ya que nos permitía reducir el espacio ocupado por los componentes.
- Acordamos continuar utilizando YOLO para el reconocimiento de personas, animales y objetos, aunque todavía necesitábamos mejorar sus resultados.
- Mantuvimos el uso de una fuente de alimentación externa, como habíamos decidido en la reunión anterior.
- Confirmamos que no utilizaríamos baterías ni continuaríamos con el diseño de la carcasa en 3D.
- Decidimos utilizar este primer montaje como referencia para organizar mejor los componentes y preparar una versión más estable de los lentes.

### Pruebas efectuadas

- Revisamos las conexiones del circuito después de trasladar los componentes a la protoboard pequeña.
- Realizamos pruebas para comprobar que los dispositivos continuaran funcionando correctamente después del cambio.
- Continuamos probando el reconocimiento de personas, animales y objetos mediante YOLO.
- Colocamos los componentes sobre unos lentes y realizamos pruebas con el montaje provisional.
- Observamos cómo quedaban distribuidos los cables y los dispositivos para identificar qué cambios serían necesarios.
- Comprobamos que todavía debíamos mejorar la organización y sujeción de algunos componentes antes de realizar el montaje definitivo.

### Aprendizajes obtenidos

- Aprendí que cambiar los componentes de una protoboard a otra requiere bastante cuidado, porque debemos revisar las conexiones y asegurarnos de que todo continúe funcionando.
- Comprendí que utilizar una protoboard más pequeña ayuda a ahorrar espacio, pero también hace necesario organizar mejor los cables.
- Me di cuenta de que no basta con lograr que los componentes funcionen, sino que también debemos pensar en cómo colocarlos físicamente para que el prototipo sea práctico.
- También comprendí que el reconocimiento de imágenes necesita varias pruebas y ajustes, ya que los resultados pueden cambiar dependiendo de lo que capture la cámara.
- Esta experiencia me ayudó a entender la importancia de realizar primero un montaje provisional, porque así podemos identificar problemas que no habíamos considerado.
- Aprendí que trabajar en equipo facilita la revisión de conexiones y la búsqueda de soluciones cuando necesitamos realizar cambios en el diseño.

### Próximos pasos

- Buscar una forma más firme y organizada de sujetar los componentes sobre los lentes.
- Mejorar la distribución de los cables para que el prototipo sea más estable.
- Continuar realizando pruebas y ajustes con YOLO para mejorar el reconocimiento de personas, animales y objetos.
- Revisar nuevamente el funcionamiento de los componentes cuando realicemos cambios en el montaje.
- Preparar una versión física más organizada del prototipo de lentes inteligentes.


## DÍA 7 – 12 Y 13 DE NOVIEMBRE DE 2026

### Integrantes presentes

- Alejandra Quintanilla
- Dana Aguirre
- Shirley Pérez

### Actividades realizadas

- Durante estos dos días nos reunimos las tres para trabajar en el montaje definitivo de nuestro prototipo de lentes inteligentes, utilizando unos lentes como base para colocar los componentes electrónicos.
- Comenzamos a acomodar el sensor ultrasónico HC-SR04, el buzzer, la ESP32-CAM y los demás componentes que forman parte del circuito, tratando de encontrar una distribución que fuera funcional y que también se viera ordenada.
- Una de las tareas que más tiempo nos llevó fue organizar los cables jumper, ya que necesitábamos conectarlos correctamente sin que estorbaran demasiado ni quedaran sobresaliendo por todas partes.
- Estuvimos probando diferentes posiciones para los componentes y los cables, buscando que quedaran bien sujetos a los lentes y que el prototipo tuviera una mejor apariencia.
- También utilizamos pegamento para fijar los componentes y algunas conexiones. Sin embargo, conforme avanzábamos, se nos complicó identificar algunos cables porque quedaban muy juntos y ya no era tan fácil distinguir a qué pin correspondía cada uno.
- Durante el proceso fuimos revisando las conexiones y acomodando nuevamente algunos cables para evitar confusiones.
- El viernes 13 logramos terminar el montaje y realizamos pruebas para revisar el funcionamiento del prototipo después de haber colocado los componentes sobre los lentes.
- Al finalizar, Alejandra se llevó los lentes a su casa para mejorar la organización de los cables y hacer que fuera más fácil identificar de qué pin salía cada conexión y hacia dónde se dirigía.

### Avances

- Logramos colocar los componentes electrónicos sobre la estructura de los lentes, avanzando del montaje provisional a una versión física más completa del prototipo.
- Conseguimos distribuir el sensor ultrasónico, el buzzer y la ESP32-CAM sobre los lentes.
- Avanzamos en la organización y fijación de los cables jumper, aunque todavía quedaban algunos detalles por mejorar.
- El viernes terminamos el montaje que habíamos planificado y realizamos pruebas para revisar su funcionamiento.
- Identificamos aspectos importantes que necesitábamos corregir para facilitar la revisión de las conexiones y mejorar la presentación del prototipo.

### Dificultades encontradas

- Una de las mayores dificultades fue encontrar la manera de colocar todos los componentes sobre los lentes, ya que el espacio era limitado y debíamos procurar que quedaran bien sujetos.
- Nos costó bastante acomodar los cables jumper porque algunos eran largos, se cruzaban entre sí y dificultaban que el montaje se viera ordenado.
- También queríamos que los componentes quedaran distribuidos de una manera más estética, pero al mismo tiempo necesitábamos mantener las conexiones necesarias para su funcionamiento.
- Al utilizar pegamento para fijar algunas partes, varios cables quedaron muy juntos y se nos hizo difícil distinguir cuáles correspondían a determinados pines.
- Esto complicaba la revisión del circuito, porque no siempre era sencillo seguir visualmente el recorrido de cada cable desde su origen hasta su destino.
- Tuvimos que dedicar bastante tiempo a encontrar posiciones adecuadas para los componentes sin afectar las conexiones.

### Soluciones implementadas

- Fuimos probando diferentes posiciones para los componentes hasta encontrar una distribución que se adaptara mejor a la estructura de los lentes.
- Reacomodamos los cables jumper varias veces para reducir el desorden y evitar que sobresalieran demasiado.
- Utilizamos pegamento para sujetar los componentes y mantenerlos en las posiciones que habíamos elegido.
- Cuando se nos dificultaba identificar alguna conexión, revisábamos los pines y el recorrido de los cables para evitar confundirlos.
- Después de terminar el montaje, acordamos que todavía era necesario mejorar la organización del cableado.
- Por esta razón, Alejandra se llevó el prototipo a su casa para acomodar mejor los cables y facilitar la identificación de las conexiones.

### Decisiones técnicas

- Decidimos utilizar los lentes como estructura principal para sostener los componentes electrónicos del prototipo.
- Mantuvimos el sensor ultrasónico HC-SR04 para detectar obstáculos, el buzzer para generar alertas sonoras y la ESP32-CAM para capturar imágenes.
- Optamos por fijar los componentes a la estructura de los lentes para evitar que se movieran durante las pruebas.
- Acordamos organizar los cables jumper de manera que ocuparan el menor espacio posible, sin perder de vista la necesidad de identificar correctamente cada conexión.
- Decidimos que, aunque el montaje ya estuviera terminado, era importante mejorar el cableado antes de considerar completamente finalizada su presentación física.

### Pruebas efectuadas

- Revisamos las conexiones de los componentes mientras realizábamos el montaje sobre los lentes.
- Comprobamos que los cables permanecieran conectados después de acomodar y fijar los dispositivos.
- El viernes 13 realizamos pruebas del prototipo montado para revisar su funcionamiento.
- Observamos cómo quedaban distribuidos los componentes y los cables al estar colocados sobre los lentes.
- Identificamos que todavía era necesario mejorar la organización del cableado para facilitar futuras revisiones y evitar confusiones entre los pines.

### Aprendizajes obtenidos

- Aprendí que montar los componentes electrónicos sobre una estructura física puede ser más complicado de lo que parece, especialmente cuando tenemos poco espacio disponible.
- Comprendí que no basta con conectar correctamente los dispositivos, sino que también debemos pensar en cómo acomodarlos para que el prototipo sea funcional y tenga una buena presentación.
- Me di cuenta de lo importante que es mantener los cables identificados y organizados, porque cuando se cruzan o quedan demasiado juntos resulta difícil reconocer a qué pin pertenece cada uno.
- También aprendí que debemos tener cuidado al fijar los componentes, ya que después puede ser más complicado moverlos o revisar sus conexiones.
- Estos dos días me ayudaron a comprender mejor la importancia de planificar la distribución física de un circuito antes de sujetar definitivamente sus componentes.
- Además, reforcé mis conocimientos sobre las conexiones electrónicas y la importancia de trabajar en equipo para encontrar soluciones cuando el montaje presenta dificultades.

### Próximos pasos

- Mejorar la organización de los cables jumper para que sea más sencillo identificar el origen y destino de cada conexión.
- Revisar nuevamente el circuito después de realizar los ajustes en el cableado.
- Comprobar que todos los componentes continúen funcionando correctamente.
- Realizar los últimos ajustes necesarios para mejorar la presentación física del prototipo.
- Preparar las evidencias del montaje y las pruebas realizadas para incluirlas en la documentación del proyecto.

### Día 8 – Sábado 14 y domingo 15 de noviembre de 2026

**Actividad realizada: Elaboración y organización de la documentación técnica del proyecto.**

Durante el sábado y domingo trabajé en la elaboración de la documentación técnica del proyecto de lentes inteligentes, con el propósito de organizar la información necesaria para explicar su funcionamiento y facilitar la comprensión del sistema desde el repositorio de GitHub.

Primero, revisé la estructura del repositorio y las indicaciones del profesor para identificar qué información debía incluirse en la documentación, procurando no repetir el contenido desarrollado en el artículo académico.

Posteriormente, redacté y organicé los apartados relacionados con la descripción general del proyecto, los componentes electrónicos, las tecnologías utilizadas y la arquitectura del sistema. También documenté el funcionamiento del sensor ultrasónico, las alertas sonoras y el reconocimiento de imágenes mediante la ESP32-CAM y YOLO.

Además, trabajé en las instrucciones generales para la instalación y ejecución del prototipo, considerando los requisitos de hardware, software y comunicación con el servidor Flask. También incorporé la información de los diagramas elaborados en Cirkit Designer y draw.io, para relacionarlos con la explicación técnica del sistema.

Durante este proceso realicé ajustes en la redacción y el formato del README, buscando que la documentación fuera clara, ordenada y fácil de consultar desde GitHub.

**Aprendizaje obtenido:**

Esta actividad me permitió comprender mejor la importancia de la documentación técnica en un proyecto de programación. Aprendí a organizar la información del sistema y a diferenciar la documentación técnica del artículo académico, evitando repetir explicaciones y enfocándome en los aspectos necesarios para comprender y reproducir el funcionamiento del prototipo.

**Resultado:**

Se avanzó en la elaboración del documento técnico del repositorio, dejando organizadas las secciones principales y algunos detalles pendientes de verificar con el código fuente.
