/* ej07_22.c */
/* ¿Qué hace este programa?
 * El programa cuenta los numeros de caracteres de una cadena */
#include <stdio.h>

int misterio2(const char *s); /* prototipo */

int main() {
  char cadena[80]; /* crea un arreglo de carateres */
  printf("Introduzca una cadena : ");
  scanf("%s", cadena);
  printf("%d\n", misterio2(cadena));
  return 0; /* indica terminación exitosa */

} /* fin de main */
/* ¿Qué hace esta función? */
int misterio2(const char *s) {
  int x; /* contador */
  for (x = 0; *s != '\0'; s++) {
    x++;
  }
  return x;
} /* ciclo a través de la cadena */
