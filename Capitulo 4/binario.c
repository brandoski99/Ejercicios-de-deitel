#include <stdio.h>

int main(){
    int decimal = 28, binario = 0,temp = 0, multipli = 10000;
    while( decimal >= 1){
        temp = decimal / 2  % 2;
        decimal /= 10;
        binario +=  temp * multipli;
        multipli /= 10;
        printf("\n%d", binario);
    }
    printf("%d", binario);
    return 0;
 }
