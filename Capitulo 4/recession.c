#include <stdio.h>

int main(){
    int count = 1,account,limit,balance;
    while(count <= 3){
        printf("Account number: ");
        scanf("%d", &account);
        printf("Limit of credit: ");
        scanf("%d", &limit);
        printf("Balance: ");
        scanf("%d", &balance);
        if(limit / 2 < balance){
           printf("Customer %d has exceeded the credit limit: -%d\n", account, balance - limit / 2);
        }
        count++;
    }
   return 0;
 }
