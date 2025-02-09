#include <stdio.h>

int main(){
    printf("Decimales\t Romanos");
    for(int i = 1; i <= 100; i++){
        printf("\n%5d", i);
        switch(i){
      case 1:
         printf("%15s", "I");
         break;
      case 2:
         printf("%15s", "II");
         break;
      case 3:
         printf("%15s", "III");
         break;
       }
    }
    return 0;
 }
