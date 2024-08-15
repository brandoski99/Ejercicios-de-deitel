/* Figura 7.16: fig07_16.c
02 Cuando el operador sizeof se utiliza en un nombre de arreglo,
03 éste devuelve el número de bytes en el arreglo. */
 #include <stdio.h>

 size_t obtieneTamanio( float *ptr ); /* prototipo */

 int main()
 {
 float arreglo[ 20 ]; /* crea arreglo */

 printf( "El numero de bytes en el arreglo es %d"
        "\nEl numero de bytes devueltos por obtieneTamanio es %d\n",
 sizeof( arreglo ), obtieneTamanio( arreglo ) );

 return 0; /* indica terminación exitosa */

 } /* fin de main */

 /* devuelve el tamaño de ptr */
 size_t obtieneTamanio( float *ptr )
 {
    return sizeof( ptr );
 } /* fin de la función obtieneTamanio */
