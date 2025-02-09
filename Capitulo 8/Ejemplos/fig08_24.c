/* Figura 8.24: fig08_24.c
Uso de strcspn */
#include <stdio.h>
#include <string.h>

int main() {
  /* inicializa dos apuntadores a char */
  const char *cadena1 = "El valor es 3.14159";
  const char *cadena2 = "1234567890";
  printf("%s%s\n%s%s\n\n%s\n%s%u", "cadena1 = ", cadena1, "cadena2 = ", cadena2,
         "La longitud del segmento inicial de cadena1",
         "que no contiene caracteres de cadena2 = ", strcspn(cadena1, cadena2));
  return 0; /* indica terminación exitosa */
  /* fin de main */
}
