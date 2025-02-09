/* Figura 8.37: fig08_37.c
Uso de strerror */
#include <stdio.h>
#include <string.h>
int main() {
  printf("%s\n", strerror(99));
  return 0; /* indica terminación exitosa */
} /* fin de main */
