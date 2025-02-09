#include <stdio.h>

int reverse(int num);

int main(){
   reverse(7823);
 }


int reverse(int num){
    while(num >= 1){
          printf("%d", num % 10);
          num /= 10;
    }
 }
