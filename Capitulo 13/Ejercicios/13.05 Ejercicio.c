#include <stdio.h>

#define SUM(x, y) printf("La suma de %s y %s es %d\n", #x, #y, ((x) + (y)));

int main() {
  SUM(10, 3)
  return 0;
}
