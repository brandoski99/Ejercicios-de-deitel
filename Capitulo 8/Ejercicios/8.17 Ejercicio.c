#include <stdio.h>
#include <string.h>

void ocurrences(char sentence[], char search[]);
int main() {
  char sentence1[100];
  char sentence2[100];
  char sentence3[100];
  char search[100];
  printf("Introduce varias lineas de texto: ");
  fgets(sentence1, sizeof(sentence1), stdin);
  fgets(sentence2, sizeof(sentence2), stdin);
  fgets(sentence3, sizeof(sentence3), stdin);
  printf("\nIntroduce una cadena de busqueda: ");
  scanf("%99s", search);

  ocurrences(sentence1, search);
  ocurrences(sentence2, search);
  ocurrences(sentence3, search);
  return 0;
}

void ocurrences(char sentence[], char search[]) {
  static int sentecenum = 1;
  char *ptrSearch = strstr(sentence, search);

  printf("linea de texto%d:", sentecenum++);
  if (ptrSearch != NULL) {
    // Imprime la primera ocurrencia
    printf("\nLa primera ocurrencia es: %s", ptrSearch);

    // Busca si hay una segunda ocurrencia
    ptrSearch = strstr(ptrSearch + 1, search);
    if (ptrSearch != NULL) {
      printf("\nLa segunda  ocurrencia es: %s", ptrSearch);
    }
  }
  // Si strstr devuelve NULL, no se encontro ocurrenias de search en sentence
  else {
    printf("No se encontraron ocurrencias de: %s", search);
  }
  printf("\n");
}
