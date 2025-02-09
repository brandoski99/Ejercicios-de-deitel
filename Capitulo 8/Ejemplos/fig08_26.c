/* Figura 8.26: fig08_26.c
Uso de strrchr */
#include <stdio.h>
#include <string.h>
int main() {
  /* inicializa el apuntador a char */
  const char *cadena1 = "Un zoologico tiene muchos animales, incluso zorros";

  int c = 'z'; /* caracter a buscar */

  printf("%s\n%s'%c'%s\"%s\"\n", "El resto de cadena1 que comienza con la",
         "ultima ocurrencia del caracter ", c, " es: ", strrchr(cadena1, c));
  return 0; /* indica terminación exitosa */
} /* fin de main */
