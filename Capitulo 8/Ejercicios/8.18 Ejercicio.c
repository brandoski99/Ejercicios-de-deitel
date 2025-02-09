#include <stdio.h>
#include <string.h>

void ocurrences(char sentence[], char search);

int main() {
  char sentence1[100];
  char sentence2[100];
  char sentence3[100];
  printf("\nIntroduce un caracter de busqueda: ");
  char search;
  scanf(" %c", &search);
  while (getchar() != '\n')
    ; // Consume el resto del buffer de entrada, asi evita que sentence1 quede
      // vacio

  printf("Introduce varias lineas de texto:\n");
  fgets(sentence1, sizeof(sentence1), stdin);
  fgets(sentence2, sizeof(sentence2), stdin);
  fgets(sentence3, sizeof(sentence3), stdin);

  ocurrences(sentence1, search);
  ocurrences(sentence2, search);
  ocurrences(sentence3, search);
  return 0;
}

void ocurrences(char sentence[], char search) {
  static int sentencenum = 1;
  printf("Linea de texto%d:\n", sentencenum++);
  char *ptrSearch = strchr(sentence, search);
  int ocurrences = 0;
  while (ptrSearch != NULL) {
    ocurrences++;
    ptrSearch = strchr(ptrSearch + 1, search);
  }
  printf("La letra \'%c\' se repite %d\n", search, ocurrences);
}
