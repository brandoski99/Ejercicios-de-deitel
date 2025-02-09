#include <stdio.h>

#define MIN2(num1, num2) (num1) < (num2) ? (num1) : (num2)

#define MIN3(num1,num2,num3) MIN2(num1,num2) < (num3) ? MIN2(num1,num2) : (num3)

int main() {
  int number1, number2,number3;
  printf("Introduzca 3 numeros: ");
  scanf("%d %d %d", &number1, &number2, &number3);
  putchar('\n');
  printf("El valor mas pequenio es: %d\n", MIN3(number1, number2,number3));
  return 0;
}
