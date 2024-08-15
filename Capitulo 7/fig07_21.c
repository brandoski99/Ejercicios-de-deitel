#include <stdio.h>


void copia1( char *s1, const char *s2 ); /* prototipo */

void copia2( char *s1, const char *s2 ); /* prototipo */


int main()

{

char cadena1[ 10 ]; /* crea el arreglo cadena1 */

char *cadena2 = "Hola"; /* crea un apuntador a una cadena */

char cadena3[ 10 ]; /* crea el arreglo cadena3 */

char cadena4[] = "Adios"; /* crea un apuntador a una cadena */


copia1( cadena1, cadena2 );

printf( "cadena1 = %s\n", cadena1 );


copia2( cadena3, cadena4 );

printf( "cadena3 = %s\n", cadena3 );


return 0; /* indica terminación exitosa */


} /* fin de main */


/* copia s2 en s1 con el uso de la notación de arreglos */

void copia1( char *s1, const char *s2 )

{

int i; /* contador */


/* realiza el ciclo a través de la cadena */

for ( i = 0; ( s1[ i ] = s2[ i ] ) != '\0'; i++ ) {

; /* no realiza tarea alguna en el cuerpo */

} /* fin de for */


} /* fin de la función copia1 */


/* copia s2 en s1 con el uso de la notación de apuntadores */

void copia2( char *s1, const char *s2 )

{

/* realiza el ciclo a través de las cadenas */

for ( ; ( *s1 = *s2 ) != '\0'; s1++, s2++ ) {

; /* no realiza tarea alguna en el cuerpo */

} /* fin de for */


} /* fin de la función copia2 */
