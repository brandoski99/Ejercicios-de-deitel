/* Figura 8.8: fig08_08.c
Uso de atol */
#include <stdio.h>
#include <stdlib.h>
int main() {
  long l; /* variable para almacenar la cadena converitida */
  l = atol("1000000");
  printf("%s%ld\n%s%ld\n", "La cadena \"1000000\" convertida a long int es ", l,
         "El valor convertido, dividido entre 2 es ", l / 2);
  return 0; /* indica terminación exitosa */
} /* fin de main */
