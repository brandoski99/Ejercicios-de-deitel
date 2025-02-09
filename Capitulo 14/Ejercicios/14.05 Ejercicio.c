#include <stdio.h>

int main() {
  FILE *textFile = fopen("14.05.txt", "r+");
  FILE *tempFile = tmpfile();
  int character;

  if (textFile != NULL) {
    if (tempFile != NULL) {
      printf("El archivo antes de la modificacion es:\n");
      while ((character = getc(textFile)) != EOF) {
        putchar(character);
        putc(character, tempFile);
        putc(' ', tempFile);
      }
      // Devolvemos el apuntador de ubicacion al principio de cada archivo
      rewind(textFile);
      rewind(tempFile);

      printf("\nEl archivo despues de la modificacion es:\n");
      while ((character = getc(tempFile)) != EOF) {
        putchar(character);
        putc(character, textFile);
      }
    }
  }

  return 0;
}
