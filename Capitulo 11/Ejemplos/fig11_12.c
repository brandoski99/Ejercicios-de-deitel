/* Figura 11.12: fig11_12.c
Escritura en un archivo de acceso aleatorio */
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
  FILE *ptrCf; /* apuntador al archivo credito.dat */
  /* crea datosCliente con información predeterminada */
  struct datosCliente cliente = {0, "", "", 0.0};
  /* fopen abre el archivo; si no lo puede abrir, sale del archivo */
  if ((ptrCf = fopen("credito.dat", "rb+")) == NULL) {
    printf("El archivo no pudo abrirse.\n");
  } /* fin de if */
  else { /* se requiere que el usuario especifique el número de cuenta */
    printf("Introduzca el numero de cuenta"
           " ( 1 a 100, 0 para terminar la entrada )\n? ");
    scanf("%d", &cliente.numCta);
    /* el usuario introduce la información, la cual se copia dentro del
    archivo */
    while (cliente.numCta != 0) {
      /* el usuario introduce el apellido, el nombre y el saldo */
      printf("Introduzca el apellido, el nombre, el saldo\n? ");
      /* establece los valores para apellido, nombre y saldo del
      registro */
      fscanf(stdin, "%s%s%lf", cliente.apellido, cliente.nombre,
             &cliente.saldo);
      /* localiza la posición de un registro específico en el archivo */
      fseek(ptrCf, (cliente.numCta - 1) * sizeof(struct datosCliente),
            SEEK_SET);
      /* escribe en el archivo la información especificada por el
      usuario */
      fwrite(&cliente, sizeof(struct datosCliente), 1, ptrCf);
      /* permite al usuario introducir otro número de cuenta */
      printf("Introduzca el numero de cuenta\n? ");
      scanf("%d", &cliente.numCta);
    } /* fin de while */
    fclose(ptrCf); /* fclose cierra el archivo */
  } /* fin de else */
  return 0; /* indica terminación exitosa */
} /* fin de main */
