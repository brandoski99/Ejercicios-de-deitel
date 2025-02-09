/* Figura 9.23: fig09_23.c */
/* entrada de datos con un ancho de campo */
#include <stdio.h>

int main() {
  int x;
  int y;
  printf("Introduce un entero de seis digitos: ");
  scanf("%2d%d", &x, &y);
  printf("Los enteros introducidos son %d y %d\n", x, y);
  return 0; /* indica terminación exitosa */
} /* fin de main */
