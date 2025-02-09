#include <stdio.h>

int main(){
    int n,sum = 0, count = 1,num;
    printf("Introduzca la cantidad de numeros que va a sumar: ");
    scanf("%d", &n);
    while(count <= n){
        printf("\nIntroduzca los numeros a sumar: ");
        scanf("%d", &num);
        sum += num;
        count++;
    }
    printf("total = %d", sum);
    return 0;
 }

 8
