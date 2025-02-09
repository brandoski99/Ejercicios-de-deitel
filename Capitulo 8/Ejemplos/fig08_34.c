/* Figura 8.34: fig08_34.c
Uso de memchr */
#include <stdio.h>
#include <string.h>
int main() {
  const char *s = "Esta es una cadena"; /* inicializa el apuntador char */
  printf("%s\'%c\'%s\"%s\"\n", "El resto de s despues del caracter ", 'd',
         " encontrado es ", memchr(s, 'd', 16));
  return 0; /* indica terminación exitosa */
} /* fin de main */
