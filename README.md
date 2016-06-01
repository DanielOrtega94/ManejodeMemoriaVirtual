# ManejodeMemoriaVirtual

### Objetivos
  * Mejorar compresión en mecanismos básicos de administración de memoria virtual.
  * Desarrollar habilidades para construir software de prueba de concepto.
  * Estimular trabajo en equipo.

### Descripción del problema
El proyecto consiste en simular el proceso de memoria virtual con el uso de TLBs de datos e instrucciones y paginación de un nivel. Note que este sistema no incluye uso de caches, sino que está orientado sólo a ver los fallos de página en la TLB y tabla de páginas para traducción de direcciones virtuales a físicas.

Se adjunta el archivo con la traza. Cada entrada en el archivo tiene un carácter indicando “i” para decir que es una dirección virtual asociada a una “instrucción” (lectura de una instrucción a ejecutar desde memoria), o una “l” indicando un “load” (lectura a memoria) y una “s” para indicar un “store“ (escritura a memoria). El ”l“ y ”s“ involucra acceso a datos y ”i“ involucra acceso a código a ejecutar.

### Requerimientos

* Para la implementación considere direcciones virtuales de 32 bits, un tamaño de página de memoria (en MB) y tamaño (en KB) ingresado por teclado.
* Considere valores posibles para la memoria 32MB, 64MB y 128MB y tamaño
de página de 4, 8, 16KB.
* Considere 2 TLBs, una para datos y una para instrucciones. Cada TLB
posse 4 entradas y es completamente asociativa.
* Implemente algoritmo LRU como algoritmo de reemplazamiento en las TLBs
y tabla de páginas.
* La simulación debe entregar las tasas de fallos en la TLB de instrucciones, de datos y tabla de páginas. Además debe proporcionar el número de reemplazos realizados en cada una de las TLBs y la tabla de páginas.

### Datos

Para realizar su proyecto considere el archivo de traza de ejecución que se adjunta con el proyecto.

### Metodología

Los estudiantes pueden formar grupos de a lo más 2 estudiantes. Cada integrante debe participar en el desarrollo del proyecto activamente.

### Evaluación

La evaluación del proyecto será en 3 partes cuyos porcentajes estan estipulados a continuación:
* Correctitud de la solución: cumpliendo todas las exigencias pedidas. Se probarán varios casos de entrada los cuales determinar an en parte su nota. También se analizará el código. (35 %)
* Informe escrito: el proyecto debe estar documentado en un informe de no más de 4 páginas, en las cuales expresen en palabras, pseudocódigo o diagrama de flujo lo que hace el algoritmo que implementaron en su solución, y un análisis de resultados. (30 %)
* Interrogación grupal: habrá también una interrogación grupal. El objetivo de esta interrogación es que quede clara la autoría de las soluciones expuestas. Cada integrante del grupo debe conocer el funcionamiento de las soluciones expuestas y de los programas.(35 %)

### Términos y condiciones

Si se descubren prácticas deshonestas de cualquier tipo, el grupo y todos los involucrados, serán calificados con la nota mínima.
