#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
int main() {
  srand(time(NULL));
  char *articulo[] = {"el", "la", "algun", "un", "cualquiera"};
  char *sustantivo[] = {"nino", "nina", "perro", "pueblo", "carro"};
  char *verbo[] = {"condujo", "brinco", "corrio", "camino", "salto"};
  char *preposicion[] = {"hacia", "desde", "sobre", "bajo", "en"};
  char sentence[SIZE] = "";
  int rArticulo = 0 + rand() % 4;
  int rSustantivo = 0 + rand() % 4;
  int rVerbo = 0 + rand() % 4;
  int rPreposicion = 0 + rand() % 4;
  for (int i = 1; i <= 20; i++) {
    snprintf(sentence, SIZE, "%s %s %s %s %s %s.", articulo[rArticulo],
             sustantivo[rSustantivo], verbo[rVerbo], preposicion[rPreposicion],
             articulo[0 + rand() % 4], sustantivo[0 + rand() % 4]);
    sentence[0] = toupper(sentence[0]);
    printf("%s", sentence);
    printf("\n");

    rArticulo = 0 + rand() % 4;
    rSustantivo = 0 + rand() % 4;
    rVerbo = 0 + rand() % 4;
    rPreposicion = 0 + rand() % 4;
  }
  return 0;
}
