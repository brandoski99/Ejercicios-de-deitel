/* Figura 8.27: fig08_27.c
Uso de strspn */
#include <stdio.h>
#include <string.h>
int main() {
  /* inicializa dos apuntadores a char */
  const char *cadena1 = "El valor es 3.14159";
  const char *cadena2 = "aelv lsEro";

  printf("%s%s\n%s%s\n\n%s\n%s%u\n", "cadena1 = ", cadena1,
         "cadena2 = ", cadena2, "La longitud del segmento inicial de cadena1",
         "que contiene solamente caracteres de cadena2 = ",
         strspn(cadena1, cadena2));
  return 0; /* indica terminación exitosa */
} /* fin de main */
