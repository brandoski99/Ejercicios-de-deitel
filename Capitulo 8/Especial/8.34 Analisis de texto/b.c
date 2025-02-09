#include <stdio.h>
#include <string.h>

#define SIZE 256
#define LEN_WORDS 8

void printLen(char *lines);

int main() {
  char lines[SIZE];
  printf("Introduzca varias lineas de texto(Introduzca 99 para salir)\n");
  while (1) {
    fgets(lines, sizeof(lines), stdin);

    if (strcmp(lines, "99\n") == 0) {
      break;
    }

    if (strcmp(lines, "\n") != 0) {
      printLen(lines);
    }
  }
  return 0;
}

void printLen(char *lines) {
  int lens[LEN_WORDS] = {0};
  char *token = strtok(lines, " \n");

  // Contamos las longitudes de cada palabra
  while (token != NULL) {
    int length = strlen(token);
    if (length > 0 && length <= LEN_WORDS) {
      lens[length - 1]++;
    }
    token = strtok(NULL, " \n");
  }

  // Imprimir la tabla
  printf("\nLongitud de la palabra\tOcurrencias\n");
  for (int i = 0; i < LEN_WORDS; i++) {
    printf("%d\t\t\t%d\n", i + 1, lens[i]);
  }
  putchar('\n');
}
