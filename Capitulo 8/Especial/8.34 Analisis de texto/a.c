
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256
#define ALPHABET_SIZE 26
#define LEN_WORDS 8

void printAlphabet(char *lines);

int main() {
  char lines[SIZE];
  printf("Introduzca varias lineas de texto(Introduzca 99 para salir)\n");
  while (1) {
    fgets(lines, sizeof(lines), stdin);

    if (strcmp(lines, "99\n") == 0) {
      break;
    }

    if (strcmp(lines, "\n") != 0) {
      printAlphabet(lines);
    }
  }
  return 0;
}

void printAlphabet(char *lines) {
  int alpha[ALPHABET_SIZE] = {0};
  char *src = lines;

  // Contamos los caracteres
  while (*src != '\0') {
    char ch = tolower(*src);
    if (ch >= 'a' && ch <= 'z') {
      alpha[ch - 'a']++;
    }
    src++;
  }

  // Imprimir la tabla
  printf("\nLetra\tOcurrencias\n");
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    printf("%c\t%d\n", 'a' + i, alpha[i]);
  }
  putchar('\n');
}
