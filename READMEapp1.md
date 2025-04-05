Tarea 1, App 1 Lenguajes y Paradigmas de la Programación Sección 2
Profesor Justo Vargas

Estudiantes: 
1. José Vicente Cornejo josevcornejo@alumnos.uai.cl
2. Ignacio Arau iarau@alumnos.uai.cl
3. Maximiliano Rojas maximrojas@alumnos.uai.cl

Explicación por archivo:

1. main.c: Cara principal de la aplicación. Se encarga de ejecutar todas las funciones presentes en todos los archivos del repertorio. Es la que recibe la data de los demás archivos


3. order.h: sirve para declarar las funciones, o sea las firmas de estas, que van a leer el archivo csv y la estructura de todos los pedidos de la pizzería


4. order.c: implementa las funciones ya declaradas en order.h


5. metrics.h: sirve para declarar las funciones, o sea las firmas de estas, para calcular todas las metricas en metrics.c


6. metrics.c: calcula las métricas gracias a lo ya conocido en metrics.h


8. makefile: usa todos los archivos ya creados. primero mergea todos los archivos en main.o, metrics.o order.o, respectivamente. De esta forma va a enlazar todo el programa, creando un .exe que sea ejecutable y contenga todo lo necesario para la correcta realización del programa


Uso de AI's para la evaluación: 
En este trabajo se usaron intensivamente diversas inteligencias artificiales, tales son ChatGPT, Perplexity y Gemini. Su uso fue fundamental para crear código y comprenderlo. 

Razones de diseño:
Los ingredientes se almacenan usando struct order, esto debido a que se requiere simpleza y no gran sofisticación.
En cuanto al parseo CSV se utiliza el modelo más simple igualmente, esto debido a que es una tarea relativamente "pequeña". Por ende, la eficacia es fundamental para este caso.


Preguntas:
¿Qué fue lo más complejo o interesante de la tarea?
Lo más difícil fue comenzar con la tarea, no sabíamos cómo empezar, así que le hicimos preguntas a la IA sobre el trabajo y sobre lo que se requería que resolvieramos.
Una vez ya se entendió el raciocinio necesario para atacar el problema de la pizzería, los problemas fueron la no-comprensión de por qué habían errores relacionados con las firmas y con funciones de los archivos que se suponen que estaban "bien".

¿Cómo enfrentaron los errores, pruebas y debugging?
Nos enfrentamos a miles de errores y problemas desde un principio debido a nuestra falta de experiencia escribiendo código.
Las pruebas fueron realizadas en VSCode, cambiando firmas constantemente y no entendiendo por qué ocurren errores.

¿Qué lecciones aprendieron al implementar en C este tipo de lectura de archivos y cálculos de métricas?
Se aprendió la complejidad del lenguaje y la utilidad de las firmas para reconocer cada subject y poder diferenciarlos unos de otros.
Además, se aprendió de la gran utilidad de los archivos CSV, ya que al ser archivos tan simples pueden contener una gran cantidad de información, lo cual lleva a una gran utilidad para poder acceder a data de forma sencilla y liviana en espacio, ya que son archivos simples extremadamentes convenientes.
