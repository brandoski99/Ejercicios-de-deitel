/* ejercicio 7.15 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototipos */
void baraja(int wMazo[][13]);
void reparte(int wMazo[][13], const char *wCara[], const char *wPalo[],
             int wMano[][13]);
void imprimirMano(const char *wCara[], const char *wPalo[], int wMano[][13],
                  const char *nombre);
void determinar(const int wMano[][13], int *manoValor, int *combinacion,
                int *combinacionPar2);
void cambiarCartas(int wMano[][13], int wMazo[][13], int *manoValor,
                   int *combinacion, int *combinacionPar2);
void jugadorOpciones(int wMano[][13], int wMazo[][13], const char *wCara[],
                     const char *wPalo[]);
// Variable que guarda la combinacion del segundo par
static int contador = 0; /* Limite de cartas repartidas por mano */
static int carta;        /* contador de cartas */

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
  int jugador = 0;
  int repartidor = 0;

  /* vairables encargadas de almacenar el valor del palo*/
  int combinacionJugador = -1;
  int combinacionRepartidor = -1;

  int jugadorPar2 = -1;
  int repartidorPar2 = -1;

  srand(time(0)); /* semilla del generador de números aleatorios */

  baraja(mazo);
  reparte(mazo, cara, palo, mano1);
  reparte(mazo, cara, palo, mano2);
  imprimirMano(cara, palo, mano1, "Jugador");
  determinar(mano2, &repartidor, &combinacionRepartidor, &repartidorPar2);
  jugadorOpciones(mano1, mazo, cara, palo);
  cambiarCartas(mano2, mazo, &repartidor, &combinacionRepartidor,
                &repartidorPar2);
  imprimirMano(cara, palo, mano1, "Jugador");
  determinar(mano1, &jugador, &combinacionJugador, &jugadorPar2);
  imprimirMano(cara, palo, mano2, "Repartidor");
  determinar(mano2, &repartidor, &combinacionRepartidor, &repartidorPar2);
  printf("\n Jugador = %d \t Repartidor = %d\n", jugador, repartidor);

  if (jugador > repartidor) {
    printf("Felicidades! has ganado!\n");
  } else {
    printf("Perdiste! El repartidor ha ganado\n");
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
  int fila;      /* contador de filas */
  int columna;   /* contador de columnas */
  contador += 5; // Se suma 5 al contador cada vez que se llama la funcion
  /* reparte cada una de las 52 cartas */
  for (carta = 1; carta <= contador; carta++) {

    /* realiza el ciclo a través de las filas de wMazo */
    for (fila = 0; fila <= 3; fila++) {

      /* realiza el ciclo a través de las columnas de wMazo en la fila actual */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMazo[fila][columna] == carta) {
          wMano[fila][columna] = carta;
          wMazo[fila][columna] = 0;
        } /* fin de if */

      } /* fin de for */
    }
  } /* fin de for */

} /* fin de la función reparte */
void jugadorOpciones(int wMano[][13], int wMazo[][13], const char *wCara[],
                     const char *wPalo[]) {
  int inputJugador = 0;    // Guarda las opciones del jugador
  int cartas[4][13] = {0}; // Guarda las cartas con sus posiciones

  void jugadorCambio(int wMano[][13], int wMazo[][13],
                     int cartasACambiar[][13]);
  void imprimirManoJugador(const char *wCara[], const char *wPalo[],
                           int wMano[][13]);

  printf("Desea cambiar las cartas?\n1-Si\n2-No\n");
  scanf("%d", &inputJugador);
  switch (inputJugador) {
  case 1:
    // Se asignan las posiciones a las cartas
    for (int carta = 1; carta <= 5; carta++) {
      for (int fila = 0; fila <= 3; fila++) {
        for (int columna = 0; columna <= 12; columna++) {
          if (wMano[fila][columna] == carta) {
            cartas[fila][columna] = carta;
          }
        }
      }
    }
    // Se imprimen las cartas con sus posiciones
    imprimirManoJugador(wCara, wPalo, wMano);
    jugadorCambio(wMano, wMazo, cartas);
    break;
  case 2:
    break;
  }
}

void imprimirManoJugador(const char *wCara[], const char *wPalo[],
                         int wMano[][13]) {
  int cartass = 1; /* contador de cartas */
  int fila;        /* contador de filas */
  int columna;     /* contador de columnas */

  printf("Tu mano:\n");
  for (; cartass <= 5; cartass++) {

    /* realiza el ciclo a través de las filas de wMano */
    for (fila = 0; fila <= 3; fila++) {

      /* realiza el ciclo a través de las columnas de wMano en la fila actual */
      for (columna = 0; columna <= 12; columna++) {

        /* si el espacio contiene la carta actual, despliega la carta */
        if (wMano[fila][columna] == cartass) {
          printf("%d-%2s de %-9s\n", cartass, wCara[columna], wPalo[fila]);
        } /* fin de if */

      } /* fin de for */
    }
  } /* fin de for */
  printf("\n6-Salir\n");
  printf("Seleccione alguna de las opcones: ");
  printf("\n");
}
void jugadorCambio(int wMano[][13], int wMazo[][13], int cartasACambiar[][13]) {
  int input = 0;
  int cambios = 1;
  void cambioSeleccion(int wMano[][13], int wMazo[][13],
                       int cartasACambiar[][13], int opcion);
  while (input != 6 && cambios <= 5) {
    scanf("%d", &input);
    switch (input) {
    case 1:
      cambioSeleccion(wMano, wMazo, cartasACambiar, input);
      cambios++;
      break;
    case 2:
      cambioSeleccion(wMano, wMazo, cartasACambiar, input);
      cambios++;
      break;
    case 3:
      cambioSeleccion(wMano, wMazo, cartasACambiar, input);
      cambios++;
      break;
    case 4:
      cambioSeleccion(wMano, wMazo, cartasACambiar, input);
      cambios++;
      break;

    case 5:
      cambioSeleccion(wMano, wMazo, cartasACambiar, input);
      cambios++;
      break;

    case 6:
      break;
    }
  }
}

void cambioSeleccion(int wMano[][13], int wMazo[][13], int cartasACambiar[][13],
                     int opcion) {

  contador++;
  int exitt = 0;
  for (int fila = 0; fila <= 3; fila++) {
    for (int columna = 0; columna <= 12; columna++) {
      if (wMano[fila][columna] == opcion) {
        wMano[fila][columna] = 0;
      }
    }

    /* se reemplazan las cartas descartadas */
    for (int carta = 1; carta <= contador && exitt == 0; carta++) {

      /* realiza el ciclo a través de las filas de wMazo */
      for (int fila = 0; fila <= 3 && exitt == 0; fila++) {

        /* realiza el ciclo a través de las columnas de wMazo en la fila actual
         */
        for (int columna = 0; columna <= 12 && exitt == 0; columna++) {

          /* si el espacio contiene la carta actual, se asigna la carta al mazo
           */
          if (wMazo[fila][columna] == carta) {
            wMano[fila][columna] = carta;
            wMazo[fila][columna] = 0;
            exitt++;
          } /* fin de if */

        } /* fin de for */
      }
    } /* fin de for */
  }
}
void cambiarCartas(int wMano[][13], int wMazo[][13], int *manoValor,
                   int *combinacion, int *combinacionPar2) {
  int cartas = 5; // cantidad de cartas a cambiar

  if (*combinacion > -1) {
    // Si es un par;
    if (*manoValor > 0 && *manoValor <= 13) {
      cartas = 3;
    }
    // Si son dos pares
    else if (*combinacionPar2 != -1) {
      cartas = 1;
    }

    // Si es triple
    else if (*manoValor > 36 && *manoValor <= 49) {
      cartas = 2;
    }
    // Si son cuatro iguales
    else if (*manoValor > 49 && *manoValor <= 62) {
      cartas = 1;
    }
    // Si es directa o son 5 del mismo palo no se cambia ninguna carta
    else {
      cartas = 0;
    }
  }
  if (cartas != 0) {
    /*se descartan las cartas que no formen una combinacion*/
    for (int carta = 1; carta <= cartas; carta++) {
      for (int fila = 0; fila <= 3; fila++) {
        for (int columna = 0; columna <= 12; columna++) {
          if (*combinacionPar2 != -1) {
            if (columna != *combinacion && columna != *combinacionPar2) {
              wMano[fila][columna] = 0;
            }
          } else if (columna != *combinacion) {
            wMano[fila][columna] = 0;
          }
        }
      }
    }

    /* se reemplazan las cartas descartadas */
    contador += cartas;
    for (carta = 1; carta <= contador; carta++) {

      /* realiza el ciclo a través de las filas de wMazo */
      for (int fila = 0; fila <= 3; fila++) {

        /* realiza el ciclo a través de las columnas de wMazo en la fila actual
         */
        for (int columna = 0; columna <= 12; columna++) {

          /* si el espacio contiene la carta actual, se asigna la carta al mazo
           */
          if (wMazo[fila][columna] == carta) {
            wMano[fila][columna] = carta;
            wMazo[fila][columna] = 0;
          } /* fin de if */

        } /* fin de for */
      }
    } /* fin de for */
  }
}
void imprimirMano(const char *wCara[], const char *wPalo[], int wMano[][13],
                  const char *nombre) {
  int carta;   /* contador de cartas */
  int fila;    /* contador de filas */
  int columna; /* contador de columnas */

  printf("%s:\n", nombre);
  for (carta = 1; carta <= contador; carta++) {

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
} /* fin de la función reparte */

void determinar(const int wMano[][13], int *manoValor, int *combinacion,
                int *combinacionPar2) {
  /* Prototipos */
  void esPar(const int wMano[][13], int *manoValor, int *combinacion);
  void dosPares(const int wMano[][13], int *manoValor, int *combinacion,
                int *combinacionPar2);
  void triple(const int wMano[][13], int *manoValor, int *combinacion);
  void cuatro(const int wMano[][13], int *manoValor, int *combinacion);
  void todasIguales(const int wMano[][13], int *manoValor);
  void directa(const int wMano[][13], int *manoValor);

  /* LLamadas */
  cuatro(wMano, manoValor, combinacion);
  if (*manoValor == 0) {
    triple(wMano, manoValor, combinacion);
  }
  if (*manoValor == 0) {
    dosPares(wMano, manoValor, combinacion, combinacionPar2);
  }
  if (*combinacionPar2 == -1) {
    esPar(wMano, manoValor, combinacion);
  }
  todasIguales(wMano, manoValor);
  directa(wMano, manoValor);
}

void esPar(const int wMano[][13], int *manoValor, int *combinacion) {

  int par = 0;
  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? par++ : 0;
    }
    // Si se encuentra un par la funcion retorna
    if (par == 2) {
      // printf("\nhay un par en la  mano");
      *combinacion = j;
      if (*manoValor > 36 && *manoValor <= 49) {
        *manoValor += 1 + j;
      } else {
        *manoValor = 1 + j;
      }
      return;
    }
    par = 0;
  }
}

void dosPares(const int wMano[][13], int *manoValor, int *combinacion,
              int *combinacionPar2) {
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
          *combinacion = j;
        }
      } else {
        wMano[i][j] ? par2++
                    : 0; // Si par1 = 2 entonces el proximo par se sumara a par2
        if (par2 == 2 && vPar2 == 0) {
          vPar2 = j;
          *combinacionPar2 = j;
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
    *manoValor = 12 + vPar1 + vPar2;
    // printf("\nHay 2 pares en la mano");
    return;
  }
}

void triple(const int wMano[][13], int *manoValor, int *combinacion) {
  int triple = 0;
  // anterior hayan sido 2 pares
  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? triple++ : 0;
    }
    // Si se encuentra un triple la funcion retorna
    if (triple == 3) {
      // printf("\nhay un triple en la  mano");
      *combinacion = j;
      *manoValor = 36 + j;
      return;
    }
    triple = 0;
  }
}

void cuatro(const int wMano[][13], int *manoValor, int *combinacion) {
  int cuatro = 0;

  for (int j = 0; j <= 12; j++) {
    for (int i = 0; i <= 3; i++) {
      wMano[i][j] ? cuatro++ : 0;
    }
    // Si se encuentra cuatro del mismo valor la funcion retorna
    if (cuatro == 4) {
      // printf("\nhay cuatro iguales en la  mano");
      *combinacion = j;
      *manoValor = 49 + j;
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
      // printf("\ntodas las cartas son del mismo palo");
      *manoValor = 62 + vPalos;
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
    // printf("\nHay una directa\n");
    *manoValor += 999;
  }
}
