#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void printDate(char *date);

int main() {
  char date[SIZE];
  printf("Introduzca una fecha en el siguiente formato: dd/mm/yyyy\n");
  fgets(date, sizeof(date), stdin);
  printDate(date);
  return 0;
}

void printDate(char *date) {
  char *day = strtok(date, "/");
  char *month = strtok(NULL, "/");
  char *year = strtok(NULL, "/");

  const char *months[12] = {"Enero",      "Febrero", "Marzo",     "Abril",
                            "Mayo",       "Junio",   "Julio",     "Agosto",
                            "Septiembre", "Octubre", "Noviembre", "Diciembre"};

  month = (char *)months[atoi(month) - 1];

  printf("\n%s de %s del %s\n", day, month, year);
}
