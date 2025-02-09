#include <stdio.h>

int main() {
  int digitsPrecision = 1;
  while (digitsPrecision != 5) {
    printf("precision de %d: %.*f\n", digitsPrecision, 100.453627,
           digitsPrecision);
    digitsPrecision++;
  }
  return 0;
}
