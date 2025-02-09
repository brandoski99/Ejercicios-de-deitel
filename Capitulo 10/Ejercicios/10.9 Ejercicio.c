#include <stdio.h>

union puntoFlotante {
  float f;
  double d;
  long double x;
};
int main() {
  union puntoFlotante test;
  printf("Introduzca los valores de tipo float,double,long double:\n");

  scanf("%f %lf %Lf", &test.f, &test.d, &test.x);

  printf("Los valores son:\nfloat f = %f\ndouble d = %lf\nlong double x = %Lf",
         test.f, test.d, test.x);
  return 0;
}
