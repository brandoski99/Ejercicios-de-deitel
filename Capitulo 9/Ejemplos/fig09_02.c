/* Figura 9.2: fig09_02.c */
/* Uso de los especificadores de conversión entera */
#include <stdio.h>

int main() {
  printf("%d\n", 455);
  printf("%i\n", 455); /* i es lo mismo que d en printf */
  printf("%d\n", +455);
  printf("%d\n", -455);
  printf("%hd\n", 32000);
  printf("%ld\n", 2000000000);
  printf("%o\n", 455);
  printf("%u\n", 455);
  printf("%u\n", -455);
  printf("%x\n", 455);
  printf("%X\n", 455);
  return 0; /* indica terminación exitosa */
} /* fin de main */
