#include <stdio.h>
#include <stdlib.h>

int main() {
  int elements;
  printf("Introduzca el numero de los elementos: ");
  scanf("%d", &elements);
  putchar('\n');
  int *arr = calloc(elements, sizeof(int));
  if (arr != NULL) {
    printf("Ingrese %d enteros:\n", elements);
    for (int i = 0; i < elements; i++) {
      scanf("%d", &arr[i]);
    }
    printf("\nEl arreglo es:\n");
    for (int i = 0; i < elements; i++) {
      printf("%d ", arr[i]);
    }
    int length = elements / 2;
    arr = realloc(arr, 5);
    printf("\nLa mitad del arrelgo es:\n");
    for (int i = 0; i < length; i++) {
      printf("%d ", arr[i]);
    }
    free(arr);

  }
  // Imprime error si no hay memoria para crear el  arreglo
  else {
    printf("\nMemoria insuficiente\n");
  }
  return 0;
}
