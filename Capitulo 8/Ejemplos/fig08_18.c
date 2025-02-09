/* Figura 8.18: fig08_18.c
Uso de strcpy y strncpy */
#include <stdio.h>
#include <string.h>
int main() {
  char x[] = "Feliz cumpleanios a ti"; /* inicializa el arreglo de
  caracteres x */
  char y[25];                          /* crea el arreglo de caracteres y */
  char z[15];                          /* crea el arreglo de caracteres z */
  /* contenido de la copia de x en y */
  printf("%s%s\n%s%s\n", "La cadena en el arreglo x es: ", x,
         "La cadena en el arreglo y es: ", strcpy(y, x));
  /* copia los primeros 17 caracteres de x dentro de z. No copia el
  caracter nulo */
  strncpy(z, x, 17);
  z[17] = '\0'; /* termina la cadena en z */
  printf("La cadena en el arreglo z es: %s\n", z);
  return 0; /* indica terminación exitosa */
} /* fin de main */
