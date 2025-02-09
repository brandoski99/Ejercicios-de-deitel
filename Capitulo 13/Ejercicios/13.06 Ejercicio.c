#include <stdio.h>

#define MIN2(num1, num2) (num1) < (num2) ? (num1) : (num2)

int main() {
  int number1, number2;
  printf("Introduzca 2 numeros: ");
  scanf("%d %d", &number1, &number2);
  putchar('\n');
  printf("El valor mas pequenio es: %d\n", MIN2(number1, number2));
  return 0;
}
