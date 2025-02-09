#include <stdio.h>
#include <math.h>

// todas las funciones de la libreria math.h  reciben  y devuelven argumentos del tipo double

int main(){
    printf("raiz cuadrada: %.2f\n", sqrt(900.0)); //raiz cuadrada de x

    printf("funcion exponencial: %.5f\n", exp(1.0));  // funcion exponencial e^x

    printf("logaritmo natural: %.2f\n", log(2.718282)); // logaritmo natural de x (base e)

    printf("logaritmo base 10: %.2f\n", log10(100)); // logaritmo de x (base 10)

    printf("valor absoluto: %.2f\n", fabs(-5.0)); // valor absoluto de x

    printf("redondea a numero mayor: %.2f\n", ceil(9.2)); // redondea x al entero mas pequeño no menor que x

    printf("redondea a numero menor: %.2f\n", floor(9.2)); // redondea x al entero mas grande no mayor que x

    printf("potencia: %.2f\n", pow(2, 7)); // recibe dos argumentos pow(double x, double y) en donde x es elevado a la potencia de y

    printf("residuo: %.2f\n", fmod(13.6, 2.3)); // residuo de x/y como un numero de punto flotante

    printf("seno: %.2f\n", sin(0.0)); // seno trigonometrico de x (x en radianes)

    printf("coseno: %.2f\n", cos(0.0)); // coseno trigonometrico de x (x en radianes)

    printf("tangente: %.2f\n", tan(0.0)); // tangente trigonometrica de x (x en radianes)
   return 0;
 }
