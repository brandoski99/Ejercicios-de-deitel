/* Figura 9.20: fig09_20.c */
/* Lectura de caracteres y cadenas */
#include <stdio.h>
int main() {
  char x;
  char y[9];
  printf("Introduzca una cadena: ");
  scanf("%c%s", &x, y);
  printf("La entrada fue:\n");
  printf("el caracter \"%c\" ", x);
  printf("y la cadena \"%s\"\n", y);
  return 0; /* indica terminación exitosa */
} /* fin de main */
