/* ejercicio 7.13 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototipos */
void baraja(int wMazo[][13]);
void reparte(int wMazo[][13], const char *wCara[], const char *wPalo[],
             int wMano[][13]);
void imprimirMano(const char *wCara[], const char *wPalo[], int wMano[][13]);
void determinar(const int wMano[][13], int *manoValor);

int main() {
  /* inicializa el arreglo palo */
  const char *palo[4] = {"Corazones", "Diamantes", "Treboles", "Espadas"};

  /* inicializa el arreglo cara */
  const char *cara[13] = {"Dos",   "Tres", "Cuatro", "Cinco", "Seis",
                          "Siete", "Ocho", "Nueve",  "Diez",  "Joto",
                          "Quina", "Rey",  "As"};

  /* inicializa el arreglo mazo,mano1 y mano2 */
  int mazo[4][13] = {0};
  int mano1[4][13] = {0};
  int mano2[4][13] = {0};

  /* variables encargadas de almacenar el valor de cada mano */
  int manoValor1 = 0;
  int manoValor2 = 0;

  srand(time(0)); /* semilla del generador de números aleatorios */

  baraja(mazo);
  reparte(mazo, cara, palo, mano1);
  reparte(mazo, cara, palo, mano2);
  imprimirMano(cara, palo, mano1);
  imprimirMano(cara, palo, mano2);
  determinar(mano1, &manoValor1);
  determinar(mano2, &manoValor2);

  printf("\n Mano1 = %d \t Mano2 = %d\n", manoValor1, manoValor2);

  /* determinamos cual mano es mejor */
  if (manoValor1 > manoValor2) {
    printf("\nLa mano 1 es mejor que la mano 2\n");
  } else if (manoValor2 > manoValor1) {
    printf("\nLa mano 2 es mejor que la mano 1\n");
  } else {
    printf("\nEmpate\n");
  }

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
  static int carta;        /* contador de cartas */
  int fila;                /* contador de filas */
  int columna;             /* contador de columnas */
  static int contador = 5; /* Limite de cartas repartidas por mano */

  /* reparte cada una de las 52 cartas */
  for (carta = 1; carta <= contador; carta++) {

    /* realiza el ciclo a través de las filas de wMazo */
    for (fila = 0; fila <= 3; fila++) {

      /* realiza el ciclo a través de las columnas de wMazo en la fila actual */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMazo[fila][columna] == carta) {
          wMano[fila][columna] = 1;
          wMazo[fila][columna] = 0;
        } /* fin de if */

      } /* fin de for */
    }
  } /* fin de for */
  contador += 5; // Se suma 5 al contador cada vez que se llama la funcion
} /* fin de la función reparte */

void imprimirMano(const char *wCara[], const char *wPalo[], int wMano[][13]) {
  int carta;            /* contador de cartas */
  int fila;             /* contador de filas */
  int columna;          /* contador de columnas */
  static int nMano = 1; /* indica el numero de la mano */

  printf("Mano%d:\n", nMano);
  for (carta = 1; carta <= 5; carta++) {

    /* realiza el ciclo a través de las filas de wMano */
    for (fila = 0; fila <= 3; fila++) {

      /* realiza el ciclo a través de las columnas de wMano en la fila actual */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMano[fila][columna] == carta) {
          printf("%6s de %-9s\n", wCara[columna], wPalo[fila]);
        } /* fin de if */

      } /* fin de for */
    }
  } /* fin de for */
  printf("\n");
  nMano++;
} /* fin de la función reparte */

void determinar(const int wMano[][13], int *manoValor) {
  /* Prototipos */
  void esPar(const int wMano[][13], int *manoValorr);
  void dosPares(const int wMano[][13], int *manoValor);
  void triple(const int wMano[][13], int *manoValor);
  void cuatro(const int wMano[][13], int *manoValor);
  void todasIguales(const int wMano[][13], int *manoValor);
  void directa(const int wMano[][13], int *manoValor);

  /* LLamadas */
  triple(wMano, manoValor);
  if (*manoValor == 0) {
    dosPares(wMano, manoValor);
  }
  esPar(wMano, manoValor);
  cuatro(wMano, manoValor);
  todasIguales(wMano, manoValor);
  directa(wMano, manoValor);
}

void esPar(const int wMano[][13], int *manoValor) {
  int par = 0;
  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? par++ : 0;
    }
    // Si se encuentra un par la funcion retorna
    if (par == 2) {
      printf("\nhay un par en la  mano");
      *manoValor += 1 + j;
      return;
    }
    par = 0;
  }
}

void dosPares(const int wMano[][13], int *manoValor) {
  int par1 = 0;
  int par2 = 0;

  int vPar1 = 0; // Puntaje del primer par
  int vPar2 = 0; // Puntaje del segundo par
  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {

      if (par1 != 2) {
        wMano[i][j] ? par1++ : 0;
        if (par1 == 2 && vPar1 == 0) {
          vPar1 = j;
        }
      } else {
        wMano[i][j] ? par2++
                    : 0; // Si par1 = 2 entonces el proximo par se sumara a par2
        if (par2 == 2 && vPar2 == 0) {
          vPar2 = j;
        }
      }

    } // fin del for i
    if (par1 != 2) {
      par1 = 0;
    } else if (par2 != 2) {
      par2 = 0;
    }
  } // fin del for j

  if (par2 == 2) {
    *manoValor += 12 + vPar1 + vPar2;
    printf("\nHay 2 pares en la mano");
    return;
  }
}

void triple(const int wMano[][13], int *manoValor) {

  int triple = 0;

  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? triple++ : 0;
    }
    // Si se encuentra un triple la funcion retorna
    if (triple == 3) {
      printf("\nhay un triple en la  mano");
      *manoValor += 36 + j;
      return;
    }
    triple = 0;
  }
}

void cuatro(const int wMano[][13], int *manoValor) {

  int cuatro = 0;

  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? cuatro++ : 0;
    }
    // Si se encuentra cuatro del mismo valor la funcion retorna
    if (cuatro == 4) {
      printf("\nhay cuatro iguales en la  mano");
      *manoValor += 49 + j;
      return;
    }
    cuatro = 0;
  }
}

void todasIguales(const int wMano[][13], int *manoValor) {

  int palos = 0;
  int vPalos = 0;
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 12; j++) {
      wMano[i][j] ? palos++ : 0;
      if (palos == 5 && vPalos == 0) {
        vPalos = j;
      }
    }
    // Si todas las cartas son del mismo palo la funcion retorna
    if (palos == 5) {
      printf("\ntodas las cartas son del mismo palo");
      *manoValor += 62 + vPalos;
      return;
    }
    palos = 0;
  }
}

void directa(const int wMano[][13], int *manoValor) {
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
    *manoValor += 999;
  }
}
