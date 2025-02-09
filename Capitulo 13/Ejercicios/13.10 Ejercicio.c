#include <stdio.h>

#define SUM_ARRAY(array, elements)                                             \
  ({                                                                           \
    int sum = 0;                                                               \
    for (int i = 0; i < elements; i++)                                         \
      sum += array[i];                                                         \
    sum;                                                                       \
  })

int main() {
  int example[5] = {1, 2, 3, 4, 5};
  int n = sizeof(example) / sizeof(example[0]);
  printf("La suma es: %d\n", SUM_ARRAY(example, n));
  return 0;
}
