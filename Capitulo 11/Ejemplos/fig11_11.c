/* Figura 11.11: fig11_11.c
Creación secuencial de un archivo de acceso aleatorio*/
#include <stdio.h>
/* definición de la estructura datosCliente */
struct datosCliente {
  int numCta;
  /* número de cuenta */
  char apellido[15]; /* apellido de la cuenta */
  char nombre[10];
  /* nombre de la cuenta */
  double saldo;
  /* saldo de la cuenta */
}; /* fin de la estructura datosCliente */
int main() {
  int i; /* contador utilizado para contar de 1 a 100 */
  /* crea datosCliente con información predeterminada */
  struct datosCliente clienteEnBlanco = {0, "", "", 0.0};
  FILE *ptrCf; /* apuntador al archivo credito.dat */
  /* fopen abre el archivo; si no se puede abrir, sale del archivo */
  if ((ptrCf = fopen("credito.dat", "wb")) == NULL) {
    printf("No pudo abrirse el archivo.\n");
  } /* fin de if */
  else {
    /* escribe 100 registros en blanco en el archivo */
    for (i = 1; i <= 100; i++) {
      fwrite(&clienteEnBlanco, sizeof(struct datosCliente), 1, ptrCf);
    } /* fin de for */
    fclose(ptrCf); /* fclose cierra el archivo */
  } /* fin de else */
  return 0; /* indica terminación exitosa */
} /* fin de main */
