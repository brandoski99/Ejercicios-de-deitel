/* Figura 7.6: fig07_06.c
02 Eleva al cubo una variable mediante una llamada por valor */
#include <stdio.h>
 int cuboPorValor( int n ); /* prototipo */
int main()
 {
 int numero = 5; /* inicializa numero */

 printf( "El valor original de numero es %d", numero );
 /* pasa numero por valor a cuboPorValor */
  numero = cuboPorValor( numero );

 printf( "\nEl nuevo valor de numero es %d\n", numero );

   return 0; /* indica terminaci�n exitosa */

 } /* fin de main */

 /* calcula y devuelve el cubo de un argumento entero */
 int cuboPorValor( int n )
 {
 return n * n * n; /* eleva al cubo la variable local n y devuelve
el resultado */

 } /* fin de la funci�n cuboPorValor */
