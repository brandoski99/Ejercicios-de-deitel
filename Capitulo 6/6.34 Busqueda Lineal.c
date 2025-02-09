#include <stdio.h>
int linealSearch(int arr[], int length,int key,int pos);
int main(){
    int example[100];
    for(int i = 0; i < 100; i++){
        example[i] = i * 2;
    }
    if(linealSearch(example,100,18,0) == -1){
        printf("No se encontro el elemento");
    }
    return 0;
 }
int linealSearch(int arr[], int length,int key,int pos){
    if(arr[pos] == key){
        printf("El elemento se encontro en la posicion [%d] del arreglo\n", pos);
        return 0;
    }
    if(pos >= length){
        return -1;
    }
    else{
       return linealSearch(arr,length,key,pos+1);
    }
 }
