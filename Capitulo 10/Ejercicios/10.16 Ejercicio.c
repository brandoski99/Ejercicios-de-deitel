#include <stdio.h>

unsigned int packCharacters(char char1, char char2, char char3, char char4);
void showbits(unsigned int character);
void unpackCharacters(unsigned int pack);
int main() {
  char char1, char2, char3, char4;
  unsigned int pack = 0;
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

  pack = packCharacters(char1, char2, char3, char4);
  unpackCharacters(pack);
  return 0;
}

unsigned int packCharacters(char char1, char char2, char char3, char char4) {
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
  return character1; // retornar paquete con 4 caracteres en bits
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

void unpackCharacters(unsigned int pack) {
  printf("\nPaquete sin desempaquetar: ");
  showbits(pack);
  unsigned int mask = 255 << 24;     // 11111111 00000000 00000000 00000000
  unsigned int unpack = pack & mask; // Desempaca el primer caracter
  unpack >>= 24;
  char character1 = unpack;
  printf("\nEl primer caracter desempaquetado es: %c\n", character1);
  mask = 255 << 16;     // 00000000 11111111 00000000 00000000
  unpack = pack & mask; // Desempaca el segundo caracter
  unpack >>= 16;
  char character2 = unpack;
  printf("El segundo caracter desempaquetado es: %c\n", character2);
  mask = 255 << 8;      // 00000000  00000000 11111111 00000000
  unpack = pack & mask; // Desempaca el tercer caracter
  unpack >>= 8;
  char character3 = unpack;

  printf("El tercer caracter desempaquetado es: %c\n", character3);
  mask = 255;           // 00000000  00000000 00000000 11111111
  unpack = pack & mask; // Desempaca el cuarto caracter
  char character4 = unpack;
  printf("El cuarto caracter desempaquetado es: %c\n", character4);
  printf("\nPaquete despues de ser desempaquetado: ");
  showbits(unpack);
}
