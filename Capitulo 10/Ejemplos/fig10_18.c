/* Figura 10.18: fig10_18.c
Uso de un tipo de enumeración */
#include <stdio.h>
/* las constantes de enumeración representan los meses del año */
enum meses { ENE = 1, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC };
int main() {
  enum meses mes; /* puede contener cualquiera de los 12 meses */
  /* inicializa el arreglo de apuntadores */
  const char *nombreMes[] = {"",         "Enero",      "Febrero", "Marzo",
                             "Abril",    "Mayo",       "Junio",   "Julio",
                             "Agosto",   "Septiembre", "Octubre", "Noviembre",
                             "Diciembre"};
  /* ciclo a través de los meses */
  for (mes = ENE; mes <= DIC; mes++) {
    printf("%2d%11s\n", mes, nombreMes[mes]);
  }         /* fin de for */
  return 0; /* indica terminación exitosa */
} /* fin de main */
