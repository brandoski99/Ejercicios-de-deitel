#include <stdio.h>
#include <string.h>

void greater(int array[], int elements);
void less(int array[], int elements);
void swap(int *element1, int *element2);
int main(int argc, char *argv[]) {
  if (argc == 2) {
    int arr[10] = {2, 5, 109, 1293, 12, 23, 891, 232, 12, 222};
    printf("El arreglo es:\n");
    for (int i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
    }
    putchar('\n');
    // Si la opcion introducida es -a, entonces se ordena en orden ascendente
    if (strcmp(argv[1], "-a") == 0) {
      greater(arr, 10);
      printf("\nEl arreglo en orden ascendente es:\n");
      for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
      }
    }
    // Si la opcion introducida es -d, entonces se ordena en orden descendente
    else if (strcmp(argv[1], "-d") == 0) {
      less(arr, 10);
      printf("\nEl arreglo en orden descendente es:\n");
      for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
      }
    }
    // Si el segundo argumento no es un comando valido, lanza un error
    else {
      printf("%s opcion invalida\n", argv[1]);
    }
  }
  // Si el numero de argumentos es insuficiente, lanza un error
  else {
    printf("\nIntroduzca un argumento valido, -a o -d\n");
  }
  return 0;
}
void greater(int array[], int elements) {
  for (int i = 0; i < elements - 1; ++i) {

    // Assume the current position holds
    // the minimum element
    int min_idx = i;

    // Iterate through the unsorted portion
    // to find the actual minimum
    for (int j = i + 1; j < elements; ++j) {
      if (array[j] < array[min_idx]) {

        // Update min_idx if a smaller
        // element is found
        min_idx = j;
      }
    }

    // Move minimum element to its
    // correct position
    swap(&array[i], &array[min_idx]);
  }
}

void less(int array[], int elements) {
  for (int i = 0; i < elements - 1; i++) {
    int k = i;
    for (int j = i + 1; j < elements; j++) {
      if (array[j] > array[k]) {
        k = j;
        // printf("%d\n", k);
      }
    }
    swap(&array[k], &array[i]);
  }
}

void swap(int *element1, int *element2) {
  int temp = *element1;
  *element1 = *element2;
  *element2 = temp;
}
