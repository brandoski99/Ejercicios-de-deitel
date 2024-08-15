/* Ejercicio 7.16 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototipos */
void baraja(int wMazo[][13]);
void reparte(const int wMazo[][13], const char *wCara[], const char *wPalo[]);
void inicializarMazo(int wMazo[][13]);

int main() {
  /* inicializa el arreglo palo */
  const char *palo[4] = {"Corazones", "Diamantes", "Treboles", "Espadas"};

  /* inicializa el arreglo cara */
  const char *cara[13] = {"As",   "Dos",   "Tres", "Cuatro", "Cinco",
                          "Seis", "Siete", "Ocho", "Nueve",  "Diez",
                          "Joto", "Quina", "Rey"};

  /* inicializa el arreglo mazo */
  int mazo[4][13] = {0};

  srand(time(0)); /* semilla del generador de números aleatorios */
  inicializarMazo(mazo);
  baraja(mazo);
  reparte(mazo, cara, palo);

  return 0; /* indica terminación exitosa */

} /* fin de main */

/* baraja las cartas del mazo */
void baraja(int wMazo[][13]) {
  int rfila;    /* número de fila */
  int rcolumna; /* número de columna */
  int temp;     /* guarda temporalmente el valor del mazo para intercambiarlo */

  for (int fila = 0; fila <= 3; fila++) {
    for (int columna = 0; columna <= 12; columna++) {

      /* Se intercambian los valores aleatoriamente */
      rfila = rand() % 4;
      rcolumna = rand() % 13;
      temp = wMazo[fila][columna];
      wMazo[fila][columna] = wMazo[rfila][rcolumna];
      wMazo[rfila][rcolumna] = temp;
    }
  }
}
/* reparte las cartas del mazo */
void reparte(const int wMazo[][13], const char *wCara[], const char *wPalo[]) {
  int carta;   /* contador de cartas */
  int fila;    /* contador de filas */
  int columna; /* contador de columnas */
  /* reparte cada una de las 52 cartas */
  for (carta = 1; carta <= 52; carta++) {

    /* realiza el ciclo a través de las filas de wMazo */
    for (fila = 0; fila <= 3; fila++) {
      /* realiza el ciclo a través de las columnas de wMazo en la fila actual
       */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMazo[fila][columna] == carta) {
          printf("%6s de %-9s%c", wCara[columna], wPalo[fila],
                 carta % 2 == 0 ? '\n' : '\t');

          /* Si se encuentra la carta se detienen los 2 for anidados */
          fila = 4;
          columna = 13;
        } /* fin de if */
      } /* fin de for */
    }

  } /* fin de for */
}

void inicializarMazo(int wMazo[][13]) {
  int carta = 1;
  for (int fila = 0; fila <= 3; fila++) {
    for (int columna = 0; columna <= 12; columna++) {
      wMazo[fila][columna] = carta;
      carta++;
    }
  }
}
