/* ej10_19.c */
/* Este programa determina si el valor es un múltiplo de X. */

// X = 1024 (00000000 00000000 00000100 00000000)
/*El programa compara el valor introducido por los primeros 10 multiplos de 1024
 */
#include <stdio.h>
int multiplo(int num); /* prototipo */

int main() {
  int y; /* y almacenará un entero introducido por el usuario */
  printf("Introduce un entero entre 1 y 32000: ");
  scanf("%d", &y);
  /* si y es un múltiplo de X */
  if (multiplo(y)) {
    printf("%d es un multiplo de X\n", y);
  } /* fin de if */
  else {
    printf("%d no es un multiplo de X\n", y);
  } /* fin de else */
  return 0; /* indica terminación exitosa */
} /* fin de main */
/* determina si suma es un múltiplo de X */
int multiplo(int num) {
  int i;
  /* contador */
  int mascara = 1; /* inicializa mascara */
  int mult = 1;    /* initialize mult */
  for (i = 1; i <= 10; i++, mascara <<= 1) {
    if ((num & mascara) != 0) {
      mult = 0;
      break;
    } /* fin de if */
  } /* fin de for */
  return mult;
} /* fin de la función multiplica */
