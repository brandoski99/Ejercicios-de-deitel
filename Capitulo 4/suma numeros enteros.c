#include <stdio.h>

int main(){
    int x, count = 1, sum = 0;
    scanf("%d", &x);
    while(count <= x){
        sum += count++ * 100;
    }
    printf("%d", sum);
  return 0;
 }
