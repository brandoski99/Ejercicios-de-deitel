#include <stdio.h>

void pow2(unsigned number, unsigned potential);

int main() {
  pow2(3, 5);
  return 0;
}

void pow2(unsigned number, unsigned potential) {
  unsigned total = number << potential;
  printf("El resultado en decimal de %d x 2^%d = %d\n", number, potential,
         total);
  printf("El resultado en bits de %d x 2^%d = ", number, potential);

  // Imprimir resultado en bits
  unsigned mask = 1 << 31;
  unsigned bits = total;
  for (int c = 1; c <= 32; c++) {
    printf(mask & bits ? "1" : "0");
    bits <<= 1;
    if (c % 8 == 0) {
      putchar(' ');
    }
  }
  putchar('\n');
}
