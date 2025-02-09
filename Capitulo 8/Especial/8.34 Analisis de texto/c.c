#include <stdio.h>
#include <string.h>

#define LINES 100
#define SIZE 1000

void printWordsOcurrencies(const char *lines);

int main() {
  char lines[LINES];
  char accumulator[SIZE];
  int countLines = 0;
  printf("Introduzca varias lineas(Introduzca 99 para salir\n");

  while (1) {
    fgets(lines, sizeof(lines), stdin);
    if (strcmp(lines, "99\n") == 0) {
      break;
    }

    if (countLines + strlen(lines) >= SIZE) {
      printf("\nLimite de lineas alcanzado, terminando ejecucion...\n");
      break;
    }
    // Guardar las lineas
    sprintf(&accumulator[countLines], "%s", lines);
    countLines += strlen(lines);
  }

  countLines++;
  accumulator[countLines] = '\0';
  printWordsOcurrencies(accumulator);
  return 0;
}

void printWordsOcurrencies(const char *lines) {
  int countWords = 0;
  char copylines[SIZE];
  strcpy(copylines, lines); /* Copiar las lineas para que strtok no altere el
                               arreglo original */

  char processedWords[SIZE]; // Guardar palabras y evitar su repeticion
  char *token = strtok(copylines, " \n");

  while (token != NULL) {

    /* Revisar si la palabra no ha sido procesada */
    if (strstr(processedWords, token) == NULL) {
      /* Guarda la primera ocurrenia de la palabra */
      char *ptrSearch = strstr(lines, token);
      int i = 0;
      while (strstr(ptrSearch, token) != NULL) {
        i++;

        if (strstr(ptrSearch + 1, token) == NULL) {
          break;
        }
        // Pasar a la siguiente ocurrencia
        ptrSearch = strstr(ptrSearch + 1, token);
      }
      // Marcar palabra como ya procesada
      sprintf(&processedWords[countWords], "%s ", token);
      countWords += strlen(token);
      countWords++; // Dejar un espacio para la siguiente palabra
      printf("La palabra \"%s\" se repite %d veces\n", token, i);
    }
    // Pasar a la siguiente palabra
    token = strtok(NULL, " \n");
  }
}
