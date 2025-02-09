/* Figura 9.7: fig09_07.c */
/* Uso de los especificadores de conversión p, n, y % */
#include <stdio.h>
int main() {
  int *ptr;
  /* define un apuntador a un int */
  int x = 12345; /* inicializa int x */
  int y;         /* define int y */

  ptr = &x;
  /* asigna a ptr la dirección de x */
  printf("El valor de ptr es %p\n", ptr);
  printf("La direccion de x es %p\n\n", &x);
  printf("Total de caracteres impresos en esta linea:%n", &y);
  printf(" %d\n\n", y);
  y = printf("Esta linea tiene 30 caracteres\n");
  printf(" se imprimieron %d caracteres\n\n", y);
  printf("Impresion de %% en una cadena de control de formato\n");
  return 0; /* indica terminación exitosa */
} /* fin de main */
