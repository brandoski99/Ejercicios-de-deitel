#include <stdio.h>

#define PRINT_ARRAY(array, elements)                                           \
  for (int i = 0; i < (elements); i++)                                         \
    printf("%d\t", array[i]);

int main() {
  int example[5] = {2, 5, 203, 21, 2};
  PRINT_ARRAY(example, 5)
  return 0;
}
