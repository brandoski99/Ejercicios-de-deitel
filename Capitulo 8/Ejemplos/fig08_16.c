/* Figura 8.16: fig08_16.c
Uso de sscanf */
#include <stdio.h>
int main() {
  char s[] = "31298 87.375"; /* inicializa el arreglo s */
  int x;                     /* valor x a introducir */
  double y;                  /* valor y a introducir */

  sscanf(s, "%d%lf", &x, &y);
  printf("%s\n%s%6d\n%s%8.3f\n",
         "Los valores almacenados en el arreglo de caracteres s son:",
         "entero:", x, "double:", y);
  return 0; /* indica terminación exitosa */
} /* fin de main */
