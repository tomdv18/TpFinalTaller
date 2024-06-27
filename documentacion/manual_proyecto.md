# MANUAL DEL PROYECTO
## Distribución
Originalmente, distribuimos al equipo en dos subequipos: uno encargado de la parte del cliente, desde su código hasta su interfaz visual y sonidos, mientras que el otro equipo se encargó del lado del servidor, incluyendo desde el manejo de las conexiones y las partidas, hasta el desarrollo y balanceo del juego, así como también del testeo de las partes del mismo.

## Partes problemáticas
### Código
En cuanto al código, la mayor parte de problemas se dio al ponernos de acuerdo con el protocolo de comunicación del cliente-servidor. Fue una parte que tuvo constantes cambios debido a que cada agregado en cualquiera de las dos partes, ya sea un nuevo enemigo, un nuevo mapa, la posibilidad de elegir distintos personajes o partidas, incluía una modificación en el protocolo de comunicación.

### Integración
Surgieron algunos inconvenientes debidos a las diferencias de sistemas operativos de los integrantes. Esto llevó a conflictos como el no procesamiento de archivos de audio por su formato o la no visualización de imágenes si no eran de un formato específico; cuestión que, una vez solucionada, volvió a aparecer a la hora de crear el Vagrantfile.

## Errores conocidos
#### Vagrant
Para correr el juego utilizando Vagrant, se recomienda fuertemente utilizar la branch de este repositorio llamada del mismo nombre.
Existe un error en las dependencias del Vagrantfile que no permite hacer testing del proyecto, ni reproduce sonido al utilizar el juego, pero el resto de características del mismo funcionan con normalidad.

## ¿Qué cambiaríamos?
En normas generales, sentimos que, pese a los inconvenientes normales surgidos de un trabajo grupal, pudimos lograr con nuestro objetivo, desarrollando todas las features propuestas e incluso llegando a agregar extras.

Perdimos mucho tiempo en refactorizar el código. Tal vez planificarlo de antemano, como para tener el código más prolijo en una primera instancia, nos hubiese venido bien.

Si bien el uso de Github como sistema de control de versiones fue fundamental en el proyecto, tuvimos poca comunicación y eso hizo que, en ciertas circunstancias, pisáramos trabajo realizado por otro integrante, lo que nos llevó a hacer doblemente el trabajo en ciertas ocasiones. Una herramienta de gestión de proyectos como Trello podría habernos solucionado este inconveniente.

Por último, los problemas de integración mencionados arriba hicieron que tuviésemos muchos conflictos que generaron problemas difíciles de resolver, puesto que no estaban bajo nuestro control. Utilizar Docker o incluso Vagrant desde un comienzo pudo habernos ahorrado este inconveniente.
