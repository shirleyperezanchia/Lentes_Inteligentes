# Proyecto: Lentes Inteligentes Asistivos

# Bitácora de: Dana Paola Aguirre Espinoza

Curso: Paradigmas de Programación  
Profesor: Eddier López  
Forma de trabajo: el proyecto lo trabajamos en equipo con Alejandra Quintanilla Muñiz, Shirley Pérez Anchía y Joan Eras. Cuando hice algo por mi cuenta lo marco como individual.

## Semana 1 – Día 1 (30/09/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía

### Actividades realizadas

- En la primera reunión, cada una compartió las ideas que tenía para el proyecto.
- Después de escuchar todas las propuestas, elegimos la que nos pareció con más sentido: unos lentes inteligentes para personas no videntes, que por medio de un sensor detecten lo que tienen adelante y les avisen con un sonido.
- Como los materiales los facilitaba el profesor, revisamos con cuáles podíamos contar para el proyecto: un ESP32, un sensor ultrasónico y un buzzer. La cámara quedó anotada solo como una posibilidad.
- Individual: tanto en la universidad como en mi casa, busqué en redes sociales e internet proyectos parecidos y dispositivos de apoyo para personas no videntes, y le compartí al grupo lo que encontré como referencia.

### Avances

- Quedó definido el tema del proyecto.
- Teníamos claro el objetivo: que la persona sepa a tiempo que hay un obstáculo cerca y pueda desplazarse con más confianza.
- Sabíamos con qué materiales íbamos a trabajar.

### Dificultades encontradas

- Escoger una sola idea no fue fácil; buscábamos algo que de verdad ayudara a alguien, pero que estuviera a nuestro alcance.
- Yo todavía no sabía para qué servía cada componente ni cuál convenía usar.

### Soluciones implementadas

- Cada una dio su punto de vista y analizamos qué tan posible era cada idea; así llegamos a un acuerdo.
- Leímos un poco sobre cada componente para tener una base antes de escoger.

### Decisiones técnicas

- Como primera versión, el prototipo tendría solo dos partes: el sensor ultrasónico para medir la distancia y el buzzer para dar la alerta.
- El ESP32 sería el encargado de controlar todo.

### Pruebas efectuadas

- Ese día solo planeamos; todavía no teníamos nada armado para probar.

### Aprendizajes obtenidos

- Escuchar a todas antes de decidir hace que la decisión final sea mejor.
- Antes de conectar algo, hay que entender qué hace cada pieza.
- Revisar proyectos parecidos me dio una idea más clara de lo que podíamos lograr.

### Próximos pasos

- Estudiar cómo funciona y cómo se programa cada componente antes de la siguiente reunión.
- Recibir los materiales del profesor para empezar con las primeras pruebas.

## Semana 1 – Día 2 (01/10/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía

### Actividades realizadas

- En la segunda reunión el objetivo fue conocer los componentes uno por uno: el ESP32, el sensor HC-SR04 y el buzzer.
- Antes de conectar, identificamos qué pin era cada cosa y cómo se alimentaba cada componente.
- Empezamos los primeros diagramas del circuito. Alejandra se encargó de Wokwi, donde montó el ESP32 con el sensor, el buzzer y el código.
- Individual (02/10): me encargué de la parte de alimentación. La simulé en Proteus y en Tinkercad: batería de 9 V, interruptor y un regulador 7805 que baja el voltaje a 5 V, con una resistencia de 100 Ω como carga de prueba.

### Avances

- Ya sabíamos qué hace cada componente y cómo se conecta.
- Los diagramas iniciales ya nos daban una guía para el montaje.
- En mi simulación verifiqué que la alimentación da los 5 V que necesita el ESP32.

### Dificultades encontradas

- Algunos pines no eran fáciles de identificar y no teníamos claro el orden correcto de las conexiones.
- Ningún simulador tenía todos los componentes del proyecto juntos.

### Soluciones implementadas

- Fuimos componente por componente, revisando su información antes de conectarlo.
- Nos repartimos las simulaciones: Wokwi para la parte del ESP32 (Alejandra) y Proteus y Tinkercad para la alimentación (yo).

### Decisiones técnicas

- El ESP32 sigue como el centro del proyecto; el HC-SR04 mide la distancia y el buzzer da las alertas.
- Trabajar las simulaciones en programas distintos, en lugar de buscar uno que tuviera todo.
- En la simulación usé un regulador 7805, pero noté que se pierde mucha energía en calor al pasar de 9 V a 5 V. Para los lentes sería mejor un convertidor DC-DC (step-down).

### Pruebas efectuadas

- Cada componente se probó por su cuenta antes de unirlo a los demás.
- Comprobamos a qué pin iba cada conexión y cómo se alimentaba cada componente.
- Proteus: el regulador entregó 5.001 V y la corriente por la resistencia de 100 Ω fue de 50.01 mA.
- Tinkercad: el mismo circuito marcó 5.00 V y 50.0 mA.
- Con el interruptor abierto marcó 0 V y 0 mA, o sea que el interruptor sí corta el paso de corriente.
- Los 50 mA coinciden con la Ley de Ohm (5 V / 100 Ω = 0.05 A). Es una carga de prueba, no el consumo real de los lentes.

### Aprendizajes obtenidos

- Ahora reconozco con más facilidad los pines de cada componente.
- Probar las piezas por separado evita errores cuando se conecta todo junto.
- Aprendí a simular un circuito en Proteus y Tinkercad y a medir voltaje y corriente.
- Si una herramienta no alcanza, se puede combinar con otra.

### Próximos pasos

- Corregir y completar los diagramas.
- Ver cómo se comportan los componentes cuando trabajan conectados.
- Dejar listo lo necesario para empezar el montaje en físico.

## Semana 1 – Día 3 (02/10/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía

### Actividades realizadas

- Esta vez la reunión fue con el profesor Eddier López, en la sala de profesores. Nos ayudó a conectar los componentes en los que veníamos trabajando.
- Gracias a su ayuda quedaron conectados el ESP32, el sensor HC-SR04 y el buzzer, y por primera vez los vimos funcionando juntos.
- La programación la hicimos en Arduino IDE, entre las tres, desde mi computadora.
- Con todo conectado, revisamos que respondiera bien y cómo se pasaban la información entre ellos.
- También salió la idea de sumar una ESP32-CAM, para que los lentes hicieran algo más que medir distancia con el sensor.

### Avances

- Tuvimos el circuito armado y funcionando desde Arduino IDE.
- La programación del sensor y el buzzer avanzó bastante.
- Le agregamos la cámara a la idea del proyecto, para que más adelante los lentes también puedan reconocer personas y animales.

### Dificultades encontradas

- No era sencillo saber cómo conectar todo ni cómo escribir el código para que funcionara.
- La idea de la cámara nos obligó a replantear varias cosas, porque los diagramas que teníamos no la incluían.

### Soluciones implementadas

- El profesor nos guio con las conexiones, y después nosotras fuimos probando paso a paso en Arduino IDE.
- Analizamos dónde encajaba la ESP32-CAM y adaptamos la idea del proyecto.

### Decisiones técnicas

- El sensor ultrasónico, el ESP32 y el buzzer se quedan como la base para detectar obstáculos.
- Sumar la ESP32-CAM para reconocer personas y animales.
- Rehacer los diagramas para que incluyan la cámara.

### Pruebas efectuadas

- Verificamos el circuito del ESP32 ya conectado al sensor y al buzzer.
- Subimos el código desde Arduino IDE y revisamos que cada componente respondiera.
- Fue la primera vez que probamos el circuito ya montado en físico. El profesor nos ayudó a montarlo y las pruebas en Arduino IDE las hicimos nosotras.

### Aprendizajes obtenidos

- Gané práctica conectando componentes y programándolos en Arduino IDE.
- Ver el sensor, el ESP32 y el buzzer funcionando juntos me ayudó a entender el sistema completo.
- Un proyecto puede cambiar en el camino, y eso no es malo si mejora la idea.

### Próximos pasos

- Averiguar qué necesita la ESP32-CAM para funcionar con el proyecto.
- Actualizar los diagramas con la cámara.
- Continuar programando y probando.

## Semana 4 – Día 4 (22/10/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía
- Joan Eras

### Actividades realizadas

- El trabajo se centró en la ESP32-CAM y en cómo hacer llegar sus fotos a un servidor.
- Alejandra armó el servidor que iba a recibir las imágenes, y lo probamos mandándole fotos de prueba.
- Conectamos la ESP32-CAM al adaptador FT232RL para poder programarla desde Arduino IDE.
- Para cargar el programa, el pin IO0 tenía que ir a GND; una vez cargado, había que quitar esa conexión para que la cámara arrancara normal.
- En el Monitor Serial aparecía que la cámara tomaba las fotos y la hora de cada una, pero no salía el enlace para verlas. Pensamos que era culpa del Wi-Fi de la universidad.
- Mientras nosotras probábamos los componentes, Joan empezó con la parte escrita del proyecto.
- Individual (en casa): me llevé la cámara para probarla con mi propio Wi-Fi. Ahí sí apareció el enlace y se podían ver las fotos, así que confirmamos que la cámara funcionaba y que el problema era la red de la universidad.

### Avances

- El servidor de Alejandra ya recibía las imágenes de prueba.
- Logramos programar la ESP32-CAM y ver que tomaba fotos.
- Encontramos que la falla venía de la red y no de la cámara.
- Joan empezó con el documento escrito.

### Dificultades encontradas

- Las fotos se tomaban, pero en la universidad no había forma de verlas.
- Al principio no sabíamos si el error estaba en el código de la cámara, en el servidor o en el internet.

### Soluciones implementadas

- Probamos el servidor por aparte con imágenes de prueba, para descartar que el problema fuera ese.
- Usamos el Monitor Serial para confirmar que la cámara sí estaba tomando las fotos.
- Probé la cámara en mi casa con otra red, y así quedó claro que el problema era el Wi-Fi de la universidad.

### Decisiones técnicas

- Usar un servidor para recibir las fotos de la ESP32-CAM y después trabajar ahí el reconocimiento de personas y animales.
- Seguir usando el FT232RL para programar la cámara.
- Hacer las pruebas de la cámara en otras redes antes de seguir uniendo todo el sistema.
- Dejar para otra reunión la conexión entre la cámara y el servidor.

### Pruebas efectuadas

- Le mandamos imágenes de prueba al servidor y las recibió.
- Cargamos el código de la cámara y en el Monitor Serial vimos que tomaba fotos.
- Intentamos ver las fotos de la cámara desde la universidad, pero no salía el enlace.
- En mi casa, con mi Wi-Fi, el enlace sí apareció y pude ver las fotos de la cámara. Ese día solo probé la cámara; todavía no la conecté con el servidor.

### Aprendizajes obtenidos

- Entendí cómo se mandan las fotos de una cámara a un servidor.
- Me quedó claro cómo se programa la ESP32-CAM con el FT232RL y por qué el IO0 solo se conecta a GND al cargar el programa.
- La red puede hacer que algo parezca dañado aunque los componentes estén bien.
- Cuando algo falla, sirve revisar cada parte por separado hasta encontrar dónde está el problema.

### Próximos pasos

- Reunirnos de nuevo para probar la cámara con el servidor.
- Buscar una red donde se puedan mandar y ver las fotos.
- Cuando las fotos lleguen al servidor, seguir con el reconocimiento de personas y animales.
- Continuar con el documento escrito y con la unión de los componentes.

## Semana 4 – Día 5 (23/10/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía
- Joan Eras

### Actividades realizadas

- Esta vez trabajamos en la soda de la universidad. Como la cámara ya estaba comprobada y el servidor de Alejandra funcionaba, el plan fue empezar con el reconocimiento de personas y animales usando YOLO.
- Para que la red de la universidad no nos bloqueara otra vez, Shirley compartió el Wi-Fi de la U desde su laptop y así creó una red propia, a la que conectamos la cámara y el servidor.
- El servidor con YOLO lo pusimos a correr en mi laptop. Alejandra ya tenía YOLO instalado en la suya.
- Individual: ese día descargué e instalé YOLO y lo necesario para el servidor en mi laptop.
- Entre todas, desde mi computadora, cambiamos el código de la ESP32-CAM para que mandara sus fotos al servidor, y también hicimos el código del ESP32 que maneja el sensor y el buzzer.
- En las pruebas notamos que YOLO no siempre lograba reconocer a las personas.
- También medimos los componentes, acomodados uno junto al otro, para calcular el espacio que necesitaría una carcasa. A partir de esas medidas, Alejandra comenzó un diseño en 3D.
- Durante la reunión, el profesor Eddier nos indicó que debíamos cambiar algunas conexiones y que la batería que teníamos pensada no era adecuada.
- Por estos cambios descartamos el diseño en 3D. Decidimos usar una protoboard más pequeña y dejar el circuito conectado a la computadora y a la corriente.
- Al terminar, Alejandra se llevó los componentes a su casa para seguir probando YOLO y revisar por qué no reconocía bien a algunas personas.

### Avances

- Logramos que la cámara se comunicara con el servidor en la universidad, gracias a la red que compartió Shirley.
- Empezamos a trabajar con YOLO para reconocer personas y animales.
- El servidor quedó funcionando en mi laptop.
- Avanzamos con el código de la cámara y con el del ESP32 del sensor y el buzzer.
- Quedó definido que usaríamos una protoboard más pequeña y que el circuito estaría conectado a la computadora y a la corriente.

### Dificultades encontradas

- YOLO no siempre detectaba a las personas.
- La batería que teníamos pensada no servía para el proyecto: los componentes no necesitan todos el mismo voltaje, así que con una sola batería habría que adaptar la alimentación, y con varias se ocuparía más espacio en los lentes.
- Ya habíamos medido los componentes y empezado el 3D cuando tuvimos que descartarlo por los cambios en el circuito.
- La protoboard que teníamos era muy grande para lo que queríamos montar.

### Soluciones implementadas

- Usar la red compartida desde la laptop de Shirley para que la cámara y el servidor se pudieran comunicar en la universidad.
- Seguir probando YOLO para encontrar qué afectaba el reconocimiento; Alejandra se encargó de eso en su casa.
- Hacer caso a las recomendaciones del profesor sobre las conexiones y la alimentación.
- Cambiar a una protoboard más pequeña y dejar de lado la carcasa en 3D.

### Decisiones técnicas

- Usar YOLO para reconocer personas y animales en las fotos de la ESP32-CAM.
- Correr el servidor con YOLO en mi laptop.
- Mantener el circuito conectado a la computadora y a la corriente en lugar de usar batería.
- No hacer la carcasa en 3D, porque el montaje no iba a ser portátil.
- Usar una protoboard más pequeña y ordenar de nuevo las conexiones.

### Pruebas efectuadas

- Probamos que la ESP32-CAM le mandara las fotos al servidor por la red compartida.
- Después de cambiar el código de la cámara en mi computadora, volvimos a probarla.
- Probamos el reconocimiento con YOLO; detectaba personas, pero no en todos los casos.
- Revisamos las conexiones con lo que nos dijo el profesor.

### Aprendizajes obtenidos

- El reconocimiento de imágenes no sale perfecto a la primera; hay que ir ajustándolo.
- Antes de pensar en una carcasa hay que tener claro cómo se va a alimentar el circuito y cuánto espacio ocupa.
- Al elegir cómo alimentar el circuito hay que tomar en cuenta el voltaje que necesita cada componente.
- Aprendí a instalar y poner a funcionar el servidor con YOLO en mi laptop.
- Si una red bloquea la conexión, se puede compartir el internet desde una laptop y trabajar con una red propia.
- A veces toca cambiar una idea aunque ya se haya avanzado en ella.

### Próximos pasos

- Conseguir la protoboard pequeña y pasar el circuito a ella.
- Pensar cómo acomodar los componentes en la nueva protoboard.
- Decidir cómo va a quedar el prototipo, sabiendo que estará conectado a la computadora y a la corriente.
- Seguir mejorando el reconocimiento de personas y animales con YOLO.

## Semana 5 – Día 6 (30/10/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía

### Actividades realizadas

- Ya teníamos la protoboard pequeña que estábamos esperando, así que nos reunimos para seguir con el proyecto.
- Pasamos poco a poco los componentes y los cables de la protoboard grande a la nueva, cuidando el orden para no confundir ninguna conexión.
- Con todo ya acomodado, volvimos a probar el circuito para confirmar que el cambio no había afectado nada.
- Seguimos haciendo pruebas con YOLO, porque todavía fallaba en algunos casos al reconocer personas, animales y objetos.
- Para tener una idea de cómo se verían los lentes, colocamos los componentes sobre unos lentes con los materiales que teníamos a mano.
- Con ese montaje provisional nos pusimos los lentes y probamos cómo respondían los componentes así colocados.

### Avances

- El circuito quedó en la protoboard pequeña y ahora ocupa mucho menos espacio.
- Hicimos el primer montaje físico de los lentes.
- Confirmamos que los componentes seguían funcionando después del cambio de protoboard.
- Seguimos avanzando con las pruebas de YOLO.
- Con el montaje pudimos ver más o menos cómo quedaría el prototipo y qué cosas faltaba mejorar.

### Dificultades encontradas

- YOLO todavía no detectaba bien a las personas, los animales y los objetos en todos los casos.
- El montaje sobre los lentes fue improvisado, porque aún no teníamos una forma fija de sostener los componentes.
- En la protoboard pequeña el espacio es más reducido, así que había que acomodar los cables con más cuidado.

### Soluciones implementadas

- Después del traslado revisamos cada conexión para asegurarnos de que estuviera en su lugar.
- Seguimos probando YOLO para ver en qué situaciones fallaba.
- Armamos el montaje provisional con lo que teníamos disponible, para probar el prototipo puesto.
- Anotamos qué había que mejorar en el acomodo y la sujeción de los componentes para el montaje final.

### Decisiones técnicas

- Quedarnos con la protoboard pequeña para el montaje final, porque ocupa menos espacio y es más fácil de ordenar.
- Seguir usando YOLO para el reconocimiento, aunque todavía hay que mejorarlo.
- Tomar el montaje provisional como base para hacer una versión más ordenada y firme.
- Mantener el circuito conectado a la fuente de alimentación, como ya lo habíamos decidido.

### Pruebas efectuadas

- Revisamos que las conexiones funcionaran después de pasar todo a la protoboard pequeña.
- Probamos de nuevo el reconocimiento con YOLO.
- Probamos los componentes ya colocados sobre los lentes, en el montaje provisional.
- Revisamos cómo estaban distribuidos los componentes para ver qué cambiar antes del montaje final.

### Aprendizajes obtenidos

- Al cambiar a una protoboard más pequeña hay que ordenar mejor los cables y revisar que todo siga funcionando.
- No es suficiente que los componentes funcionen; también hay que pensar cómo van a quedar acomodados en los lentes.
- YOLO necesita más pruebas y ajustes para reconocer mejor.
- Un montaje de prueba ayuda a encontrar problemas que no se ven hasta tener el prototipo puesto.

### Próximos pasos

- Hacer un montaje de los lentes más ordenado, firme y definitivo.
- Buscar una mejor manera de sujetar los componentes para que el prototipo quede estable.
- Seguir probando y ajustando YOLO.

## Semana 7 – Día 7 (12/11/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía

### Actividades realizadas

- Empezamos a armar el prototipo final, acomodando todos los componentes en el lugar donde iban a quedar.
- Forramos una diadema con foam para usarla como soporte de los componentes.
- Pegamos los componentes en unos lentes de sol, que serían la base de los lentes inteligentes. Para fijarlos usamos cinta aislante negra, cinta doble cara y silicón caliente.
- No alcanzamos a terminar el montaje ese día, así que quedó pendiente para la siguiente reunión.
- Individual: además del montaje, trabajé en el artículo de investigación del proyecto.

### Avances

- Comenzamos el montaje definitivo del prototipo.
- La diadema quedó forrada y lista para sostener los componentes.
- Parte de los componentes ya quedó pegada en los lentes de sol.
- Avancé en el artículo de investigación.

### Dificultades encontradas

- Acomodar todos los componentes en un espacio tan pequeño tomó más tiempo del que pensábamos.
- El montaje no se pudo terminar en una sola reunión.

### Soluciones implementadas

- Hicimos el montaje entre las tres: forramos la diadema, acomodamos los componentes y los pegamos juntas.
- Dejamos lo que faltaba para continuarlo en la siguiente reunión.

### Decisiones técnicas

- Usar unos lentes de sol como base del prototipo.
- Usar una diadema forrada con foam como apoyo para sostener los componentes.
- Fijar todo con cinta aislante negra, cinta doble cara y silicón caliente, junto con la protoboard pequeña.

### Pruebas efectuadas

- Este día nos enfocamos en el montaje físico, así que no hicimos pruebas nuevas.

### Aprendizajes obtenidos

- Pasar de la protoboard a algo que se pueda poner en la cabeza requiere pensar bien dónde va cada componente.
- El montaje final lleva tiempo y es mejor hacerlo con calma para no dañar las conexiones.

### Próximos pasos

- Terminar de acomodar y pegar los componentes.
- Ordenar los cables para que el prototipo quede limpio y firme.

## Semana 7 – Día 8 (13/11/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Shirley Pérez Anchía

### Actividades realizadas

- Continuamos con el montaje que habíamos empezado el día anterior.
- Fuimos acomodando los cables para que no se enredaran y estorbaran lo menos posible.
- Seguimos pegando los componentes en los lentes y en la diadema con cinta aislante negra, cinta doble cara y silicón caliente.
- Terminamos el montaje y, al final, probamos el prototipo ya montado para revisar que todo siguiera funcionando.
- Individual: trabajé en el artículo de investigación. Redacté la sección de funcionalidades del prototipo y, en el marco teórico, las secciones del buzzer y de la base de datos SQLite, buscando fuentes académicas reales y citándolas en formato IEEE.

### Avances

- El prototipo quedó más ordenado, aunque todavía había que mejorar el acomodo de los cables.
- Terminamos el montaje final de los lentes.
- Comprobamos que el prototipo funciona ya montado.
- Quedaron escritas en el artículo las secciones de funcionalidades, buzzer y SQLite, con sus referencias en formato IEEE.

### Dificultades encontradas

- Ordenar tantos cables en tan poco espacio fue complicado.
- Había que pegar los componentes con cuidado para que no se movieran ni se soltaran las conexiones.
- Al pegar los componentes, varios cables quedaron muy juntos y se volvió difícil saber a qué pin iba cada uno.
- En las pruebas, la cámara a veces se trababa, aunque sí funcionaba.

### Soluciones implementadas

- Fuimos acomodando los cables por partes, revisando hacia dónde iba cada uno antes de pegar los componentes.
- Pegamos los componentes poco a poco para que quedaran firmes.
- Cuando no estábamos seguras de una conexión, seguíamos el cable hasta su pin para no confundirlo.
- Alejandra se llevó el prototipo para ordenar mejor los cables, de forma que se identifique de qué pin sale cada uno, y para revisar por qué la cámara se trababa.

### Decisiones técnicas

- Fijar los componentes a los lentes para que no se movieran durante las pruebas.
- Acomodar los cables de forma que ocuparan el menor espacio posible, sin perder de vista a qué pin iba cada uno.

### Pruebas efectuadas

- Con todo ya montado, hicimos pruebas para comprobar que los componentes siguieran funcionando después de pegarlos y acomodar los cables.
- El prototipo funcionó, pero notamos que la cámara a veces se quedaba trabada.

### Aprendizajes obtenidos

- El orden de los cables es importante para que el prototipo sea más resistente y más fácil de revisar si algo falla.
- Terminar un prototipo físico requiere paciencia y trabajo en equipo.
- Buscar fuentes para el marco teórico me ayudó a entender mejor cómo funcionan algunos de los componentes que usamos.

### Próximos pasos

- Ordenar mejor los cables y revisar por qué la cámara se traba.
- Seguir probando el prototipo montado en diferentes situaciones.
- Documentar los resultados de las pruebas para el artículo.

## Semana 7 – Día 9 (15/11/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza (trabajo individual)

### Actividades realizadas

- Individual: dediqué el día a avanzar en el artículo de investigación del proyecto.
- Revisé la guía del profesor y la rúbrica del artículo para comprobar qué secciones se piden como mínimo y cuáles nos faltaban.
- Revisé y corregí algunas partes del artículo para que coincidieran con el prototipo final.
- Revisé que las citas y las referencias siguieran el formato IEEE.
- Actualicé el diagrama de arquitectura en draw.io con los cambios que propuso el equipo.
- Antes de subir mi bitácora, la comparé con las de mis compañeras para que lo que contamos de cada reunión coincidiera.

### Avances

- Quedó claro qué le falta al artículo según la guía: la justificación, el proceso de desarrollo dentro de la metodología, los resultados, la discusión y las conclusiones.
- Varias secciones del artículo quedaron corregidas.
- Las referencias quedaron más ordenadas según el formato IEEE.
- El diagrama de arquitectura quedó actualizado.

### Dificultades encontradas

- Como el artículo lo escribimos entre varias, algunas referencias no quedaban en orden.
- Algunas partes del borrador todavía hablaban de cosas que al final no se usaron, como la vibración y la batería.

### Soluciones implementadas

- Ajusté las referencias para que quedaran en orden.
- Revisé cada sección comparándola con el prototipo que de verdad armamos y propuse los cambios necesarios.

### Decisiones técnicas

- Seguir el formato IEEE: referencias numeradas en el orden en que aparecen en el texto.
- Dejar las citas en inglés tal como están en el original y aclarar con una nota cuáles citas en español son traducción propia.

### Pruebas efectuadas

- Este día no hubo pruebas del prototipo; revisé el artículo comparándolo con la guía y la rúbrica del profesor.

### Aprendizajes obtenidos

- Comparar el artículo con el prototipo final me ayudó a encontrar partes que ya no coincidían con lo que hicimos.
- Revisar el artículo entre todas ayuda a que quede coherente, aunque cada una haya escrito partes distintas.

### Próximos pasos

- Escribir la justificación y el alcance y limitaciones.
- Completar los resultados, la discusión y las conclusiones.
- Renumerar todas las referencias cuando el artículo esté completo.

## Semana 8 – Día 10 (17/11/2026)

### Integrantes presentes

- Dana Paola Aguirre Espinoza
- Alejandra Quintanilla Muñiz
- Joan Eras

### Actividades realizadas

- Con los lentes ya terminados, Alejandra y yo hicimos pruebas en la universidad para reunir la mayor cantidad de resultados posibles para el artículo.
- Recorrimos distintos espacios del campus llevando los lentes y apuntamos la cámara hacia personas, objetos de uso cotidiano y figuras de animales.
- Para que los dispositivos pudieran comunicarse, conectamos todo a una red compartida desde la laptop, porque con la red de la universidad no funciona.
- En la página web revisamos lo que reconocía YOLO, con el nombre de cada objeto y su nivel de confianza, y tomamos capturas de los resultados.
- Grabamos videos de algunos recorridos, como en un pasillo y en un baño de la universidad, mientras la página mostraba en vivo lo que veía la cámara.
- Al final exportamos todas las detecciones de la base de datos a un archivo CSV.
- Alejandra y yo seguimos trabajando en el artículo hasta terminarlo, agregando los resultados de las pruebas.
- Al terminar, Alejandra se llevó el prototipo para hacer las mediciones del sensor.

### Avances

- Obtuvimos los datos necesarios para la parte de resultados del artículo.
- La base de datos guardó 395 detecciones de la sesión: obstáculos, personas y animales.
- Comprobamos que el prototipo terminado funciona en lugares reales y no solo en la mesa de trabajo.
- El artículo quedó terminado con los resultados de las pruebas.

### Dificultades encontradas

- La red de la universidad sigue sin dejar que los dispositivos se comuniquen con el servidor.
- No teníamos animales reales para probar, así que solo pudimos usar figuras de juguete.
- YOLO confundió una máquina expendedora con un refrigerador.

### Soluciones implementadas

- Usamos el internet compartido desde la laptop durante todas las pruebas.
- Usamos figuras de un caballo y una vaca para comprobar que el sistema reconociera animales.
- Tomamos capturas de la página en cada prueba, ya que la imagen de la cámara se ve en vivo y no se guarda.

### Decisiones técnicas

- Usar las capturas, el CSV y los videos como evidencia de las pruebas para el artículo.
- Registrar en una tabla el objeto, la clase que asignó YOLO y su nivel de confianza.

### Pruebas efectuadas

- Pruebas de reconocimiento con personas, objetos (mesa, bicicleta, lavamanos, microondas, botella, mouse, planta) y figuras de animales.
- Pruebas de recorrido llevando los lentes, revisando al mismo tiempo la página web.
- Revisión de los registros guardados en la base de datos y exportación a CSV.

### Aprendizajes obtenidos

- La cámara puede reconocer a una persona aunque el sensor todavía no la detecte; en esos casos la página la muestra como "Lejos".
- YOLO da una confianza más baja cuando los objetos son pequeños o salen cortados en la imagen.
- Probar en lugares reales muestra cosas que no se ven en las pruebas de mesa.

### Próximos pasos

- Hacer los últimos ajustes al artículo y entregarlo.
- Montar el stand y presentar el proyecto final.
