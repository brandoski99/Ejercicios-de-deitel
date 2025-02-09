#include <stdarg.h>
#include <stdio.h>

int product(int elements, ...);

int main() {
  printf("El producto de los enteros es: %d\n", product(3, 5, 5, 5));
  return 0;
}

int product(int elements, ...) {
  int total = 1;
  va_list ap;
  va_start(ap, elements);

  for (int j = 1; j <= elements; j++) {
    total *= va_arg(ap, int);
  }
  va_end(ap);

  return total;
}
