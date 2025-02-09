#include <stdio.h>
#include <string.h>

int main() {
  char lines[256];
  int wordscount = 0;
  printf("Introduzca varias lineas de texto(introduzca 99 para salir):\n");

  while (1) {
    fgets(lines, sizeof(lines), stdin);

    if (strcmp(lines, "99\n") == 0) {
      break;
    }

    // Empieza a contar las palabras hasta que strtok devuelva NULL
    strtok(lines, " ");
    wordscount++;
    while (strtok(NULL, " ") != NULL) {
      wordscount++;
    }
  }

  printf("\nEl total de palabras fueron: %d", wordscount);
  return 0;
}
