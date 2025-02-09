/* Figura 9.24: fig09_24.c */
/* Lectura y descarte de caracteres desde el flujo de entrada */
#include <stdio.h>
int main() {
  int mes1;  /* define mes1 */
  int dia1;  /* define dia1 */
  int anio1; /* define anio1 */

  int mes2;  /* define mes2 */
  int dia2;  /* define dia2 */
  int anio2; /* define anio2 */
  printf("Introduzca una fecha de la forma mm-dd-aaaa: ");
  scanf("%d%*c%d%*c%d", &mes1, &dia1, &anio1);
  printf("mes = %d dia = %d anio = %d\n\n", mes1, dia1, anio1);
  printf("Introduzca una fecha de la forma mm/dd/aaaa: ");
  scanf("%d%*c%d%*c%d", &mes2, &dia2, &anio2);
  printf("mes = %d dia = %d anio = %d\n", mes2, dia2, anio2);
  return 0; /* indica terminación exitosa */
} /* fin de main */
