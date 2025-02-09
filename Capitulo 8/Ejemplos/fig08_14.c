/* Figura 8.14: fig08_14.c
Uso de getchar y puts */
#include <stdio.h>
int main() {

  char c; /* variable para almacenar los caracteres introducidos por el usuario
           */
  char enunciado[80]; /* crea un arreglo de caracteres */
  int i = 0;          /* inicializa el contador i */

  /* indica al usuario que introduzca una línea de texto */
  puts("Introduzca una linea de texto:");
  /* utiliza getchar para leer cada caracter */
  while ((c = getchar()) != '\n') {
    enunciado[i++] = c;
  } /* fin de while */
  enunciado[i] = '\0'; /* termina la cadena */
  /* utiliza puts para desplegar el enunciado */
  puts("\nLa linea introducida es :");
  puts(enunciado);
  return 0; /* indica terminación exitosa */
} /* fin de main */
