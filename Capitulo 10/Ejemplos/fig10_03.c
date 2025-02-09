/* Figura 10.3: fig10_03.c
Programa para barajar y repartir con el uso de estructuras */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* definición de la estructura carta */
struct carta {
  const char *cara; /* define el apuntador cara */
  const char *palo; /* define el apuntador palo */
}; /* fin de la estructura carta */

typedef struct carta Carta;
void llenaMazo(Carta *const wMazo, const char *wCara[], const char *wPalo[]);
void barajar(Carta *const wMazo);
void repartir(const Carta *const wMazo);

int main() {
  Carta mazo[52]; /* define el arreglo Carta */
  /* inicializa el arreglo de apuntadores */
  const char *cara[] = {"As",   "Dos",   "Tres", "Cuatro", "Cinco",
                        "Seis", "Siete", "Ocho", "Nueve",  "Diez",
                        "Joto", "Quina", "Rey"};
  /* inicializa el arreglo de apuntadores */
  const char *palo[] = {"Corazones", "Diamantes", "Treboles", "Espadas"};
  srand(time(NULL));           /* randomizar */
  llenaMazo(mazo, cara, palo); /* carga el mazo con las barajas */
  barajar(mazo);               /* coloca la Baraja en orden aleatorio */
  repartir(mazo);              /* reparte las 52 barajas */
  return 0;                    /* indica terminación exitosa */
} /* fin de main */
/* coloca cadenas dentro de las estructuras Baraja */
void llenaMazo(Carta *const wMazo, const char *wCara[], const char *wPalo[]) {
  int i; /* contador */
  /* ciclo a través de wMazo */
  for (i = 0; i <= 51; i++) {
    wMazo[i].cara = wCara[i % 13];
    wMazo[i].palo = wPalo[i / 13];
  } /* fin de for */
} /* fin de la función llenaMazo */
/* baraja el mazo */
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
/* reparte la baraja */
void repartir(const Carta *const wMazo) {
  int i; /* contador */
  /* ciclo a través de wMazo */
  for (i = 0; i <= 51; i++) {
    printf("%5s de %-8s%c", wMazo[i].cara, wMazo[i].palo,
           (i + 1) % 2 ? '\t' : '\n');
  } /* fin de for */
} /* fin de la función repartir */
