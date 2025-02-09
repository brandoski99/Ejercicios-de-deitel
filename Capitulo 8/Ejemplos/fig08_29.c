/* Figura 8.29: fig08_29.c
Uso de strtok */
#include <stdio.h>
#include <string.h>
int main() {
  /* inicializa el arreglo cadena */
  char cadena[] = "Este es un enunciado con 7 tokens";
  char *ptrToken; /* crea un apuntador char */
  printf("%s\n%s\n\n%s\n", "La cadena a dividir en tokens es:", cadena,
         "Los tokens son:");
  ptrToken = strtok(cadena, " "); /* comienza la división del enunciado
en tokens */
  /* continua la división en tokens, hasta que ptrToken se hace NULL */
  while (ptrToken != NULL) {
    printf("%s\n", ptrToken);
    ptrToken = strtok(NULL, " "); /* obtiene el siguiente token */
  } /* fin de while */
  return 0; /* indica terminación exitosa */
} /* fin de main */
