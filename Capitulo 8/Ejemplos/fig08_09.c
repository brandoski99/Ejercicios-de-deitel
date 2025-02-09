/* Figura 8.9: fig08_09.c
Uso de strtod */
#include <stdio.h>
#include <stdlib.h>
int main() {
  /* inicializa el apuntador cadena */
  const char *cadena = "51.2% son admitidos"; /* inicializa la cadena */
  double d;        /* variable para almacenar la secuencia convertida */
  char *ptrCadena; /* crea un apuntador char */

  d = strtod(cadena, &ptrCadena);
  printf("La cadena \"%s\" se convierte en \n", cadena);
  printf("un valor double %.2f y la cadena \"%s\"\n", d, ptrCadena);
  return 0; /* indica terminación exitosa */
}
/* fin de main */
