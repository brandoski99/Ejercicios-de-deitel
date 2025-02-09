/* Figura 8.13: fig08_13.c
Uso de gets y putchar */
#include <stdio.h>
void inverso(const char *const ptrS); /* prototipo */
int main() {
  char enunciado[80]; /* crea un arreglo de caracteres */
  printf("Introduzca una linea de texto:\n");
  /* utiliza gets para leer una línea de texto */
  gets(enunciado);
  printf("\nLa linea impresa al reves es:\n");
  inverso(enunciado);
  return 0; /* indica terminación exitosa */
} /* fin de main */
/* imprime recursivamente los caracteres de una cadena en orden inverso */
void inverso(const char *const ptrS) {
  /* si es el final de la cadena */
  if (ptrS[0] == '\0') { /* caso base */
    return;
  } /* fin de if */
  else {               /* si no es el final de la cadena */
    inverso(&ptrS[1]); /* paso recursivo */
    putchar(ptrS[0]);  /* utiliza putchar para desplegar los caracteres */
  } /* end else */
} /* fin de la función inverso */
