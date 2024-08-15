#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototipos */
void baraja(int wMazo[][13]);
void reparte(int wMazo[][13], const char *wCara[], const char *wPalo[],
             int wMano[][13]);
void imprimirMano(const char *wCara[], const char *wPalo[], int wMano[][13]);
void determinar(const int wMano[][13]);

static int manoValor = 0;

int main() {
  /* inicializa el arreglo palo */
  const char *palo[4] = {"Corazones", "Diamantes", "Treboles", "Espadas"};

  /* inicializa el arreglo cara */
  const char *cara[13] = {"As",   "Dos",   "Tres", "Cuatro", "Cinco",
                          "Seis", "Siete", "Ocho", "Nueve",  "Diez",
                          "Joto", "Quina", "Rey"};

  /* inicializa el arreglo mazo */
  int mazo[4][13] = {0};
  int mano[4][13] = {0};
  srand(time(0)); /* semilla del generador de números aleatorios */

  baraja(mazo);
  reparte(mazo, cara, palo, mano);
  imprimirMano(cara, palo, mano);
  determinar(mano);
  return 0; /* indica terminación exitosa */

} /* fin de main */

/* baraja las cartas del mazo */
void baraja(int wMazo[][13]) {
  int fila;    /* número de fila */
  int columna; /* número de columna */
  int carta;   /* contador */

  /* elige aleatoriamente un espacio para cada una de las 52 cartas */
  for (carta = 1; carta <= 52; carta++) {

    /* elije una nueva ubicación al azar hasta que encuentra un espacio vacío */
    do {
      fila = rand() % 4;
      columna = rand() % 13;
    } while (wMazo[fila][columna] != 0); /* fin de do...while */

    /* coloca el número de carta en el espacio vacío del mazo */
    wMazo[fila][columna] = carta;
  } /* fin de for */

} /* fin de la función baraja */

/* reparte las cartas del mazo */
void reparte(int wMazo[][13], const char *wCara[], const char *wPalo[],
             int wMano[][13]) {
  int carta;   /* contador de cartas */
  int fila;    /* contador de filas */
  int columna; /* contador de columnas */

  /* reparte cada una de las 52 cartas */
  for (carta = 1; carta <= 5; carta++) {

    /* realiza el ciclo a través de las filas de wMazo */
    for (fila = 0; fila <= 3; fila++) {

      /* realiza el ciclo a través de las columnas de wMazo en la fila actual */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMazo[fila][columna] == carta) {
          /* printf("%6s de %-9s%c", wCara[columna], wPalo[fila],
                  carta % 2 == 0 ? '\n' : '\t'); */
          wMano[fila][columna] = carta;
          wMazo[fila][columna] = 0;
        } /* fin de if */

      } /* fin de for */
    }
  } /* fin de for */

} /* fin de la función reparte */

void imprimirMano(const char *wCara[], const char *wPalo[], int wMano[][13]) {
  int carta;   /* contador de cartas */
  int fila;    /* contador de filas */
  int columna; /* contador de columnas */

  for (carta = 1; carta <= 5; carta++) {

    /* realiza el ciclo a través de las filas de wMazo */
    for (fila = 0; fila <= 3; fila++) {

      /* realiza el ciclo a través de las columnas de wMazo en la fila actual */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMano[fila][columna] == carta) {
          printf("%6s de %-9s\n", wCara[columna], wPalo[fila]);
        } /* fin de if */

      } /* fin de for */
    }
  } /* fin de for */

} /* fin de la función reparte */

void determinar(const int wMano[][13]) {
  /* Prototipos */
  void esPar(const int wMano[][13]);
  void dosPares(const int wMano[][13]);
  void triple(const int wMano[][13]);
  void cuatro(const int wMano[][13]);
  void todasIguales(const int wMano[][13]);
  void directa(const int wMano[][13]);

  /* LLamadas */
  esPar(wMano);
  dosPares(wMano);
  triple(wMano);
  cuatro(wMano);
  todasIguales(wMano);
  directa(wMano);
}

void esPar(const int wMano[][13]) {
  int par = 0;
  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? par++ : 0;
    }
    // Si se encuentra un par la funcion retorna
    if (par == 2) {
      printf("\nhay un par en la  mano");
      return;
    }
    par = 0;
  }
}

void dosPares(const int wMano[][13]) {
  int par1 = 0;
  int par2 = 0;
  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {

      if (par1 != 2) {
        wMano[i][j] ? par1++ : 0;
      }

      else {
        wMano[i][j] ? par2++
                    : 0; // Si par1 = 2 entonces el proximo par se sumara a par2
      }

    } // fin del for i
    if (par1 != 2) {
      par1 = 0;
    } else if (par2 != 2) {
      par2 = 0;
    }
  } // fin del for j

  if (par2 == 2) {
    printf("\nHay 2 pares en la mano");
  }
}

void triple(const int wMano[][13]) {

  int triple = 0;

  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? triple++ : 0;
    }
    // Si se encuentra un triple la funcion retorna
    if (triple == 3) {
      printf("\nhay un triple en la  mano");
      return;
    }
    triple = 0;
  }
}

void cuatro(const int wMano[][13]) {

  int cuatro = 0;

  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? cuatro++ : 0;
    }
    // Si se encuentra cuatro del mismo valor la funcion retorna
    if (cuatro == 4) {
      printf("\nhay cuatro iguales en la  mano");
      return;
    }
    cuatro = 0;
  }
}

void todasIguales(const int wMano[][13]) {

  int palos = 0;

  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 12; j++) {
      wMano[i][j] ? palos++ : 0;
    }
    // Si todas las cartas son del mismo palo la funcion retorna
    if (palos == 5) {
      printf("\ntodas las cartas son del mismo palo");
      return;
    }
    palos = 0;
  }
}

void directa(const int wMano[][13]) {
  int palos = 0;
  int caras = 0;
  int palosIguales;
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 12; j++) {
      wMano[i][j] ? palos++ : 0;
      if (palos == 5) {
        palosIguales = i;
      }
    }
    // Si palos != 5 se iguala a 0 y se pasa al siguiente tipo de palo
    if (palos != 5) {
      palos = 0;
    }
  }

  if (palos == 5) {
    for (int j = 0; j <= 12; j++) {
      // Si las caras son consecutivas se incrementa la variable caras, pero si
      // no lo son se termina el ciclo igualando j a 13
      if (wMano[palosIguales][j] != 0) {
        caras++;
      } else {
        j = 13;
      }
    } // fin del for j
  } // fin del if

  if (caras == 5) {
    printf("\nHay una directa\n");
  }
}
