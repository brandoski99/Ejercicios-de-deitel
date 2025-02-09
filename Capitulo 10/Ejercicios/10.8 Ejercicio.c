#include <stdio.h>

union entero {
  char c;
  short s;
  int i;
  long b;
};

int main() {
  union entero test;
  printf("Introduzca un valor char, un valor short, un valor entero, y un "
         "valor long:\n");

  scanf("%c %hd %i %ld", &test.c, &test.s, &test.i, &test.b);

  printf(
      "Los valores son:\nchar c = %c\nshort s = %hd\nint i = %d\n long b = %ld",
      test.c, test.s, test.i, test.b);
  return 0;
}
