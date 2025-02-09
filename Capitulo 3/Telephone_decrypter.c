#include <stdio.h>
int main(){
  int tlf,num1,num2,num3,num4,temp = 0;
  printf("Please enter a  digits number: ");
  scanf("%d", &tlf);
  num1 = (tlf / 1000 + 2) % 10;
  num2 = ((tlf % 1000) / 100 + 3) % 10;
  num3 = ((tlf % 100) / 10 + 3) % 10;
  num4 = (tlf % 10 + 3);
  temp = num1;
  num1 = num3;
  num3 = temp;
  temp = num2;
  num2 = num4;
  num4 = temp;
  int encrypter = num1 * 1000 + num2 * 100 + num3 * 10 +  num4;
  printf("%d", encrypter);
  return 0;
 }
