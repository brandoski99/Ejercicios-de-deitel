#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
int main() {
  srand(time(NULL));

  int randNumbers[SIZE] = {0};
  // Asigna los numeros aleatorios
  for (int i = 0; i < SIZE; i++) {
    int rNumber = 1 + rand() % 1000;
    randNumbers[i] = rNumber;
  }

  int total = 0;
  int currentNumber = 0;

  printf("Valor\tCaracteres totales\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d\t%n", randNumbers[i], &currentNumber);
    total += currentNumber - 1; // Restar 1 para que no cuente a '\t'
    printf("%d\n", total);
  }
  return 0;
}
