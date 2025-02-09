#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];
  unsigned int numchar;
  scanf("%99s%99s", str1, str2);
  printf("\nCuantos caracteres desea comparar?: ");
  scanf("%u", &numchar);
  if (strncmp(str1, str2, numchar) == 0) {
    printf("\nLas 2 cadenas son iguales");
  } else if (strncmp(str1, str2, numchar) > 0) {
    printf("\nLa cadena 1 es mayor que la cadena 2");
  } else {
    printf("\n La cadena 1 es menor que la cadena 2");
  }
  return 0;
}
