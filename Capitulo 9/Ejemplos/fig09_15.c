/* Figura 9.15: fig09_15.c */
/* La impresión con la bandera 0( cero ) llena con ceros el inicio de un
campo*/
#include <stdio.h>
int main() {
  printf("%+09d\n", 452);
  printf("%09d\n", 452);
  return 0; /* indica terminación exitosa */
} /* fin de main */
