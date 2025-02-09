/* Figura 9.11: fig09_11.c */
/* Justificación derecha e izquierda de valores */
#include <stdio.h>
int main() {
  printf("%10s%10d%10c%10f\n\n", "hola", 7, 'a', 1.23);
  printf("%-10s%-10d%-10c%-10f\n", "hola", 7, 'a', 1.23);
  return 0; /* indica terminación exitosa */
} /* fin de main */
