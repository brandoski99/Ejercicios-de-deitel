#include <stdio.h>

double distancia(double x1,double y1, double x2, double y2);

int main(){
    distancia(23,32,39,29);
   return 0;
 }


double distancia(double x1,double y1, double x2, double y2){
       if(x1 - x2 <= 0){
         printf("distancia entre x1 y x2 es de: %.1f\n", x2 - x1);
       }
       else
         printf("distancia entre x1 y x2 es de: %.1f\n", x1 - x2);
       if(y1 - y2 <= 0){
         printf("distancia entre y1 y y2 es de: %.1f\n", y2 - y1);
       }
       else
         printf("distancia entre y1 y y2 es de: %.1f\n", y1 - y2);
 }
