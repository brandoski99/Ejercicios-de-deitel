#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
  for(int count = 1; count <= 5; count++){
    int n = 2 + rand() % 10;
    if( n % 2 == 0 )
       printf("%d %d %d %d %d \n", n,n,n,n,n);
    n = 1 + rand() % 10;
    if (n % 2 == 1)
       printf("%d %d %d %d %d \n", n,n,n,n,n);
    n = 6 + rand() % 22;
    if ( n % 4 == 0)
        printf("%d %d %d %d %d \n", n,n,n,n,n);
  }
    return 0;
 }
