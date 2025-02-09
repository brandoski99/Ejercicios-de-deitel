#include <stdio.h>

int main() {
  int x = 12345;
  float y = 1.2345;

  for (int i = 1; i <= 10; i++) {
    printf("Con un campo de %d: ", i);
    printf("%*d\n", i, x);
  }
  putchar('\n');

  for (int i = 1; i <= 10; i++) {
    printf("Con un campo de %d: ", i);
    printf("%*.4f\n", i, y);
  }
  return 0;
}
