#include <stdio.h>

int main(){
  int contador = 0;
  while(contador < 300000000){
    ++contador;
    if(contador % 100000000 == 0){
        printf("\n%d", contador);
    }
  }
  return 0;
 }
