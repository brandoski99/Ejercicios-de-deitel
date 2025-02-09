/* Figura 8.7: fig08_07.c
Uso de atoi */
#include <stdio.h>
#include <stdlib.h>
int main() {
  int i; /* variable para almacenar la cadena convertida */
  i = atoi("2593");
  printf("%s%d\n%s%d\n", "La cadena \"2593\" convertida a int es ", i,
         "El valor convertido menos 593 es ", i - 593);
  return 0; /* indica terminación exitosa
             */
} /* fin de main */
