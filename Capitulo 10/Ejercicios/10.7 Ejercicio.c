#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct cartaBit {
  unsigned cara : 4;  /* 4 bits; 0-15 */
  unsigned palo : 2;  /* 2 bits; 0-3 */
  unsigned color : 1; /* 1 bit; 0-1 */
};
typedef struct cartaBit Carta;

void llenaMazo(Carta *const wMazo);
void barajar(Carta *const wMazo);
void repartir(const Carta *const wMazo); /* prototipo */
int main() {
  Carta mazo[52];
  srand(time(NULL));

  llenaMazo(mazo);
  barajar(mazo);
  repartir(mazo);
  return 0;
}
/* inicializa Carta */
void llenaMazo(Carta *const wMazo) {
  int i; /* contador */
  /* ciclo a través de wMazo */
  for (i = 0; i <= 51; i++) {
    wMazo[i].cara = i % 13;
    wMazo[i].palo = i / 13;
    wMazo[i].color = i / 26;
  } /* fin de for */
} /* fin de la función llenaMazo */

void barajar(Carta *const wMazo) {
  int i;      /* contador */
  int j;      /* variable para almacenar el valor aleatorio entre 0 - 51 */
  Carta temp; /* define la estructura temporal para intercambiar cartas */

  /* ciclo a través de wMazo para intercambiar aleatoriamente Baraja */
  for (i = 0; i <= 51; i++) {
    j = rand() % 52;
    temp = wMazo[i];
    wMazo[i] = wMazo[j];
    wMazo[j] = temp;
  } /* fin de for */
} /* fin de la función barajar */

void repartir(const Carta *const wMazo) {
  int i; /* contador */
  /* ciclo a través de wMazo */
  for (i = 0; i <= 51; i++) {
    printf("Carta:%3d Palo:%2d Color:%2d%c", wMazo[i].cara, wMazo[i].palo,
           wMazo[i].color, (i + 1) % 2 ? '\t' : '\n');
  } /* fin de for */
} /* fin de la función repartir */
