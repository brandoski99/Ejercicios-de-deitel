#include <stdio.h>

int main(){
    int a;
    int *ptrA;

    a = 7;
    ptrA = &a;

    printf("La direccion de a es: %p\nEl valor de ptrA es: %p\n\n", &a, ptrA);

    printf("El valor de a es %d \nel valor de *ptrA es %d\n\n", a, *ptrA);

    printf("Muestra de que * y & son complementos uno del otro\n&*ptrA = %p\n*&ptrA = %p", &*ptrA, *&ptrA);
  return 0;
}
