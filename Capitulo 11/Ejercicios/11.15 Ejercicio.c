#include <stdio.h>
#include <time.h>
int main() {

  char c; /* variable para almacenar los caracteres introducidos por el usuario
           */
  char enunciado[80]; /* crea un arreglo de caracteres */
  int i = 0;          /* inicializa el contador i */
  int option = 0;
  printf(
      "1-Escribir desde i/o estandar\n2-Escribir desde archivos asignados\n");
  scanf("%d", &option);
  switch (option) {
  case 1:
    fputs("Introduzca una linea de texto: ", stdout);
    /* utiliza getchar para leer cada caracter */
    while ((c = fgetc(stdin)) != '\n') {
      enunciado[i++] = c;
    } /* fin de while */
    enunciado[i] = '\0'; /* termina la cadena */
    /* utiliza puts para desplegar el enunciado */
    fputs("\nLa linea introducida es :\n", stdout);
    fputs(enunciado, stdout);
    break;
  case 2:
    char inputName[20];
    char outName[20];
    printf("\nIntroduzca el nombre de archivo de entrada: ");
    scanf("%s", inputName);
    putchar('\n');
    printf("Introduzca el nombre de archivo de salida: ");
    scanf("%s", outName);
    putchar('\n');
    FILE *inputFile = fopen(inputName, "r");
    FILE *outFile = fopen(outName, "w");
    if (inputFile != NULL && outFile != NULL) {
      fgets(enunciado, sizeof(enunciado), inputFile);
      fputs("\nLa linea introducida es : ", outFile);
      fputs(enunciado, outFile);
    }
    break;
  default:
    printf("Opcion invalidad!\n");
  }
  return 0; /* indica terminación exitosa */
} /* fin de main */
