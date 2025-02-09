#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char phonenumber[100];
  char area[4];
  char firstnumbers[4];
  char secondnumbers[5];
  char fullnumbers[20];
  printf("Introduzca el numero telefonico en el formato(555) 555-5555\n");
  fgets(phonenumber, sizeof(phonenumber), stdin);
  // Separa el codigo de area del numero telefonico
  strcpy(area, strtok(phonenumber, "()"));
  strcpy(firstnumbers, strtok(NULL, "-"));
  strcpy(secondnumbers, strtok(NULL, "-"));

  sprintf(fullnumbers, "%s%s", firstnumbers, secondnumbers);
  printf("\narea: %d\n", atoi(area));
  printf("Numero telefonico: %ld", atol(fullnumbers));
  return 0;
}
