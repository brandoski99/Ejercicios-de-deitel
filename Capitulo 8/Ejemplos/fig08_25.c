/* Figura 8.25: fig08_25.c
Uso de strpbrk */
#include <stdio.h>
#include <string.h>
int main() {
  const char *cadena1 = "esta es una prueba"; /* inicializa a char */
  const char *cadena2 = "precaucion";         /* inicializa a char */

  printf("%s\"%s\"\n’%c’%s\n\"%s\"\n", "De los caracteres en ", cadena2,
         *strpbrk(cadena1, cadena2), " aparece primero en ", cadena1);
  return 0; /* indica terminación exitosa */
} /* fin de main */
