#include <stdio.h>

struct client {
  int accountnumber;
  char name[15];
  char lastname[10];
  double mount;
};

int main() {
  struct client dataClient = {0, "", "", 0.0};
  struct client dataTrans = {0, "Unknown", "Unknown", 0.0};

  FILE *ptrOf = fopen("maesviej.dat", "r");
  FILE *ptrTf = fopen("trans.dat", "r");
  FILE *ptrNf = fopen("maesnuev.dat", "w");
  if (ptrOf == NULL || ptrTf == NULL || ptrNf == NULL) {
    printf("Uno de los archivos no se pudo abrir\n");
  } else {

    fscanf(ptrOf, "%d%s%s%lf", &dataClient.accountnumber, dataClient.name,
           dataClient.lastname, &dataClient.mount);
    fscanf(ptrTf, "%d%lf", &dataTrans.accountnumber, &dataTrans.mount);

    // printf("%d %s %s %lf\n", dataClient.accountnumber, dataClient.name,
    //       dataClient.lastname, dataClient.mount);
    // printf("%d %lf", dataTrans.accountnumber, dataTrans.mount);

    while (!feof(ptrOf)) {
      // Buscar entre todas las transacciones la cuenta actual
      while (!feof(ptrTf)) {
        if (dataClient.accountnumber == dataTrans.accountnumber) {
          dataClient.mount += dataTrans.mount;
        }
        fscanf(ptrTf, "%d%lf", &dataTrans.accountnumber, &dataTrans.mount);
      }
      fprintf(ptrNf, "%d\t%s\t%s\t%.2lf\n", dataClient.accountnumber,
              dataClient.name, dataClient.lastname, dataClient.mount);
      fscanf(ptrOf, "%d%s%s%lf", &dataClient.accountnumber, dataClient.name,
             dataClient.lastname, &dataClient.mount);
      rewind(ptrTf); // Empezar a leer de nuevo desde la primera transaccion
    }
  }
  return 0;
}
