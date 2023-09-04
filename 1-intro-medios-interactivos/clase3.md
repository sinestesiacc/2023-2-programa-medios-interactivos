# clase3

miércoles 06 septiembre 2023

modificación de imágenes y tipografía

hoy aprenderemos:

- cargar imágenes
- procesar imágenes
- texto en Processing
- tamaño de texto
- tipografías

## repaso clase pasada

- variables y scope
- arreglos
- bucles for()
- funciones y argumentos
- exportar a archivos de imagen

## cargar imágenes en Processing

usaremos el tipo de variable PImage, que nos permite almacenar imágenes.

las variables PImage se declaran así:

```processing
PImage imagen;
```

y tras declararla, podemos asignarle un valor, con la ayuda de la función loadImage(), que nos permite leer un archivo dentro de nuestro directorio.

```processing
imagen = loadImage("hola.jpg");
```

el archivo tiene que estar dentro de la carpeta data/ en tu bosquejo de Processing, o también puedes usar la herramienta de cargar imagen desde el menú "Sketch => Add file..."

## filtros de imagen

podemos usar la función tint() para camagregar un filtro de color y/o transparencia a nuestras imágenes.

## arreglo pixels() y loadPixels()

cuando pensamos en pixeles en el lienzo, tenemos un arreglo de dos dimensiones (x, y), donde cada coordenada es un pixel que almacenar un color.

con la función loadPixels(), podemos actualizar un arreglo de Processing llamado pixels[], donde cargamos el contenido del lienzo a un arreglo pero unidimensional, que equivale a tomar la imagen fila por fila, y disponerlas lado a lado, desde la esquina superior izquierda, hasta la esquina inferior derecha.

con esto podemos pasar de coordenada (x,y) a la correspondiente ubicación en pixels haciendo el cálculo:

```
int ubicacion = x + y * ancho;
```

## puntillismo

en Processing podemos tener muchas imágenes cargadas en nuestra memoria.

podemos tener un lienzo, dibujar en él, y actualizarlo cuadro a cuadro, y podemos cargar estos pixeles en el arreglo pixels() y modificarlos, combinando funciones como loadPixels y updatePixels().

también tenemos imágenes que podemos cargar desde el disco duro, como PImage y que podemos poner directamente en el lienzo con la función image(), o podemos preprocesarla y según eso pintar el lienzo.

para hacer puntillismo en el ejemplo de este capítulo, cargaremos la imagen desde el disco duro, tomaremos una coordenada aleatoria (x, y) en el lienzo, leeremos su color, y según eso dibujaremos una elipse en esa posición con ese color, para progresivamente y aleatoriamente dibujar la imagen a partir de estos puntos.

## traslación y rotación en Processing

como sabemos, en Processing contamos nuestro origen (0, 0) en la esquina superior izquierda, pero eso se puede modificar con la función translate(x, y), que nos permite modificar el origen.

nota: cada vez que nuestro bucle draw() termina, la traslación se anula, entonces no es acumulativa por cuadro.

## repetir imágenes

podemos escribir nuestras propias funciones en Processing, para repetir rutinas y variables, incluyendo imágenes.

en el ejemplo correspondiente de repetir imágenes, creamos nuestra propia función, usando a su vez las funciones translate(), rotate(), pushMatrix() y popMatrix() para dibujar la misma imagen varias veces en posiciones y ángulos aleatorios.

## texto en Processing

la función principal que usaremos para dibujar texto en nuestro lienzo es text(), que podemos llamar con estos 3 argumentos:

- string con el texto a escribir
- número para la posición en eje X
- número para la posición en eje Y

este texto es por defecto de color blanco, con borde negro, con una tipografía genérica sans-serif, con cierto tamaño y cierto alineamiento que podemos modificar.

## tamaño de texto (15 min)

podemos controlar el tamaño del texto con la función textSize(), que acepta un parámetro de número para especificar el tamaño.

otra opción de modificar tamaño, es no del texto en sí, pero de la caja contenedora donde se dibuja, lo que se puede hacer con text() y 2 parámetros adicionales para:

- tamaño caja contenedora en eje X
- tamaño caja contenedora en eje Y

## tipografías

nuestro computador tiene distintas tipografías y las podemos cargar a Processing, acondicionar para ser usadas en distintos tamaños, grabarlas en nuestra carpeta data/ y luego usarlas para escribir.

para lograr cargar una fuente en un tamaño, vamos al menú "Tools => Create Font..." y ahí escogemos alguna de las tipografías y el tamaño.

recomendamos exportar un archivo por cada tamaño que planeas, para tener una mejor resolución y calidad de la imagen.

recuerda siempre revisar las licencias de las tipografías que utilizas, descargarlas y respaldarlas, y dar crédito.

cada vez que presionamos una tecla en nuestro teclado y aparece una letra, es porque alguien diseño esa letra y la podemos usar, y nunca debemos tomar eso por sentado.

## bibliografía

- https://processing.org/reference/PImage.html
  https://processing.org/reference/tint_.html
  https://processing.org/reference/loadPixels_.html
- https://www.design-research.be/by-womxn/
- http://collletttivo.it/
- https://processing.org/examples/alphamask.html
- https://processing.org/examples/backgroundimage.html
- https://processing.org/examples/createimage.html
- https://processing.org/examples/loaddisplayimage.html
- https://processing.org/examples/transparency.html
