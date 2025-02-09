#include <stdio.h>

int main(){
    int fac, count = 1;
    int num = 1;
    printf("Introduzca un numero para factorial: ");
    scanf("%d", &fac);
    if (fac > 1){
        while(fac >= count){
            printf(" %d! = %d ", count, num);
            num *= ++count;
            if(count == 12)
               printf("\n");
        }
    }
        else
            printf("%d! = 1", fac);

    return 0;
 }
