#include <stdio.h>

int main(){
  float num,fac = 1;
  float e = 1;
  int n = 1e6;
  num = 1;
  while(num <= n){
    fac *= num;
    e += 1.0/fac;
    num++;
  }
  printf("valor de e = %f\n", e);
}
