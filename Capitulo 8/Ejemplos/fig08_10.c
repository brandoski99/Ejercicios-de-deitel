/* Figura 8.10: fig08_10.c
Uso de strtol */
#include <stdio.h>
#include <stdlib.h>
int main() {
  const char *cadena = "-1234567abc"; /* inicializa el apuntador cadena */
  char *ptrResto;                     /* crea un apuntador char */
  long x; /* variable para almacenar la secuencia convertida */

  x = strtol(cadena, &ptrResto, 0);
  printf("%s\"%s\"\n%s%ld\n%s\"%s\"\n%s%ld\n", "La cadena original es ", cadena,
         "El valor convertido es ", x, "El resto de la cadena original es ",
         ptrResto, "El valor convertido mas 567 es ", x + 567);
  return 0; /* indica terminación exitosa */
} /* fin de main */
