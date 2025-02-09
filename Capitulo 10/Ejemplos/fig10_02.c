/* Figura 10.2: fig10_02.c
Uso de los operadores de estructurmiembro y de apuntador a estructura */
#include <stdio.h>
/* definición de la estructura carta */
struct carta {
  char *cara; /* define el apuntador cara */
  char *palo; /* define el apuntador palo */
}; /* fin de la estructura carta */
int main() {
  struct carta unaCarta;  /* define una estructura variable carta */
  struct carta *ptrCarta; /* define un apuntador a una estructura carta */
  /* coloca cadenas dentro de unaCarta */
  unaCarta.cara = "As";
  unaCarta.palo = "Espadas";
  ptrCarta = &unaCarta; /* asigna la dirección de unaCarta a ptrCarta */
  printf("%s%s%s\n%s%s%s\n%s%s%s\n", unaCarta.cara, " de ", unaCarta.palo,
         ptrCarta->cara, " de ", ptrCarta->palo, (*ptrCarta).cara, " de ",
         (*ptrCarta).palo);
  return 0; /* indica terminación exitosa */
} /* fin de main */
