Algoritmos y Estructuras de Datos II 

Tarea Extraclase I

Por Fabiana Maria Moreno Castrillo

Generator: Es una herramienta en C++ para generar archivos binarios grandes con una cantidad predeterminada de números enteros aleatorios.

Uso: 

-Se compila con: g++ -o generator generator.cpp

-Se ejecuta con: ./generator --size <SIZE> --output <OUTPUT FILE PATH>

Recibe estos argumentos: 

1. --size <SIZE>: Tamaño del archivo a generar:


    SMALL: 512 MB
   
    MEDIUM: 1 GB
   
    LARGE: 2 GB
   

2. --output <OUTPUT FILE PATH>: Ruta del archivo binario de salida.

Ejemplos: 

Para generar un archivo de 512 MB llamado myfile.bin: ./generator --size SMALL --output myfile.bin

Para generar un archivo de 1 GB llamado largefile.bin: ./generator --size MEDIUM --output largefile.bin

Para generar un archivo de 2 GB llamado hugefile.bin: ./generator --size LARGE --output hugefile.bin



