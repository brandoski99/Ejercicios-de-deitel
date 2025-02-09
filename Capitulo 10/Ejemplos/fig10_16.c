/* Figura 10.16: fig10_16.c
Representación de barajas mediante campos de bits en una estructura */
#include <stdio.h>/* definición de la estructura cartaBit con campos de bits */
struct cartaBit {
  unsigned cara : 4;  /* 4 bits; 0-15 */
  unsigned palo : 2;  /* 2 bits; 0-3 */
  unsigned color : 1; /* 1 bit; 0-1 */
}; /* fin de la estructura cartaBit */
typedef struct cartaBit Carta; /* nuevo nombre de tipo para la estructura
cartaBit */
void llenaMazo(Carta *const wMazo);
/* prototipo */
void repartir(const Carta *const wMazo); /* prototipo */
int main() {
  Carta mazo[52]; /* crea el arreglo de Cartas */
  llenaMazo(mazo);
  //  repartir(mazo);
  return 0; /* indica terminación exitosa */
} /* fin de main */
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
/* muestra las cartas en formato de dos columnas; el subíndice de las
cartas 0 a 25 es k1 (columna 1); el subíndice de las cartas 26 a 51
es k2 (columna 2) */
void repartir(const Carta *const wMazo) {
  int k1; /* subíndice 0-25 */
  int k2; /* subíndice 26-51 */
  /* ciclo a través de wMazo */
  for (k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++) {
    printf("Carta:%3d Palo:%2d Color:%2d ", wMazo[k1].cara, wMazo[k1].palo,
           wMazo[k1].color);
    printf("Carta:%3d Palo:%2d Color:%2d\n", wMazo[k2].cara, wMazo[k2].palo,
           wMazo[k2].color);
  } /* fin de for */
} /* fin de la función repartir */
