#include <stdio.h>
int main(){
    float a,b,c;
    float A,B,C;
    float hip = 0;
    int T = 0;
    printf("introduzca los angulos del triangulo recto:");
    scanf("%f%f%f", &a,&b,&c);
    if(a + b + c == 180){
        printf("\nSi puede representar los angulos de un triangulo recto");
        T++;
    } else{
        printf("La suma de los angulos no es 180");
    }
   if(T){
    printf("\nIntroduzca los lados de un triangulo recto: ");
    scanf("%f%f%f", &A,&B,&C);
    if (C > B && C > A){
        printf("Si puede representar los lados de un triangulo recto");
        hip = C;
    }
    else  if (A > B &&  A > C){
        printf("Si puede representar los lados de un triangulo recto");
        hip = A;
    }
    else  if (B > A &&  B > C){
        printf("Si puede representar los lados de un triangulo recto");
        hip = B;
    }
    else{
        printf("Introduzca lados validos");
    }
   }
   if(hip)
      printf("\nLos angulos de su triangulo recto son: %.1f %.1f %.1f \ny su hipotenusa es: %.1f", a,b,c,hip);
 return 0;
 }
