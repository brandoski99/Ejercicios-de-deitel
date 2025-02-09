/* Figura 8.6: fig08_06.c
Uso de atof */
#include <stdio.h>
#include <stdlib.h>
int main() {
  double d; /* variable para almacenar la cadena convertida */
  d = atof("99.0");
  printf("%s%.3f\n%s%.3f\n", "La cadena \"99.0\" convertida a double es ", d,
         "El valor convertido dividido entre 2 es ", d / 2.0);
  return 0; /* indica terminación exitosa */
} /* fin de main */
