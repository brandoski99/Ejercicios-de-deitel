#include <stdio.h>
#define TAMANIO 10

int main(){
    int s[TAMANIO];
    int j;

    for(j = 0; j < TAMANIO; j++){
        s[j] = 2 + 2 * j;
    }
    printf("%s%13s\n", "Elemento", "Valor");

    for(j = 0; j < TAMANIO; j++){
        printf("%7d%13d\n", j , s[j]);
    }
    return 0;
 }
