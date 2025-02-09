#include <stdio.h>

int maximo(int x,int y, int z);

int main(){
    int numero1,numero2,numero3;

    scanf("%d%d%d", &numero1, &numero2, &numero3);
    printf("el numero maximo es: %d\n ", maximo(numero1,numero2,numero3) );
    return 0;
 }

 int maximo(int x,int y, int z){
     int max = x;

     if(y > max)
        max = y;

     if(z > max)
        max = z;

     return max;
   }
