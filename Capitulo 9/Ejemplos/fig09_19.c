/* Figura 9.19: fig09_19.c */
/* Lectura de números de punto flotante */
#include <stdio.h>
/* la función main comienza la ejecución del programa */
int main() {
  double a;
  double b;
  double c;
  printf("Introduzca tres numeros de punto flotante: \n");
  scanf("%le%lf%lg", &a, &b, &c);
  printf("Aqui estan los numeros introducidos con notacion \n");
  printf("plana de punto flotante:\n");
  printf("%f\n%f\n%f\n", a, b, c);
  return 0; /* indica terminación exitosa */
} /* fin de main */
