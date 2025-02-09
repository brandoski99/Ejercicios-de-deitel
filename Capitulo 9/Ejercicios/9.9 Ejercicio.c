#include <stdio.h>

int main() {
  int x = 0;
  printf("%%p = %p\n%%d = %d", &x, &x);
  return 0;
}
