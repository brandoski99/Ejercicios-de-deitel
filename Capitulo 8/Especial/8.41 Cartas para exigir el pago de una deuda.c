#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main() {
  char name[SIZE];
  char address[SIZE];
  char accountID[SIZE];
  char mount[SIZE];
  char time[SIZE];

  // A
  printf("Nombre del deudor: ");
  fgets(name, sizeof(name), stdin);
  // B
  printf("\nDireccion del deudor del deudor: ");
  fgets(address, sizeof(address), stdin);
  // C
  printf("\nNumero de cuenta del deudor del deudor: ");
  fgets(accountID, sizeof(accountID), stdin);
  // D
  printf("\nMonto de la deuda: ");
  fgets(mount, sizeof(mount), stdin);
  // E
  printf("\nTiempo del monto de la deuda: ");
  fgets(time, sizeof(time), stdin);

  // Dunning
  char *typedate;
  int timelong = 0;
  int letterGrade = 0;
  strtol(time, &typedate, timelong);
  // Dias
  if (strcmp(typedate, "Dias") == 0) {
    letterGrade = 1; // Si son dias la carta sera de nivel 1
  }
  // Semanas
  if (strcmp(typedate, "Semanas") == 0) {
    if (timelong <= 4) {
      letterGrade = 1;
    }

    // de 1 mes a 2 meses y medio
    else if (timelong > 4 && timelong < 10) {
      letterGrade = 2;
    }

    // de 2 meses y medio a 4 meses y medio
    else if (timelong > 10 && timelong < 20) {
      letterGrade = 3;
    }
    // de 4 meses y medio a 6 meses
    else if (timelong > 20 && timelong < 27) {
      letterGrade = 4;
    }

    // De 6 meses en adelante
    else {
      letterGrade = 5;
    }
  }

  if (strcmp(typedate, "Meses") == 0) {
    if (timelong <= 1) {
      letterGrade = 1;
    }

    else if (timelong > 1 && timelong < 3) {
      letterGrade = 2;
    }

    else if (timelong > 3 && timelong < 5) {
      letterGrade = 3;
    } else if (timelong > 4 && timelong <= 6) {
      letterGrade = 4;
    }

    else {
      letterGrade = 5;
    }
  }
  return 0;
}
