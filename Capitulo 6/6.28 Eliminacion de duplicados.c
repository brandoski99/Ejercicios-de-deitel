/*
 (Eliminación de duplicados.) En el capítulo 12, se explora la estructura de datos árbol de búsqueda binaria de alta
velocidad. Una característica del árbol de búsqueda binaria es que los valores duplicados se descartan cuando se
hacen inserciones en el árbol. A esto se le conoce como eliminación de duplicados. Escriba un programa que produzca
20 números aleatorios entre 1 y 20. El programa debe almacenar en un arreglo todos los valores no duplicados.
Utilice el arreglo más pequeño posible para llevar a cabo esta tarea.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void printArray(int a[], int length);

int main(){
    srand(time(NULL));
    int randN;
    int nDuplicates[N] = {0};
    int notRepeat = 0;
    for(int i = 0;  i < N; i++){
        randN = 1 + rand() % N; //Generador de numeros aleatorios
        if(!nDuplicates[randN - 1]){ //Se verifica si la posicion del numero no ha sido asignada, con el fin de ver si ya se hicieron inserciones en dicha posicion
            nDuplicates[randN - 1] = randN;
            notRepeat++;
        }
    }
    int eraseDuplicates[notRepeat];
    for(int j = 0,i = 0; j < N && i < notRepeat; j++){
        if(nDuplicates[j]){
            eraseDuplicates[i] = nDuplicates[j];
            i++;
        }
    }
    printArray(eraseDuplicates, notRepeat);
    return 0;
 }

void printArray(int a[], int length){
     for(int i = 0; i < length; i++){
        printf("%-3d", a[i]);
     }
     printf("\n");
}
