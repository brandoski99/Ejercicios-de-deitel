/* Figura 8.35: fig08_35.c
Uso de memset */
#include <stdio.h>
#include <string.h>
int main() {
  char cadena1[15] = "BBBBBBBBBBBBBB"; /* inicializa cadena1 */
  printf("cadena1 = %s\n", cadena1);
  printf("cadena1 despues de memset = %s\n", memset(cadena1, 'b', 7));
  return 0; /* indica terminación exitosa */
} /* fin de main */
