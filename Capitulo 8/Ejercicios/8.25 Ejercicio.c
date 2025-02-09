#include <stdio.h>

int main() {
  /*
 int ascii;
  printf("Introduzca un numero entre 0 y 255 y vea que caracter ASCII "
        "representa: ");
 scanf("%d", &ascii);
 printf("\nSu numero en ASCII representa al caracter: %c\n", ascii);
 */

  for (int i = 0; i <= 255; i++) {
    printf("El numero %d en ASCII es el caracter: %c\n", i, i);
  }
  return 0;
}
