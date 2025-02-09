#include <stdio.h>

unsigned packCharacters(char char1, char char2);
void showbits(unsigned int character);
void unpackCharacters(unsigned int pack);
int main() {
  char char1, char2;
  unsigned int package = 0;
  printf("Introduzca 2 caracteres:\n");
  scanf("%c %c", &char1, &char2);
  printf("%c = ", char1);
  showbits(char1);
  printf("%c = ", char2);
  // Empaquetar caracteres
  showbits(char2);
  package = packCharacters(char1, char2);
  // Desempaquetar caracteres
  unpackCharacters(package);
  return 0;
}

unsigned packCharacters(char char1, char char2) {
  printf("caracteres empaquetados = ");
  unsigned int character1 = char1;
  unsigned int character2 = char2;
  character1 <<= 8;
  showbits(character1 | character2);
  return character1 | character2;
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
  unsigned int temp = pack;
  unsigned int mask = 65280;
  unsigned int unpack = temp & mask; // Desempaca el primer caracter
  unpack >>= 8;
  char character1 = unpack;
  printf("\nEl primer caracter desempaquetado es: %c\n", character1);
  mask = 255;
  unpack = temp & mask; // Desempaca el segundo caracter
  char character2 = unpack;
  printf("El segundo caracter desempaquetado es: %c\n", character2);
  printf("\nPaquete despues de ser desempaquetado: ");
  showbits(unpack);
}
