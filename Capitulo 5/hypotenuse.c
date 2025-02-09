#include <stdio.h>
#include <math.h>
double hypotenuse(double side1, double side2);

int main(){
    printf("%.1f\n", hypotenuse(3.0,4.0));
    printf("%.1f\n", hypotenuse(5.0,12.0));
    printf("%.1f\n", hypotenuse(8.0,15.0));
    return 0;
 }

double hypotenuse(double side1, double side2){
        double total = 0.0;
        total += pow(side1, 2) + pow(side2, 2);
        return sqrt(total);
  }
