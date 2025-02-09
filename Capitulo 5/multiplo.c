#include <stdio.h>

int multiplo(int num1,int num2);

int main(){
    printf("%d", multiplo(6,3));
    return 0;
 }

int multiplo(int num1,int num2){
    if(num1 % num2 == 0)
        return 1;

    else
        return 0;
 }
