/* Figura 7.12: fig07_12.c
Intenta modificar un dato a través de
un apuntador no constante a un dato constante. */
#include <stdio.h>
void f( const int *ptrX ); /* prototipo */

int main()
{
 int y; /* define y */

 f( &y ); /* f intenta una modificación ilegal */

 return 0; /* indica terminación exitosa */

 } /* fin de main */

 /* no se puede utilizar ptrX para modificar
 el valor de la variable a la cual apunta */
 void f( const int *ptrX )
  {
   *ptrX = 100; /* error: no se puede modificar un objeto const */
} /* fin de la función f*/
