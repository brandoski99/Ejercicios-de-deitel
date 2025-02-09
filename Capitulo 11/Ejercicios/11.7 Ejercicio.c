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
    while (!feof(ptrTf)) {

      // Si algun cliente no hizo ninguna transaccion se escriben sus datos sin
      // modificar
      if (dataTrans.accountnumber != dataClient.accountnumber) {
        fprintf(ptrNf, "%d %s %s %.2lf\n", dataClient.accountnumber,
                dataClient.name, dataClient.lastname, dataClient.mount);
      }

      if (dataTrans.accountnumber == dataClient.accountnumber) {
        dataClient.mount += dataTrans.mount;
        // Escribir registro en el nuevo archivo maestro
        fprintf(ptrNf, "%d %s %s %.2lf\n", dataClient.accountnumber,
                dataClient.name, dataClient.lastname, dataClient.mount);

      } else if (dataTrans.mount != 0.0) {
        // Llenar los datos al no encontrar un registro
        printf("El registro de transaccion %d no coincide con alguna cuenta\n",
               dataTrans.accountnumber);
        fprintf(ptrNf, "%d %s %s %.2lf\n", dataTrans.accountnumber,
                dataTrans.name, dataTrans.lastname, dataTrans.mount);
      }
      fscanf(ptrOf, "%d%s%s%lf", &dataClient.accountnumber, dataClient.name,
             dataClient.lastname, &dataClient.mount);
      fscanf(ptrTf, "%d%lf", &dataTrans.accountnumber, &dataTrans.mount);
    }
  }
  return 0;
}
