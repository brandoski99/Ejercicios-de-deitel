#include <stdio.h>

#define LIMIT 212
int main() {
  int fahrenheit = 0;
  float celsius = 0.0;

  printf("Fahrenheit\tCelsius\n");
  for (; fahrenheit <= LIMIT; fahrenheit++) {
    celsius = 5.0 / 9.0 * (fahrenheit - 32);
    printf("%d\t\t%.3f\n", fahrenheit, celsius);
  }
  return 0;
}
