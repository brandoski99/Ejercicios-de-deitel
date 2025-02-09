/* Figura 9.5: fig09_05c */
/* Impresión de cadenas y caracteres */
#include <stdio.h>
int main() {
  char caracter = 'A';                  /* inicializa un char */
  char cadena[] = "Esta es una cadena"; /* inicializa el arreglo char */
  const char *ptrCadena = "Esta tambien es una cadena"; /* apuntador a char */
  printf("%c\n", caracter);
  printf("%s\n", "Esta es una cadena");
  printf("%s\n", cadena);
  printf("%s\n", ptrCadena);
  return 0; /* indica terminación exitosa */
} /* fin de main */
