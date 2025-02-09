#include <stdio.h>
#include <string.h>

void pigLatin(char *word);
int main() {
  char word[100];
  char *ptrToken;
  fgets(word, sizeof(word), stdin);
  ptrToken = strtok(word, " \n");
  while (ptrToken != NULL) {
    // Verifica si la cadena son 2 o mas letras
    if (strlen(ptrToken) >= 2) {
      pigLatin(ptrToken);
    }
    // Si no imprime el caracter sin convertirlo a latin cerdo
    else {
      printf("%s ", ptrToken);
    }
    ptrToken = strtok(NULL, " \n");
  }
  return 0;
}

void pigLatin(char *word) { printf("%s%cay ", &word[1], word[0]); }
