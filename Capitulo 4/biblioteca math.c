#include <stdio.h>
#include <math.h>

int main(){
    double monto;
    double principal = 1000.0;
    double tasa = .05;
    int anio;

    printf("%4s%21s\n", "Anio", "Monto del deposito");
    for(anio = 1; anio <= 10; anio++){
        monto = principal * pow(1.0 + tasa, anio);

        printf("%4d%21.2f\n", anio, monto);
    }
 }
