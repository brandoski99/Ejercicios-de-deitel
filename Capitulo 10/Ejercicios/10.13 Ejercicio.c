#include <stdio.h>

void packCharacters(char char1, char char2);
void showbits(unsigned int character);
int main() {
  char char1, char2;
  printf("Introduzca 2 caracteres:\n");
  scanf("%c %c", &char1, &char2);
  printf("%c = ", char1);
  showbits(char1);
  printf("%c = ", char2);
  showbits(char2);
  packCharacters(char1, char2);
  return 0;
}

void packCharacters(char char1, char char2) {
  printf("caracteres empaquetados = ");
  unsigned character1 = char1;
  unsigned character2 = char2;
  character1 <<= 8;
  showbits(character1 | character2);
}

void showbits(unsigned int character) {
  unsigned c;
  unsigned temp = character;
  unsigned deployMask = 1 << 31;

  for (c = 1; c <= 32; c++) {
    putchar(temp & deployMask ? '1' : '0');
    temp <<= 1;
    if (c % 8 == 0) {
      putchar(' ');
    }
  }
  putchar('\n');
}
