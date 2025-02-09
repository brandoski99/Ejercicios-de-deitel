#include <stdio.h>
#define TAMANIO 15

int busquedaBinaria(const int arreglo[], int claveDeBusqueda, int bajo, int alto);
void despliegaEncabezado(void);
void despliegaLinea(const int b[], int bajo, int medio, int alto);

int main(){
    int a[TAMANIO];
    int i;
    int llave;
    int resultado;

    for(i = 0; i < TAMANIO; i++){
        a[i] = i * 2;
    }
    printf("Introduzca un numero entero entre 0 y 28:\n");
    scanf("%d", &llave);

    despliegaEncabezado();

    resultado = busquedaBinaria(a, llave, 0, TAMANIO - 1);

    if(resultado != -1){
        printf("\n%d se encuentra en el elemento %d del arreglo\n",llave, resultado);
    }
    else{
        printf("\n%d No se encuentra\n", llave);
    }
    return 0;
 }

 int busquedaBinaria(const int arreglo[], int claveDeBusqueda, int bajo, int alto){
     int central;

     while(bajo <= alto){
        central = (bajo + alto) / 2;

     despliegaLinea(arreglo, bajo, central, alto);
     if(claveDeBusqueda == arreglo[central]){
        return central;
     }
     else if(claveDeBusqueda < arreglo[central]){
        alto = central - 1;
     }
     else{
        bajo = central + 1;
     }
  }
     return -1;
}


void despliegaEncabezado(void){
     int i;

     printf("\nSubindices:\n");
     for(i = 0; i < TAMANIO; i++){
        printf("%3d ", i);
     }
     printf("\n");
     for(i = 0; i <= 4 * TAMANIO; i++){
        printf("-");
     }
     printf("\n");
 }

void despliegaLinea(const int b[], int bajo, int medio, int alto){
     int i;

     for(i = 0; i < TAMANIO; i++){
        if(i < bajo || i > alto){
            printf("     ");
        }
        else if(i == medio){
            printf("%3d*", b[i]);
        }
        else{
            printf("%3d ", b[i]);
        }
     }
     printf("\n");
 }
