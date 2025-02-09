#include <stdio.h>

void showbits(unsigned int bits);
void reverseBits(unsigned int bits);
int main() {
  unsigned int input;
  printf("Introduzca un numero enter sin signo:\n");
  scanf("%u", &input);
  printf("El numero es = %u\nSu valor en bits es = ", input);
  showbits(input);
  printf("Su valor inverso en bits es = ");
  reverseBits(input);
  return 0;
}
void showbits(unsigned int bits) {
  unsigned int c;
  unsigned int temp = bits;
  unsigned int deployMask = 1 << 31;

  for (c = 1; c <= 32; c++) {
    putchar(temp & deployMask ? '1' : '0');
    temp <<= 1;
    if (c % 8 == 0) {
      putchar(' ');
    }
  }
  putchar('\n');
}

void reverseBits(unsigned int bits) {
  unsigned int c;
  unsigned int temp = bits;
  unsigned int deployMask = 1;

  for (c = 1; c <= 32; c++) {
    putchar(temp & deployMask ? '1' : '0');
    temp >>= 1;
    if (c % 8 == 0) {
      putchar(' ');
    }
  }
  putchar('\n');
}
