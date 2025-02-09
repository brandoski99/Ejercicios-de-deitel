/* Figura 8.11: fig08_11.c
Uso de strtoul */
#include <stdio.h>
#include <stdlib.h>
int main() {
  const char *cadena = "1234567abc"; /* inicializa el apuntador cadena */
  unsigned long x;                   /* variable to hold converted sequence */
  char *ptrResto;                    /* crea un apuntador a char */
  x = strtoul(cadena, &ptrResto, 0);

  printf("%s\"%s\"\n%s%lu\n%s\"%s\"\n%s%lu\n", "La cadena original es ", cadena,
         "El valor convertido es ", x, "El resto de la cadena original es ",
         ptrResto, "El valor convertido menos 567 es ", x - 567);
  return 0; /* indica terminación exitosa */
} /* fin de main */
