/* Figura 8.28: fig08_28.c
Uso de strstr */
#include <stdio.h>
#include <string.h>
int main() {
  const char *cadena1 = "abcdefabcdef"; /* cadena de búsqueda */
  const char *cadena2 = "def";          /* cadena a buscar */
  printf("%s%s\n%s%s\n\n%s\n%s%s\n", "cadena1 = ", cadena1,
         "cadena2 = ", cadena2, "El resto de cadena1 que comienza con",
         "la primera ocurrencia de cadena2 es: ", strstr(cadena1, cadena2));
  return 0; /* indica terminación exitosa */
} /* fin de main */
