/* Ejercicio 7.17
 * Codigo extraido de
 * https://foro.elhacker.net/programacion_cc/simulacion_la_tortuga_y_la_liebrec-t322498.0.html*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 71

int printRace(int[][SIZE], int, int, int);

int main() {
  srand(time(NULL));
  int row, column, raceTrack[3][SIZE];
  int tortoise = 1, hare = 1, finish;

  printf("BANG!!%63s%ds\nAND THEY 'RE OFF!!\n\n", "Time: ", 0);
  /*Guarda el resultado de la carrera*/
  finish = printRace(raceTrack, tortoise, hare, SIZE);

  if (finish == 1)
    printf("\nTORTOISE WINS\n");
  else if (finish == 2)
    printf("\nHare wins\n");
  else
    printf("\nIt's a tie\n");

  return 0;
}

int printRace(int rt[][SIZE], int t, int h, int size) {

  // Funcion que se encarga de los tics del reloj
  void wait(int);

  /*movimientos de la tortuga y la liebre*/
  int tortoiseArray[10] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
  int hareArray[10] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};
  int timer = 1, row, column;
  // Mientras que ninguno de los 2 competidores llegue a la meta se ejecuta el
  // ciclo
  while (t < size - 1 && h < size - 1) {
    for (row = 1; row < 3; row++) {
      // Se imprimen los espacios de la pista
      for (column = 1; column < size; column++) {
        if (t != h || t == 1) {
          if (row == 1 && column == t)
            printf("%c", 'T');
          else if (row == 2 && column == h)
            printf("%c", 'H');
          else
            printf("_");
        } else {
          if (row == 1 && column == t)
            printf("%c", 'T');
          // La tortuga muerde a la liebre si estan en la misma posicion
          else if (row == 2 && column == h)
            printf("%s", "OUCH!!!");
          else
            printf("_");
        }
      }
      printf("\n");
    }
    // Se obtienen numeros aleatorios para determinar sus movimientos de acuerod
    // a la tabla
    t += tortoiseArray[rand() % 10];
    h += hareArray[rand() % 10];
    // Si al moverse a la izquierda se salen de la pista, se restablece su
    // poicion a 1
    if (t < 1)
      t = 1;
    if (h < 1)
      h = 1;
    if (t > size - 1)
      t = size - 1;
    if (h > size - 1)
      h = size - 1;
    wait(1);
    // Cada 1 segundo se actualiza el  valor de timer
    printf("%69s%ds", "Time: ", timer++);
    // Se limpia la pantalla cada 1 segundo
    system("clear");
    printf("\n\n\n");
  }

  for (row = 1; row < 3; row++) {
    for (column = 1; column < size; column++) {
      if (row == 1 && column == t)
        printf("%c", 'T');
      else if (row == 2 && column == h)
        printf("%c", 'H');
      else
        printf("_");
    }
    printf("\n");
  }
  // Si ambos llegan a la meta al mismo tiempo es un empate
  if (t == size - 1 && h == size - 1)
    return 0;
  // determina que la tortuga gano
  else if (t == size - 1)
    return 1;
  // Determina que la liebre gano
  else
    return 2;
}

/*Se encarga actualizar la variable timer cada 1 segundo*/
void wait(int seconds) {
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait)
    ;
}
