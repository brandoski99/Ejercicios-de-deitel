/* Figura 7.13: fig07_13.c
Intenta modificar un apuntador constante a un dato no constante */
#include <stdio.h>

 int main()
{
 int x; /* define x */
 int y; /* define y */

/* ptr es un apuntador constante a un entero que se puede modificar
a través de ptr, pero ptr siempre apunta a la misma ubicación
de memoria */
 int * const ptr = &x;

 *ptr = 7; /* permitido: *ptr no es const */
  ptr = &y; /* error: ptr es const; no se puede asignar una nueva dirección */

 return 0; /* indica terminación exitosa */

 } /* fin de main */
