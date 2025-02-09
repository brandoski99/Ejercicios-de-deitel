/* Figura 9.18: fig09_18.c */
/* Lectura de enteros */
#include <stdio.h>
int main() {
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;

  int g;
  printf("Introduzca siete enteros: ");
  scanf("%d%i%i%i%o%u%x", &a, &b, &c, &d, &e, &f, &g);
  printf("La entrada desplegada como enteros decimales es:\n");
  printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
  return 0; /* indica terminación exitosa */
} /* fin de main */
