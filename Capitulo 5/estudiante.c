#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int student;
    int num1 = 1 + rand() % 10;
    int num2 = 1 + rand() % 10;
    int total = num1 * num2;

    printf("Cuanto es %d x %d?\n", num1,num2);
    scanf("%d", &student);
     if(student == total){
          printf("¡Muy Bien!\n");
        }
    while(student != total){
         printf("No, Porfavor intenta otra vez\n");
          scanf("%d", &student);
        if(student == total){
          printf("!Muy Bien!");
        }
    }
    return 0;
 }
