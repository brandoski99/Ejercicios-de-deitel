/* Figura 9.8: fig09_08.c */
/* Impresión de enteros justificados a la derecha */
#include <stdio.h>
int main() {
  printf("%4d\n", 1);
  printf("%4d\n", 12);
  printf("%4d\n", 123);
  printf("%4d\n", 1234);
  printf("%4d\n\n", 12345); /* dato demasiado largo */
  printf("%4d\n", -1);
  printf("%4d\n", -12);
  printf("%4d\n", -123);
  printf("%4d\n", -1234);  /* dato demasiado largo */
  printf("%4d\n", -12345); /* dato demasiado largo */
  return 0;                /* indica terminación exitosa */
} /* fin de main */
