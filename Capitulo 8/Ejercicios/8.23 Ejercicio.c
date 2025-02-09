#include <stdio.h>
#include <string.h>

#define SIZE 300

void onlyB(char str[]);

int main() {
  char sentence[SIZE];
  printf("El programa solo imprimira las palabras inicien por la letra "
         "\'b\'(ingrese 99 para terminar)\n");
  while (1) {
    fgets(sentence, sizeof(sentence), stdin);
    if (strcmp(sentence, "99\n") == 0) {
      break;
    }
    onlyB(sentence);
  }

  return 0;
}

void onlyB(char str[]) {
  char *token = strtok(str, " \n");

  // Repetir hasta llegar a la ultima palabra
  while (token != NULL) {
    if (token[0] == 'b' || token[0] == 'B') {
      printf("%s\n", token);
    }

    // Pasar a la siguiente palabra
    token = strtok(NULL, " \n");
  }
}
