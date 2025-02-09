/* Figura 9.12: fig09_12.c */
/* Impresión de números con y sin la bandera + */
#include <stdio.h>
int main() {
  printf("%d\n%d\n", 786, -786);
  printf("%+d\n%+d\n", 786, -786);

  return 0; /* indica terminación exitosa */
} /* fin de main */
