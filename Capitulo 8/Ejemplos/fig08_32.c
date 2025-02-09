/* Figura 8.32: fig08_32.c
Uso de memmove */
#include <stdio.h>
#include <string.h>
int main() {
  char x[] = "Hogar Dulce Hogar"; /* inicializa el arreglo de caracteres x */
  printf("%s%s\n", "La cadena en el arreglo x antes de memmove es: ", x);
  printf("%s%s\n", "La cadena en el arreglo x despues de memmove es: ",
         memmove(x, &x[6], 11));
  return 0; /* indica terminación exitosa */
} /* fin de main */
