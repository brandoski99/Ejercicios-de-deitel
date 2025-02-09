#include<stdio.h>

int main(){
   int num,count = 0;
   scanf("%d", &num);
   while(num > 0){
     if(num % 10 == 7){
        count++;
     }
     num /= 10;
   }
   printf("total de sietes: %d", count);
 return 0;
 }
