/* Figura 14.9: fig14_09.c
Uso de goto */
#include <stdio.h>
int main() {
  int cuenta = 1; /* inicializa cuenta */
inicio:           /* etiqueta */
  if (cuenta > 10) {
    goto fin;
  } /* fin de if */
  printf("%d ", cuenta);
  cuenta++;
  goto inicio; /* ve a (goto) inicio en la línea 6 */
fin:           /* etiqueta */
  putchar('\n');
  return 0; /* indica terminación exitosa */
}
