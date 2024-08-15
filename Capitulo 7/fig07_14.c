 /* Figura 7.14: fig07_14.c
 Intenta modificar un apuntador constante a un dato constante. */
 #include <stdio.h>

 int main()
 {
 int x = 5; /* inicializa x */
 int y; /* define y */

 /* ptr es un apuntador constante a un entero constante. ptr siempre
 apunta a la misma ubicación; el entero en esa ubicación
 no se puede modificar */
 const int *const ptr = &x;


 printf( "%d\n", *ptr );

*ptr = 7; /* error: *ptr es const; no se puede asignar un nuevo valor */
 ptr = &y; /* error: ptr es const; no se puede asignar una nueva dirección */

 return 0; /* indica terminación exitosa */
 } /* fin de main */
