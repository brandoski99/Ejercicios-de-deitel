#include <stdio.h>

int misterio(int a, int b);

int main(){
    int x;
    int y;

    printf("Introduzca 2 enteros: ");
    scanf("%d%d", &x, &y);

    printf("\n El resultado es = %d\n", misterio(x,y));

    return 0;
 }

int misterio(int a, int b){
    if(1 == b){
        return a;
    }

    else{
        return a + misterio(a, b - 1);
    }
 }
