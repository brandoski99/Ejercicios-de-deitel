#include <stdio.h>
float  celcius(float fahrenheit);
float  fahrenheit(float celcius);

int main(){
    printf("Celcius \t Fahrenheit \n");
    for(int i = 0; i <= 100; i++){
       printf("%d \t \t %.1f\n", i, fahrenheit(i));
    }
    return 0;
 }
float celcius(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
 }
float fahrenheit(float celcius){
    return (celcius * 9/5) + 32;
 }
