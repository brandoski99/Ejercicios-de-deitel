#include <stdio.h>

#define PI 3.14159
#define SPHERE_VOLUME(radius) (4.0 / 3) * (PI) * ((radius * radius * radius))

int main() {
  printf("\tVOLUMEN DE UNA ESFERA\n");
  printf("\tRadios\t\tVolumen\n");
  for (int i = 1; i <= 10; i++) {
    printf("\t%d\t\t%.2f\n", i, SPHERE_VOLUME(i));
  }
  return 0;
}
