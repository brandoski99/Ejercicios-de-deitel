/* Figura 8.38: fig08_38.c
Uso de strlen */
#include <stdio.h>
#include <string.h>
int main() {
  /* inicializa los 3 apuntadores a char */
  const char *cadena1 = "abcdefghijklmnopqrstuvwxyz";
  const char *cadena2 = "cuatro";
  const char *cadena3 = "Mexico";
  printf("%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n", "La longitud de ",
         cadena1, " es ", (unsigned long)strlen(cadena1), "La longitud de ",
         cadena2, " es ", (unsigned long)strlen(cadena2), "La longitud de ",
         cadena3, " es ", (unsigned long)strlen(cadena3));
  return 0; /* indica terminación exitosa */
} /* fin de main */
