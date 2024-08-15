/* Figura 7.20: fig07_20.
c Uso de las notaciones de subíndices y de apuntadores con arreglos */

 #include <stdio.h>

 int main()
 {
 int b[] = { 10, 20, 30, 40 }; /* inicializa el arreglo b */
 int *ptrB = b; /* establece ptrB para que apunte
al arreglo b */
 int i; /* contador */
 int desplazamiento; /* contador */

 /* muestra el arreglo b con la notación de subíndices */
 printf( "Arreglo b impreso con:\nNotacion de subindices de arreglos\n" );

 /* ciclo a través del arreglo b*/
 for ( i = 0; i < 4; i++ ) {
 printf( "b[ %d ] = %d\n", i, b[ i ] );
 } /* fin de for */

 /* muestra el arreglo b mediante el uso del nombre del arreglo y
notación apuntador/desplazamiento */

 printf( "\nNotacion apuntador/desplazamiento donde\n"
 "el apuntador es el nombre del arreglo\n" );

 /* ciclo a través del arreglo b */
 for ( desplazamiento = 0; desplazamiento < 4; desplazamiento++ ) {
 printf( "*( b + %d ) = %d\n", desplazamiento, *( b + desplazamiento ) );
 } /* fin de for */

 /* muestra el arreglo b mediante el uso de ptrB y notación de subíndices
de arreglos */
 printf( "\nNotacion de subindices de arreglos\n" );

 /* ciclo a través del arreglo b */
 for ( i = 0; i < 4; i++ ) {
 printf( "ptrB[ %d ] = %d\n", i, ptrB[ i ] );
 } /* fin de for */

 /* muestra el arreglo b mediante el uso de ptrB y notación de
apuntador/desplazamiento */
 printf( "\nNotacion apuntador desplazamiento\n" );

 /* ciclo a través del arreglo b */
 for ( desplazamiento = 0; desplazamiento < 4; desplazamiento++ ) {
 printf( "*( ptrB + %d ) = %d\n", desplazamiento, *( ptrB + desplazamiento ) );
 } /* fin de for */

 return 0; /* indica terminación exitosa */

 } /* fin de main */
