#include <stdio.h>

int main(){
 int count = 0, c = 1;
 while(count < 64){
    ++count;
    printf("* ");
    if (count % 8 == 0){
        printf("\n");
        c++;
        if(c % 2 == 0)
            printf(" ");
        }
    }



 return 0;
}

