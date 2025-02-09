#include <stdio.h>

void despliegaBits(unsigned int valor); /* prototipo */

int main() {
  despliegaBits(200);
  return 0;
}

void despliegaBits(unsigned int valor) {
  unsigned int c; /* contador */
  unsigned int despliegaMascara;

  // Para enteros de 2 bytes
  if (sizeof(valor) == 2) {
    despliegaMascara = 1 << 15;

    // Para enteros de 4 bytes
  } else if (sizeof(valor) == 4) {
    despliegaMascara = 1 << 31;
  }
  // Si no es un entero de 2 o 4 bytes
  else {
    return;
  }

  printf("%10u = ", valor);
  /* ciclo a través de los bits */
  for (c = 1; c <= sizeof(valor) * 8; c++) {
    putchar(valor & despliegaMascara ? '1' : '0');
    valor <<= 1;      /* desplaza valor 1 hacia la izquierda */
    if (c % 8 == 0) { /* despliega espacio después de 8 bits */
      putchar(' ');
    } /* fin de if */
  } /* fin de for */
  putchar('\n');
} /* fin de la función despliegaBits */
