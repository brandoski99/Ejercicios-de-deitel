#include <stdio.h>

int main() {
  float num = 9876.12345;
  for (int i = 1; i <= 9; i++) {
    printf("Precision %d: %.*g\n", i, i, num);
  }
  return 0;
}
