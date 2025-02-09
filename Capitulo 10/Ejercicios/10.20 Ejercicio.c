/* ej10_20.c */

// El programa devuelve 1 si el residuo del total es = 0, y devuelve 0 si el
// residuo del total es != 0
#include <stdio.h>
int misterio(unsigned bits); /* prototipo */
int main() {
  unsigned x;
  printf("Introduce un entero: ");
  scanf("%u", &x);
  printf("El resutado es %d\n", misterio(x));
  return 0; /*indica terminación exitosa */
} /* fin de main */
/* ¿Qué hace la función ? */
int misterio(unsigned bits) {
  unsigned i;
  /* contador */
  unsigned mascara = 1 << 31; /* inicializa mascara */
  unsigned total = 0;
  /* inicializa total */
  for (i = 1; i <= 32; i++, bits <<= 1) {
    if ((bits & mascara) == mascara) {
      printf("%d:\n", i);
      printf("Numero: ");
      printf("Mascara: ");
      total++;
    } /* fin de if */
  } /* fin de for */
  return !(total % 2) ? 1 : 0;
} /* fin de la función misterio */
