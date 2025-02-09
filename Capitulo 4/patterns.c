#include <stdio.h>

int main(){

    printf("A)\n");
    for(int c = 0; c <= 10; c++){
        for(int j = 0; j < c; j++){
            printf("*");
        }
        printf("\n");
    }

    printf("B)\n");
    for(int c = 10; c >= 0; c--){
        for(int j = 0; j < c; j++){
            printf("*");
        }
        printf("\n");
    }

    printf("C)\n");
    for(int i = 0; i <= 10; i++){
        for(int s = 0; s <= i; s++){
            printf(" ");
        }
        for(int k = i; k < 10; k++){
            printf("*");
        }
        printf("\n");
    }

    printf("D)\n");
    for(int i = 10; i >= 0; i--){
        for(int s = 0; s <= i; s++){
            printf(" ");
        }
        for(int k = i; k < 10; k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
 }
