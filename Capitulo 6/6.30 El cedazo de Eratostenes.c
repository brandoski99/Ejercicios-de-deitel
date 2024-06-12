#include <stdio.h>
#define N 1000
void initializeArray(int a[], int length);

int main(){
    int primeNumbers[N];
    initializeArray(primeNumbers, N);
    for(int count = 2; count * count < N; count++){
        if(primeNumbers[count]){
            for(int noPrime = count * count; noPrime < N; noPrime += count){
                primeNumbers[noPrime] = 0;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(primeNumbers[i]){
            printf("%d ", i);
        }
    }
    return 0;
 }

void initializeArray(int a[], int length){
     for(int i = 2; i < length; i++){
        a[i] = 1;
     }
 }
