#include <stdio.h>

int main(){
    int products = 0, count = -1;
    float total = 0.0;
    printf("Enter the products sold  today, enter EOF to exit: ");
    while(products != EOF){
        scanf("%d", &products);
        count++;
        switch(products){
           case 1:
              total += 2.98;
              break;
           case 2:
              total += 4.50;
              break;
           case 3:
              total += 9.98;
              break;
           case 4:
              total += 4.49;
              break;
           case 5:
              total += 6.87;
              break;
         }
    }
    printf("Products sold: %d\n", count);
    printf("Profit: %.2f", total);
    return 0;
 }
