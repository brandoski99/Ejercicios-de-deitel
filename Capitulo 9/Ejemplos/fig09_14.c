/* Figura 9.14: fig09_14.c */
/* Uso de la bandera # con los especificadores de conversión
o, x, X y cualquier especificador de punto flotante */
#include <stdio.h>
int main() {
  int c = 1427;
  /* inicializa c */
  double p = 1427.0; /* inicializa p */
  printf("%#o\n", c);
  printf("%#x\n", c);
  printf("%#X\n", c);
  printf("\n%g\n", p);
  printf("%#g\n", p);

  return 0; /* indica terminación exitosa */
} /* fin de main */
