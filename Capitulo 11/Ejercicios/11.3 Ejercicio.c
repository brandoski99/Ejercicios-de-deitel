#include <stdio.h>

typedef struct {
  int numCuenta;
  float montoMoneda;
} Cuenta;

int main() {
  FILE *ptrF;
  FILE *ptrTF;
  FILE *ptrN;

  int numCuenta;
  char nombre[15];
  float saldoActual;

  Cuenta trans;
  Cuenta maesnuev = {12, 10.01};

  if ((ptrF = fopen("maesviej.dat", "r")) == NULL) {
    printf("No se pudo abrir el archivo\n");
  } else {
    fscanf(ptrF, "%d%14s%f", &numCuenta, nombre, &saldoActual);
    fclose(ptrF);
  }

  if ((ptrTF = fopen("trans.dat", "r")) == NULL) {
    printf("No se pudo abrir el archivo\n");
  } else {
    fscanf(ptrTF, "%d%f", &trans.numCuenta, &trans.montoMoneda);
    fclose(ptrTF);
  }

  if ((ptrN = fopen("maesnuev.dat", "w")) == NULL) {
    printf("No se pudo abrir el archivo\n");
  } else {
    fprintf(ptrN, "%d%f", maesnuev.numCuenta, maesnuev.montoMoneda);
    fclose(ptrN);
  }

  return 0;
}
