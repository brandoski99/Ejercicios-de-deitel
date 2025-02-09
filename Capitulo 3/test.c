#include <stdio.h>

int main(){
  int n,f,c;
  printf("Please enter an number: ");
  scanf("%d", &f);
  n = 1;
  c = 1;
if (!(f == 1  || f == 0)){
  while(f >= c){
    printf("\nFactorial of %d is %d", c, n );
    n *= ++c;
  }
}
else{
   printf("\nFactorial of %d is 1", f);
 }
  return 0;
}
