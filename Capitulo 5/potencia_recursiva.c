#include <stdio.h>

int potencia(int base, int exponente);

int main(){
     printf("%d", potencia(3,4));
     return 0;
 }

int potencia(int base, int exponente){
    if(exponente == 1){
        return base;
    }

    return base * potencia(base, exponente - 1);
 }
