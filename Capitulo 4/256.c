#include <stdio.h>

int main(){
    int count;
    printf("Decimal\tBinario\tOctal\tHexadecimal\n");
    for(count = 0; count <= 1; count++)
        printf("%4d%7d%9o%11x\n", count,count,count,count);
    for(;count <= 256; count++)
        printf("%4d%16o%11x\n", count,count,count);
    return 0;
 }
