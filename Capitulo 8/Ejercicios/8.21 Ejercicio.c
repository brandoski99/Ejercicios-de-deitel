#include <stdio.h>
#include <string.h>

#define CITIES 10

void swapStr(char **str1, char **str2);
void citiesBubbleSort(char *cities[]);
void citiesSelectionSort(int currentPos, char *cities[], int length);
void citiesQuickSort(char *cities[], int start, int end);
void printCities(char *cities[]);

int main() {
  char *cities[CITIES] = {"Maracay",   "Caracas", "San Cristobal", "Merida",
                          "Carabobo",  "Barinas", "Cumana",        "Punto Fijo",
                          "La Guaira", "Maturin"};
  printf("Ciudades sin ordenar alfabeticamente:\n");
  printCities(cities);
  // citiesBubbleSort(cities);
  // citiesSelectionSort(0, cities, CITIES);
  // citiesQuickSort(cities, 0, CITIES - 1);
  printf("\nCiudades ordenadas alfabeticamente:\n");
  printCities(cities);
}

// Algoritmo de ordenamiento burbuja
void citiesBubbleSort(char *cities[]) {
  for (int pass = CITIES; pass > 1; pass--) {
    for (int i = 0; i < CITIES - 1; i++) {
      if (strcmp(cities[i], cities[i + 1]) > 0) {
        swapStr(&cities[i], &cities[i + 1]);
      }
    }
  }
}
// Algoritmo de ordenamiento por seleccion

void citiesSelectionSort(int currentPos, char *cities[], int length) {
  if (currentPos == length - 1) {
    return;
  }

  int minValueIndex = currentPos;

  for (int i = currentPos + 1; i < length; i++) {
    if (strcmp(cities[i], cities[minValueIndex]) < 0) {
      minValueIndex = i;
    }
  }

  if (minValueIndex != currentPos) {
    swapStr(&cities[currentPos], &cities[minValueIndex]);
  }

  citiesSelectionSort(currentPos + 1, cities, length);
}

void citiesQuickSort(char *cities[], int start, int end) {
  int Partition(char *cities[], int start, int end);
  if (end > start) {
    int pivotIndex = Partition(cities, start, end);
    citiesQuickSort(cities, pivotIndex + 1, end);
    citiesQuickSort(cities, start, pivotIndex);
  }
}

int Partition(char *cities[], int start, int end) {
  int pivot = start;
  int left = start;
  int right = end;
  int j = 0;
  while (1) {
    // derecha
    while (strcmp(cities[right], cities[pivot]) > 0) {
      right--;
    }

    // izquierda
    while (strcmp(cities[left], cities[pivot]) < 0) {
      left++;
    }
    if (left >= right) {
      return right;
    }
    swapStr(&cities[left], &cities[right]);
  }
}
void swapStr(char **str1, char **str2) {
  char *temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

void printCities(char *cities[]) {
  for (int i = 0; i < CITIES; i++) {
    printf("%d-%s\n", i, cities[i]);
  }
}
