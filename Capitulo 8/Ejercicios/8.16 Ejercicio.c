#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  char search[100];
  printf("Introduce una linea de texto: ");
  fgets(sentence, sizeof(sentence), stdin);
  printf("\nIntroduce una cadena a buscar: ");
  scanf("%99s", search);
  char *ptrSearch = strstr(sentence, search);

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
  return 0;
}
