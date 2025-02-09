#include <stdio.h>

int main(){
    int a,b,c,count = 0;
    for( c = 1; c <= 500; c++ ){
        for( a = 1; a < c; a++){
            for( b = 1; b < a; b++){
                if((c * c) == (a * a) + (b * b)  && c * c <= 500){
                    printf("\n%d + %d = %d", (a * a), (b * b),(c * c ));
                    count++;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
 }
