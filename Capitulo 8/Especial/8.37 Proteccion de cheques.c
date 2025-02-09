#include <stdio.h>
#include <string.h>

#define SPACES 10
void protecBill(char *bill);

int main() {
  char bill[SPACES];
  printf("Introduzca el monto del cheque\n");
  fgets(bill, sizeof(bill), stdin);
  putchar('\n');
  protecBill(bill);
  return 0;
}

void protecBill(char *bill) {
  int lenBil = strlen(bill);

  if (lenBil == SPACES - 1) {
    printf("\n%s\n", bill);
  } else {
    // Imprime los asteriscos
    for (int i = 0; i <= SPACES - lenBil - 1; i++) {
      printf("*");
    }
    // Imprime el monto
    printf("%s\n", bill);
  }

  // Numero de espacios
  printf("---------\n");
  printf("123456789\n");
}
