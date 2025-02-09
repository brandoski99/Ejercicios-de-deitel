/* Figura 8.31: fig08_31.c
Uso de memcpy */
#include <stdio.h>
#include <string.h>
int main() {
  char s1[17];
  /* crea el arreglo de carateres s1 */
  char s2[] = "Copia esta cadena"; /* inicializa el arreglo de caracteres s2 */
  memcpy(s1, s2, 18);
  printf("%s\n%s\"%s\"\n", "Despues de la copia de s2 en s1 con memcpy,",
         "s1 contiene ", s1);
  return 0; /* indica terminación exitosa */
} /* fin de main */
