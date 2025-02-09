/* Figura 9.22: fig09_22.c */
/* Uso de un conjunto de exploración invertido */
#include <stdio.h>
int main() {
  char z[9];
  printf("Introduzca una cadena: ");
  scanf("%[^aeiou]", z); /* conjunto de exploración invertido */
  printf("La entrada es \"%s\"\n", z);
  return 0; /* indica terminación exitosa */
} /* fin de main */
