#include <stdio.h>

int main(){
    int x, sum = 0;
    for(x = 0; x <= 30; x += 2){
        sum += x;
        printf("%d\n", sum);
    }
    printf("suma total: %d", sum);
  return 0;
 }
