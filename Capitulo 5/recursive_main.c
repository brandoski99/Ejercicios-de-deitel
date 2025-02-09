#include <stdio.h>

int main(){
    static int cuenta = 0;
    cuenta++;
    printf("%d\n", cuenta);
    if(cuenta < 50)
    main();
 }
