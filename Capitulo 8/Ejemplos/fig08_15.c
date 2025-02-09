/* Figura 8.15: fig08_15.c
Uso de sprintf */
#include <stdio.h>
int main() {
  char s[80]; /* crea un arreglo de caracteres */
  int x;      /* valor x a introducir */
  double y;   /* valor y a introducir */

  printf("Introduzca un entero y un double:\n");
  scanf("%d%lf", &x, &y);
  sprintf(s, "entero:%6d\ndouble:%8.2f", x, y);
  printf("%s\n%s\n",
         "La salida con formato, almacenada en el arreglo s, es:", s);
  return 0; /* indica terminación exitosa */
} /* fin de main */
