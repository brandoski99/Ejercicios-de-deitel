#include <stdio.h>

int main(){
    int n = 1;
    int result = 1;
    while(n <= 15){
        printf("%d x ", n);
        result *= n;
        n += 2;
    }
    printf("= %d", result);
    return 0;
 }
