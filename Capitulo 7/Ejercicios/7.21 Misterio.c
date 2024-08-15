/* ej07_21.c */
/* ¿Qué hace este programa? */
/* El programa toma 2 cadenas y las une en cadena1[80]*/
#include <stdio.h>
void misterio1(char *s1, const char *s2); /* prototipo */
int main() {
  char cadena1[80]; /* crea un arreglo de caracteres */
  char cadena2[80]; /* crea un arreglo de caracteres */
  printf("Introduce dos cadenas : ");
  scanf("%s %s", cadena1, cadena2);
  misterio1(cadena1, cadena2);
  printf("%s\n", cadena1);

  return 0; /* indica terminación exitosa */

} /* fin de main */
/* ¿Qué hace esta función ? */
void misterio1(char *s1, const char *s2) {
  /* Mientras que cadena s1 no llegue a '\0' seguira avanzando caracter por
   * caracter*/
  while (*s1 != '\0') {
    s1++;

  } /* fin de while */
  /* Una vez que cadena s1 llega a '\0', se empezara agregar a los espacios
   * restantes los caracteres de cadena s2 */

  for (; *s1 = *s2; s1++, s2++) {
    /* instrucción vacía */

  } /* fin de for */

} /* fin de la función misterio1 */
