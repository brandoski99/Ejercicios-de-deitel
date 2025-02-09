#include <stdio.h>

void printBits(int bits);

int main() {
  int num = 8;

  printBits(num);
  printBits(num >> 4);
  return 0;
}

void printBits(int bits) {
  unsigned c;
  unsigned deployMask = 1 << 3;

  printf("%7u = ", bits);

  for (c = 1; c <= 4; c++) {
    putchar(bits & deployMask ? '1' : '0');
    bits <<= 1;
  }
  putchar('\n');
}
