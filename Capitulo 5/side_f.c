#include <stdio.h>

int draw(int side,int letter);

int main(){
    draw(8, 78);
    draw(4, 63);
    return 0;
 }

int draw(int side,int letter){
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){
            printf("%c", letter );
        }
        printf("\n");
    }
    printf("\n");

 }
