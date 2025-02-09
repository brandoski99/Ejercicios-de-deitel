/* Figura 9.21: fig09_21.c */
/* Uso de un conjunto de exploración */
#include <stdio.h>
/* la función main comienza la ejecución del programa */
int main() {
  char z[9]; /* define el arreglo z */
  printf("Introduzca una cadena: ");
  scanf("%[aeiou]", z); /* busca un conjunto de caracteres */
  printf("La entrada es \"%s\"\n", z);
  return 0; /* indica terminación exitosa */
} /* fin de main */
