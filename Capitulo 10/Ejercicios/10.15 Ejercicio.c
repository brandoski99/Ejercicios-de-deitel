
#include <stdio.h>

void packCharacters(char char1, char char2, char char3, char char4);
void showbits(unsigned int character);
int main() {
  char char1, char2, char3, char4;
  printf("Introduzca 4 caracteres:\n");
  scanf("%c %c %c %c", &char1, &char2, &char3, &char4);

  printf("%c = ", char1);
  showbits(char1);
  printf("%c = ", char2);
  showbits(char2);
  printf("%c = ", char3);
  showbits(char3);
  printf("%c = ", char4);
  showbits(char4);

  packCharacters(char1, char2, char3, char4);
  return 0;
}

void packCharacters(char char1, char char2, char char3, char char4) {
  printf("caracteres empaquetados = ");
  unsigned int character1 = char1;
  unsigned int character2 = char2;
  unsigned int character3 = char3;
  unsigned int character4 = char4;

  character1 <<= 8;
  character1 |= character2;
  character1 <<= 8;
  character1 |= character3;
  character1 <<= 8;
  character1 |= character4;

  showbits(character1);
}

void showbits(unsigned int character) {
  unsigned int c;
  unsigned int temp = character;
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
