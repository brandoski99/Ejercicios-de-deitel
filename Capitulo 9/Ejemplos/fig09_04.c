/* Figura 9.4: fig09_04.c */
/* Impresión de números de punto flotante con
especificadores de conversión de punto flotante */
#include <stdio.h>
int main() {
  printf("%e\n", 1234567.89);
  printf("%e\n", +1234567.89);
  printf("%e\n", -1234567.89);

  printf("%E\n", 1234567.89);
  printf("%f\n", 1234567.89);
  printf("%g\n", 1234567.89);
  printf("%G\n", 1234567.89);
  return 0; /* indica terminación exitosa */
} /* fin de main */
