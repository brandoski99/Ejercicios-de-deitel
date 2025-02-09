#include <stdio.h>

int main(){
    int vendedores[9] = {200,300,400,500,600,700,800,900,1000};
    int comision;
    for(int i = 0; i < 9; i++){
        comision = vendedores[i] * 9 / 100;
        printf("vendedores[%d] = %d\n",i, vendedores[i] + 200 + comision  );
    }
    return 0;
 }
