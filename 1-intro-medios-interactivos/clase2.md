# clase2

lunes 04 septiembre 2023

dibujo programático

hoy aprenderemos:

- sistemas numéricos
- convenciones en programación
- funciones básicas de Processing: setup() y draw()
- tamaño y color del lienzo: size() y background()
- figuras geométricas: point(), line(), ellipse() y rect()
- escala de grises, color RGB y transparencia alphas
- variables y scope
- arreglos
- bucles for()
- funciones y argumentos
- exportar a archivos de imagen

## sistemas numéricos

- decimal: base 10
- binario: base 2
- hexadecimal: base 16

un número como 123,456 en decimal

lo descomponemos como 1*$10^{2}$ + 2*$10^{1}$ + 3*$10^{0}$ + 4*$10^{-1}$ + 5*$10^{-2}$ + 6*$10^{-3}$

| base 10 | base 2 | base 16 |
| ------- | ------ | ------- |
| 00      | 00000  | 00      |
| 01      | 00001  | 01      |
| 02      | 00010  | 02      |
| 03      | 00011  | 03      |
| 04      | 00100  | 04      |
| 05      | 00101  | 05      |
| 06      | 00110  | 06      |
| 07      | 00110  | 07      |
| 08      | 01000  | 08      |
| 09      | 01001  | 09      |
| 10      | 01010  | 0A      |
| 11      | 01011  | 0B      |
| 12      | 01100  | 0C      |
| 13      | 01101  | 0D      |
| 14      | 01110  | 0E      |
| 15      | 01110  | 0F      |
| 16      | 10000  | 10      |
| 17      | 10001  | 11      |
| 18      | 10010  | 12      |
| 19      | 10011  | 13      |
| 20      | 10100  | 14      |
| 21      | 10101  | 15      |
| 22      | 10110  | 16      |
| 23      | 10111  | 17      |

## convenciones en programación

- en programación, contamos desde 0, por ejemplo si hay 3 elementos, son 0, 1, 2.

- en este curso no usaremos espacios para nombres de carpetas, archivos o variables, en vez de eso, usaremos distintas estrategias:

  - usaremos guiones "-", guiones bajos "\_" para nuestros archivos y carpetas.
  - las variables de nuestro código estarán escritas en notación camello: donde escribimos todas las palabras juntas sin espacios, la primera es todo con minúsculas, y después cada palabra adicional empieza con mayúscula, por ejemplo estaPalabraEstaEscritaEnNotacionCamello.

- generalmente los espacios entre palabras importan, pero no importa cuánto espacio hay, el computador los omite, pero son muy importantes para que nuestro código sea legible y esté formateado de una manera legible.

## descargar Processing y nuestro primer bosquejo

descargar Processing desde https://processing.org/

en septiembre 2023 está disponible la versión 4.3.0.

copien este bosquejo y péguenlo en la ventana de Processing.

```processing
void setup() {
  size(500, 500);
}

void draw() {
  ellipse(250, 250, 100, 100);
}
```

## condiciones iniciales y de refresco con setup() y draw()

las funciones más centrales que usaremos en Processing son setup() y draw().

setup() corre una vez y al principio, y la usaremos para definir las condiciones iniciales del bosquejo, como el tamaño de nuestro lienzo.

draw() corre después de setup(), en bucle y hasta que cerremos la aplicación. sirve para refrescar el bosquejo, para hacer animaciones cuadro a cuadro.

setup() y draw() son funciones, que son colecciones de instrucciones de código que siguen la siguiente sintaxis cuando son declaradas:

```processing
tipo nombre(arg0, arg1, ...) {
  // linea
  // otra linea
  // etc
}
```

donde tipo nos indica el tipo de dato que la función emite tras finalizar, puede ser número, palabra, o nada "void".

en nuestros códigos de este curso siempre declararemos las funciones setup() y draw(), que son llamadas y corridas por Processing de forma automática.

## tamaño y color del lienzo con size() y background()

en Processing trabajaremos con un lienzo, y ese lienzo necesita ser creado con la función size() o tamaño en español, con esta sintaxis.

a diferencia de setup() y draw(), size(ancho, alto) necesita dos argumentos numéricos que especifican el tamaño en pixeles. además no necesitamos declararlos, solamente usarlas.

- size(ancho, alto): crea una ventana con el ancho y alto determinado en pixeles.

para pintar el lienzo de un color, usaremos la función background(color), donde color podrá tomar distintas formas:

- si usamos 1 número, será interpretado como escala de grises.
- si usamos 2 números, será interpretado como escala de grises y transparencia.
- si usamos 3 números, serán interpretados como canales RGB (rojo, verde, azul).
- si usamos 4 números, serán interpretados como canales RGB y transparencia.

donde:

- en escala de grises: 0 es negro, 255 es blanco.
- transparencia: 0 es invisible, 255 es sólido.
- RGB: 0 es nada de ese color, 255 es todo de ese color.

estos valores ocurren porque Processing entiende color como un valor de 8-bits, valores entre 0 y 255. esta escala se puede cambiar con la función colorMode().

## puntos y líneas: point() y line()

- point(posX, posY): crea un punto en la posición (posX, posY).

- line(posX1, posY1, posX2, posY2): crea una línea entre los puntos (posX1, posY1) y pos(X2, Y2).

## figuras geométricas básicas: ellipse() y rect()

- rect(posX, posY, ancho, alto): crea un rectángulo en la posición (posX, posY) y con las dimensiones ancho y alto medidas en pixeles. por defecto, la posición define la esquina superior izquierda.

- ellipse(posX, posY, ancho, alto): crea una elipse en la posición (posX, posY) y con las dimensiones ancho y alto medidas en pixeles. por defecto, la posición define el centro de la elipse.

## bordes y rellenos de figuras: stroke() y fill()

la función stroke(color) permite elegir los bordes de los trazos de las figuras. si no quieres tener stroke, puedes usar la función noStroke().

la función fill(color) permite colorear los rellenos de las figuras. si no quieres tener un relleno, puedes usar la función noFill().

los puntos y líneas están en 2D y no tienen relleno, solamente borde, por lo que usar la función noStroke() los hace invisibles, y la función noFill() no tiene efecto.

## condicionales if / else

podemos hacer que nuestro código tenga bifurcaciones para distintos comportamientos, al usar condicionales, que en código tienen esta sintaxis.

```processing
if (condicion0) {
// este código corre si la condicion0 es verdadera
}
else if (condicion1) {
// este código corre si la condición0 es falsa, y ademas la condicion1 es verdadera
}
else {
// este código corre si la condicion0 y la condicion1 son falsas
}
```

siempre necesitamos un "if" con una condición que si es cierta, hace que el código dentro corra. si queremos comparar más condiciones, podemos usar condiciones adicionales en cascada con "else if", tantas como queramos.

si queremos tener un código que solamente corra si todas las condiciones son falsas, al final escribimos un "else".

conceptos importantes:

- Processing 4 y Java
- funciones setup() y draw()
- funciones size() y background()
- figuras ellipse() y rect()
- color en Processing

## dibujo de 3 elipses

en el ejemplo asociado dibujamos 3 elipses, cada una con un color de relleno distinto, y una posición distinta.

## dibujo de 3 elipses con variables

las variables nos permiten tener valores que podemos cambiar.

también nos permiten generar reacciones en cascada en nuestro código.

## variables y scope

podemos declarar las variables en 2 lugares distintos:

- variables globales: existen fuera de todo lobque de código, y todo el resto del código tiene acceso a estas variables.
- variables locales: solamente existen dentro del bloque de código que las contiene, por ejemplo, dentro de la función setup().

## dibujo de 3 elipses con arreglos

un arreglo nos permite crear un grupo variables que comparten un nombre.

esto es muy importante para poder hacer iteraciones, y poder rápidamente hacer lo que los computadores hacen muy bien: repetir.

## iteración con bucles for

ya vimos un bucle en Processing, que es la función draw(), que Processing se encargar de correrla periódicamente para animar nuestros dibujos.

un clásico de programación es el llamado bucle for(), que se construye de la siguiente manera en Java:

```processing
for (int i = 0; i < 4; i++) {
  println(i);
}
```

sabemos que las líneas de código en Processing terminan en punto y coma ";", y dentro de los paréntesis del bucle, tenemos 2, que delimitan las 3 distintas pequeńas líneas de código que viven ahí:

1. declaración de variable de iteración: int i = 0
2. condición de continuar dentro del bucle: i < 4
3. refresco que ocurre cada vez que termina el bucle: i++

como es muy usual aumentar o disminuir en 1 el valor de un número entero, en los lenguajes de programación hay atajos para esto, que son equivalentes, como:

- i = i + 1; equivale a i++;
- i = i - 1; equivale a i--;

## declarar funciones

cuando escribimos suficiente código que queremos reutilizar, podemos encapsularlo en nuestra propia función, que podemos correr en cualquier momento, y con distintos argumentos para lograr distintos resultados.

```processing
void dibujarLineaAleatoria(float posXMax, float posYMax, float maxAncho) {
    stroke(random(maxAncho));
    line(random(posXMax), random(posYMax));
}
```

la primera palabra en este ejemplo es void ( del inglés "vacío"), que indica que la función tras correr, no arroja ningún resultado. los otros tipos posibles con int, float, String, char, y cualquier otro tipo de datos que tenga el lenguaje.

después usamos una palabra como "dibujarLineaAleatoria", que nos permite darle un nombre reconocible a la función, para poder usarla en el código cuando queramos.

después entre paréntesis(), podemos opcionalmente agregar argumentos. si lo hacemos, debemos declarar su tipo y nombre, con el que podremos referirnos dentro de la función.

luego dentro de las llaves {} podemos escribir el código que correrá cada vez que llamemos a nuestra función.

## exportar nuestro lienzo

Processing siempre tiene un estado actual del lienzo que podemos grabar.

para eso, recomendamos usar la función saveFrame(), que toma el contenido actual del lienzo y lo graba con el nombre que tenemos.

podemos hacer que el resultado de esto sea una imagen .jpg u otro formato, con un nombre estático. también podemos usar gatos #### que al exportar son reemplazados con el número actual del cuadro del lienzo, permitiéndonos así generar secuencias de imágenes.

## estrategias de dibujo programático

podemos dibujar con distintos enfoques, por ejemplo, dejando que el tiempo transcurra, o creando servidores web que nos permitan leer tendencias en Twitter que controlen nuestro dibujo, o incluso sensores y algoritmos de inteligencia artificial que detecten nuestra pose y con eso dibujar.

antes de tomar ese rumbo, cuando estamos aprendiendo, es bueno usar los rudimentos de programación interactive que nos dan los llamados HID, por sus siglas en inglés de Human Interface Device o dispositivos de interfaz humana, que en nuestro caso serán nuestro ratón y teclado.

con nuestro ratón podemos:

- detectar click en distintos botones
- detectar velocidad o ritmo entre clicks
- detectar posición del cursor en XY, quizás Z?

con nuestro teclado podemos:

- detectar el presionar de distintas teclas
- detectar secuencias de teclas en el tiempo
- detectar rapidez entre repeticiones o patrones de teclas
- detectar mayúsculas o minúsculas

## subir nuestro propio código a GitHub

hagamos inicio de sesión en GitHub.

vayamos a la web del repositorio de la clase.

hay 3 opciones:

1. están atrás ("behind") del repositorio, o sea que han habido cambios en el original, que su repositorio todavía no tiene. Para aceptar esos cambios, hacemos click en "Fetch upstream", y en el botón verde "Fetch and merge". Tras esto, el repo dirá "This branch is up to date with sinestesiacc/2023-programa-medios-interactivos:main."
2. ustedes están adelante, y pueden contribuir al repositorio, con el botón "Contribute" que les permite crear una "pull request", para proponer al repo de la clase a que incorpore sus cambios.
3. están exactamente igual que el repo original, y dirá "up to date", o sea, no estarán ni adelante ni atrás :)

## bibliografía

- - https://processing.org/
  - https://processing.org/reference/
  - https://processing.org/tutorials/
  - https://processing.org/examples/
  - https://processing.org/books/
- https://www.youtube.com/c/TheCodingTrain

