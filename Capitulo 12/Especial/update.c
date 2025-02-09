#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY 100
typedef struct {
  int symbol;
  char type;    /* 'C', 'L', 'V' */
  int location; /* 00 a 99 */
} entryTable_t;
/*  'C' = Constante
 *  'L' = Linea
 *  'V' = Variable
 */

// Buscar ubicacion de un simbolo en la tabla de simbolos
int findVariable(entryTable_t SymbolsTable[], int variable);
int findLine(entryTable_t SymbolsTable[], int line);
int findConstant(entryTable_t SymbolsTable[], int constant);
// Buscar las banderas en el arreglo banderas
void findFlags(int flags[], int LMS[], entryTable_t SymbolsTable[]);

int main() {
  entryTable_t SymbolsTable[100]; // tabla de simbolos
  int flags[MEMORY];              // Banderas del compilador
  int LMS[MEMORY] = {0};          // Instrucciones en LMS
  int location = 0;     // Ubicacion en memoria del Simpletron 00,01...
  int symbolsCount = 0; // Contador de tabla de simbolos
  int variablesLocation =
      MEMORY - 1;     // Ubicacion de las constantes y variables 99,98...
  char simple[20];    // Nombre archivo simple que se compilara
  int lineSimple = 1; // Contador de la linea actual del archivo simple

  // Inicializa los elementos del arreglo flags
  for (int i = 0; i <= MEMORY - 1; i++) {
    flags[i] = -1; // Se inicializan todos los elementos en -1
  }

  printf("Introduzca el nombre del archivo simple a compilar: ");
  scanf("%s", simple);
  putchar('\n');
  FILE *simpleFile = fopen(simple, "r"); // Archivo simple que se compilara

  if (simpleFile != NULL) {
    // Leer cada linea del archivo simple
    char read[256];
    fgets(read, sizeof(read), simpleFile);
    while (!(feof(simpleFile))) {

      // Separa en tokens cada palabra de la linea actual
      char *token = strtok(read, " \n");

      // Se agrega a tabla de simbolos el primer token que corresponde al numero
      // de Linea si no esta repetida

      if (isdigit(token) && findLine(SymbolsTable, atoi(token)) == -1) {
        SymbolsTable[symbolsCount].symbol = atoi(token);
        SymbolsTable[symbolsCount].type = 'L';
        SymbolsTable[symbolsCount].location = location;
        symbolsCount++;
      }

      // Si la linea esta repetida, despliega un mensaje de error
      else {
        printf("\n%d: *** LA LINEA %s ESTA REPETIDA, FINALIZANDO COMPILACION "
               "***\n",
               lineSimple, token);
        simpleFile = NULL;
        break;
      }

      // Siguiente instruccion luego de leer el numero de linea
      while (token != NULL) {
        // Si el token es un comentario se ignora la instruccion
        if (strcmp(token, "rem") == 0)
          location = location;

        // Si el token es input
        else if (strcmp(token, "input") == 0) {
          // Se obtiene la letra de la variable
          token = strtok(NULL, " ");
          // Si la letra no esta repetida
          if (isalpha(token[0]) && findVariable(SymbolsTable, token[0]) == -1) {

            // Se agrega  a la tabla de simbolos
            SymbolsTable[symbolsCount].symbol = token[0];
            SymbolsTable[symbolsCount].type = 'V';
            SymbolsTable[symbolsCount].location = variablesLocation;

            LMS[location] = 1000 + variablesLocation;

            location++;
            variablesLocation--;
            symbolsCount++;
          }
          // Si la letra ya esta en la tabla de simbolos
          else if (isalpha(token[0])) {
            LMS[location] = 1000 + findVariable(SymbolsTable, token[0]);
            location++;
          }
          // Si ninguno de las condiciones se cumple despliega ERROR
          else {
            printf("%d:*** ERROR NOMBRE DE VARIABLE INVALIDA %s ***",
                   lineSimple, token);
            simpleFile = NULL;
            break;
          }
        } // Fin del else if input

        // Si el token es print
        else if (strcmp(token, "print") == 0) {
          token = strtok(NULL, " ");
          // Se busca la ubicacion de la variable
          int locationSymbol = findVariable(SymbolsTable, token[0]);

          if (locationSymbol != -1) {
            LMS[location] = 1100 + locationSymbol;
            location++;
          }
          // Despliega error si no se reconoce la variable a imprimir
          else {
            printf("%d:*** ERROR VARIABLE NO ENCONTRADA PARA IMPRIMIR %s ***",
                   lineSimple, token);
            simpleFile = NULL;
            break;
          }
        } // Fin del else if print

        else if (strcmp(token, "goto") == 0) {
          token = strtok(NULL, " ");

          int locationLine = findLine(SymbolsTable, atoi(token));

          // Si se encuentra la linea en la tabla de simbolos
          if (locationLine != -1) {
            LMS[location] = 4000 + locationLine;
            location++;
          }

          // Si no, se agrega al arreglo banderas
          else {
            LMS[location] = 4000;
            flags[location] = atoi(token);
            location++;
          }
        } // Fin del else if goto
        token = strtok(NULL, " \n");
      } // Fin del while token != NULL
    } // Fin del while !(feof(simpleFile))

    // Lee la siguiente linea
    fgets(read, sizeof(read), simpleFile);
    lineSimple++;
  } // Fin del if simpleFile != NULL
  fclose(simpleFile);

  return 0;
}

// Funciones para buscar simbolos en la tabla de simbolos
int findVariable(entryTable_t SymbolsTable[], int variable) {

  for (int i = 0; i <= 99; i++) {

    /* Si se encuentra la variable, devuelve la ubicacion en memoria de este
     */
    if (SymbolsTable[i].symbol == variable && SymbolsTable[i].type == 'V') {
      return SymbolsTable[i].location;
    }
  }

  // Retorna -1 si no se encontro el simbolo
  return -1;
}

int findLine(entryTable_t SymbolsTable[], int line) {
  for (int i = 0; i <= 99; i++) {

    /* Si se encuentra la linea, devuelve la ubicacion en memoria de este */
    if (SymbolsTable[i].symbol == line && SymbolsTable[i].type == 'L') {
      return SymbolsTable[i].location;
    }
  }

  // Retorna -1 si no se encontro el simbolo
  return -1;
}

int findConstant(entryTable_t SymbolsTable[], int constant) {
  for (int i = 0; i <= 99; i++) {

    /* Si se encuentra la linea, devuelve la ubicacion en memoria de este */
    if (SymbolsTable[i].symbol == constant && SymbolsTable[i].type == 'C') {
      return SymbolsTable[i].location;
    }
  }

  // Retorna -1 si no se encontro el simbolo
  return -1;
}

void findFlags(int flags[], int LMS[], entryTable_t SymbolsTable[]) {
  int line = -1;
  for (int i = 0; i <= 99; i++) {

    // Se busca un elemento flag que no sea -1
    if (flags[i] != -1) {
      line = findLine(SymbolsTable, flags[i]);
      if (line != -1) {
        // Se agrega la ubicacion de linea a la instruccion LMS
        LMS[i] = LMS[i] + line;
      }
      // Imprime un mensaje si la linea no se consigue en la tabla de simbolos
      else {
        printf("No se encontro la linea %d en la tabla de simbolos", flags[i]);
      }
    }
  }
}
