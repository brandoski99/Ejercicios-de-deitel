#include <stdio.h>

struct parte {
  int numeroParte;
  char nombreParte[25];
};
typedef struct parte Parte;

int main() {
  Parte a;
  Parte b[10];
  Parte *ptr;

  printf("Introduzca un numero y nombre de parte: \n");
  scanf("%d%24s", &a.numeroParte, a.nombreParte);
  b[3] = a;
  ptr = b;
  printf("El numero es: %d\nEl nombre es: %s\n", (ptr + 3)->numeroParte,
         (ptr + 3)->nombreParte);
  return 0;
}
