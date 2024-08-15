/* Figura 7.24: fig07_24.c
 Programa para barajar y repartir cartas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototipos */
void baraja(int wMazo[][13]);
void reparte(const int wMazo[][13], const char *wCara[], const char *wPalo[]);

int main() {
  /* inicializa el arreglo palo */
  const char *palo[4] = {"Corazones", "Diamantes", "Treboles", "Espadas"};

  /* inicializa el arreglo cara */
  const char *cara[13] = {"As",   "Dos",   "Tres", "Cuatro", "Cinco",
                          "Seis", "Siete", "Ocho", "Nueve",  "Diez",
                          "Joto", "Quina", "Rey"};

  /* inicializa el arreglo mazo */
  int mazo[4][13] = {0};

  srand(time(0)); /* semilla del generador de n�meros aleatorios */

  baraja(mazo);
  reparte(mazo, cara, palo);

  return 0; /* indica terminaci�n exitosa */

} /* fin de main */

/* baraja las cartas del mazo */
void baraja(int wMazo[][13]) {
  int fila;    /* n�mero de fila */
  int columna; /* n�mero de columna */
  int carta;   /* contador */

  /* elige aleatoriamente un espacio para cada una de las 52 cartas */
  for (carta = 1; carta <= 52; carta++) {

    /* elije una nueva ubicaci�n al azar hasta que encuentra un espacio vac�o */
    do {
      fila = rand() % 4;
      columna = rand() % 13;
    } while (wMazo[fila][columna] != 0); /* fin de do...while */

    /* coloca el n�mero de carta en el espacio vac�o del mazo */
    wMazo[fila][columna] = carta;
  } /* fin de for */

} /* fin de la funci�n baraja */

/* reparte las cartas del mazo */
void reparte(const int wMazo[][13], const char *wCara[], const char *wPalo[]) {
  int carta;   /* contador de cartas */
  int fila;    /* contador de filas */
  int columna; /* contador de columnas */

  /* reparte cada una de las 52 cartas */
  for (carta = 1; carta <= 52; carta++) {

    /* realiza el ciclo a trav�s de las filas de wMazo */
    for (fila = 0; fila <= 3; fila++) {

      /* realiza el ciclo a trav�s de las columnas de wMazo en la fila actual */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMazo[fila][columna] == carta) {
          printf("%6s de %-9s%c", wCara[columna], wPalo[fila],
                 carta % 2 == 0 ? '\n' : '\t');
        } /* fin de if */

      } /* fin de for */
    }
  } /* fin de for */

} /* fin de la funci�n reparte */
