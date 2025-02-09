#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

int main() {
  char line[256];
  int letter_count[ALPHABET_SIZE] = {0};

  printf("Introduce varias lineas de texto (escribe 'fin' para terminar)\n");
  while (1) {
    fgets(line, sizeof(line), stdin);

    // Salir del bucle si encuentra "fin"a
    if (strcmp(line, "fin\n") == 0) {
      break;
    }

    // Contar las letras de cada linea
    for (int i = 0; line[i] != '\0'; i++) {
      char ch = tolower(line[i]);
      if (ch >= 'a' && ch <= 'z') {
        letter_count[ch - 'a']++;
      }
    }
  }

  // Imprimir resultados
  printf("\nConteo de letras:\n");
  printf("Letra\t Ocurrencias\n");
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    printf("%c\t%d\n", 'a' + i, letter_count[i]);
  }
}
