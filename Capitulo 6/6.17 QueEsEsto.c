#include <stdio.h>
#define TAMANIO 10

int queEsEsto(const int b[], int p);
int main(){
    int x;

    int a[TAMANIO] = {1,2,3,4,5,6,7,8,9,10};

    x = queEsEsto(a, TAMANIO);

    printf("El resultado es %d\n", x);

    return 0;
 }


int queEsEsto(const int b[], int p){
    if(p == 1)
        return b[0];

    else
        return b[p - 1] + queEsEsto(b, p - 1);
 }
