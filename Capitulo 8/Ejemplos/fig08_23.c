/* Figura 8.23: fig08_23.c
Uso de strchr */
#include <stdio.h>
#include <string.h>
int main() {
  const char *cadena =
      "Esta es una prueba"; /* inicializa el apuntador a char */
  char caracter1 = 'a';     /* inicializa el caracter1 */
  char caracter2 = 'z';     /* inicializa el caracter2 */

  /* si caracter1 se encuentra en cadena */
  if (strchr(cadena, caracter1) != NULL) {
    printf("\'%c\' se encuentra en \"%s\".\n", caracter1, cadena);
  } /* fin de if */
  else { /* si no se encuentra caracter1 */
    printf("\'%c\' no se encontro en \"%s\".\n", caracter1, cadena);
  } /* fin de else */
  /* si caracter2 se encuentra en cadena */
  if (strchr(cadena, caracter2) != NULL) {
    printf("\'%c\' se encontro en \"%s\".\n", caracter2, cadena);
  } /* fin de if */
  else { /* si no se encontro caracter2 */
    printf("\'%c\' no se encontro en \"%s\".\n", caracter2, cadena);
  } /* fin de else */
  return 0; /* indica terminación exitosa */
} /* fin de main */
