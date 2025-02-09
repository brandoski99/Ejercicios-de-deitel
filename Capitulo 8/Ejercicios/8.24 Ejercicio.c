#include <stdio.h>
#include <string.h>

#define SIZE 300

void onlyED(char str[]);

int main() {
  char sentence[SIZE];
  printf("El programa solo imprimira las palabras inicien por la letra "
         "\"ed\"(ingrese 99 para terminar)\n");
  while (1) {
    fgets(sentence, sizeof(sentence), stdin);
    if (strcmp(sentence, "99\n") == 0) {
      break;
    }
    onlyED(sentence);
  }

  return 0;
}

void onlyED(char str[]) {
  char *token = strtok(str, " \n");

  // Repetir hasta llegar a la ultima palabra
  while (token != NULL) {
    if (strcmp(&token[strlen(token) - 2], "ed") == 0) {
      printf("%s\n", token);
    }

    // Pasar a la siguiente palabra
    token = strtok(NULL, " \n");
  }
}
