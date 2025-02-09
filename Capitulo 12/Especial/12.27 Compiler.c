#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calcular resultados postfijo
struct heapNode {
  char data;
  struct heapNode *ptrNextNode;
};
typedef struct heapNode *ptrHeapNode;

void convertToPostFixed(char inFixed[], char postFixed[]);
int calculaExpresionsPostFixed(char *expr);
int calculate(int op1, int op2, char operator);
int isOperator(char c);
int precedence(char operator1, char operator2);
void push(ptrHeapNode *ptrTop, char value);
char pop(ptrHeapNode *ptrTop);
char heapTop(ptrHeapNode ptrTop);
int isEmpty(ptrHeapNode ptrTop);
void printHeap(ptrHeapNode ptrTop);

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

// Resuelve las banderas
void findFlags(int flags[], int LMS[], entryTable_t SymbolsTable[]);
int main() {
  entryTable_t SymbolsTable[100]; // tabla de simbolos
  int flags[100];                 // Banderas del compilador
  int LMS[100] = {0};             // Instrucciones en LMS
  int location = 0;           // Ubicacion en memoria del Simpletron 00,01...
  int symbolsCount = 0;       // Contador de tabla de simbolos
  int variablesLocation = 99; // Ubicacion de las constantes y variables99,98...
  char simple[20];            // Nombre archivo simple que se compilara

  // Inicializa los elementos del arreglo flags
  for (int i = 0; i <= 99; i++) {
    flags[i] = -1; // Se inicializan todos los elementos en -1
  }

  printf("Introduzca el nombre del archivo simple a compilar: ");
  scanf("%s", simple);
  putchar('\n');

  FILE *simpleFile = fopen(simple, "r"); // Archivo simple que se compilara
  if (simpleFile != NULL) {

    // Leer cada linea del archivo simple
    char read[50];
    fgets(read, sizeof(read), simpleFile);
    while (!(feof(simpleFile))) {

      // Separa en tokens cada palabra de la linea actual
      char *token = strtok(read, " \n");

      // Se agrega a tabla de simbolos que corresponde al numero de Linea
      SymbolsTable[symbolsCount].symbol = atoi(token);
      SymbolsTable[symbolsCount].type = 'L';
      SymbolsTable[symbolsCount].location = location;
      symbolsCount++;

      while (token != NULL) {

        // Si el token es un comentario se ignora la instruccion
        if (strcmp(token, "rem") == 0) {
          location = location;
        }
        // Si el token es input
        else if (strcmp(token, "input") == 0) {

          // Se obtiene la letra de la variable
          token = strtok(NULL, " ");

          // Se agrega  a la tabla de simbolos
          SymbolsTable[symbolsCount].symbol = token[0];
          SymbolsTable[symbolsCount].type = 'V';
          SymbolsTable[symbolsCount].location = variablesLocation;

          LMS[location] = 1000 + variablesLocation;

          location++;
          variablesLocation--;
          symbolsCount++;
        }

        // Si el token es print
        else if (strcmp(token, "print") == 0) {
          token = strtok(NULL, " ");
          // Se busca la ubicacion de la variable
          int locationSymbol = findVariable(SymbolsTable, token[0]);

          if (locationSymbol != -1) {
            LMS[location] = 1100 + locationSymbol;
            location++;
          }
        }

        // Si el token es goto
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
        }

        // Si el token es if
        else if (strcmp(token, "if") == 0) {
          token = strtok(NULL, " ");

          // Busca la primera variable
          int locationVar1 = findVariable(SymbolsTable, token[0]);

          if (locationVar1 != -1) {
            token = strtok(NULL, " ");
            // Si el simbolo es menor que
            if (strcmp(token, "<") == 0) {
              // Busca la segunda variable
              token = strtok(NULL, " ");
              int locationVar2 = findVariable(SymbolsTable, token[0]);
              if (locationVar2 != -1) {
                // Carga la primera variable al acumulador
                LMS[location] = 2000 + locationVar1;
                location++;
                // Resta la segunda variable del acumulador
                LMS[location] = 3100 + locationVar2;
                location++;
                token = strtok(NULL, " ");
                // Si el siguiente token es goto
                if (strcmp(token, "goto") == 0) {
                  token = strtok(NULL, " ");

                  // Se busca la linea
                  int locationLine = findLine(SymbolsTable, atoi(token));
                  if (locationLine != -1) {
                    LMS[location] = 4100 + locationLine;
                    location++;
                  }
                  // Si no, se agrega al arreglo banderas
                  else {
                    LMS[location] = 4100;
                    flags[location] = atoi(token);
                    location++;
                  }
                }
              }
            }

            // Si el simbolo es mayor que
            else if (strcmp(token, ">") == 0) {
              // Busca la segunda variable
              token = strtok(NULL, " ");
              int locationVar2 = findVariable(SymbolsTable, token[0]);
              if (locationVar2 != -1) {
                // Carga la segunda variable al acumulador
                LMS[location] = 2000 + locationVar2;
                location++;
                // Resta la primera variable al acumulador
                LMS[location] = 3100 + locationVar1;
                location++;
                token = strtok(NULL, " ");
                // Si el siguiente token es goto
                if (strcmp(token, "goto") == 0) {
                  token = strtok(NULL, " ");

                  // Se busca la linea
                  int locationLine = findLine(SymbolsTable, atoi(token));
                  if (locationLine != -1) {
                    LMS[location] = 4100 + locationLine;
                    location++;
                  }
                  // Si no, se agrega al arreglo banderas
                  else {
                    LMS[location] = 4100;
                    flags[location] = atoi(token);
                    location++;
                  }
                }
              }
            }
            // Si es menor o igual que
            else if (strcmp(token, "<=") == 0) {
              // Busca la segunda variable
              token = strtok(NULL, " ");
              int locationVar2 = findVariable(SymbolsTable, token[0]);
              if (locationVar2 != -1) {
                // Carga la primera variable al acumulador
                LMS[location] = 2000 + locationVar1;
                location++;
                // Resta la segunda variable del acumulador
                LMS[location] = 3100 + locationVar2;
                location++;
                token = strtok(NULL, " ");
                // Si el siguiente token es goto
                if (strcmp(token, "goto") == 0) {
                  token = strtok(NULL, " ");

                  // Se busca la linea
                  int locationLine = findLine(SymbolsTable, atoi(token));
                  if (locationLine != -1) {
                    LMS[location++] = 4100 + locationLine;
                    LMS[location++] = 4200 + locationLine;
                  }
                  // Si no, se agrega al arreglo banderas
                  else {
                    LMS[location] = 4100;
                    flags[location++] = atoi(token);
                    LMS[location] = 4200;
                    flags[location++] = atoi(token);
                  }
                }
              }
            }
            // Si es mayor o igual que
            else if (strcmp(token, ">=") == 0) {
              // Busca la segunda variable
              token = strtok(NULL, " ");
              int locationVar2 = findVariable(SymbolsTable, token[0]);
              if (locationVar2 != -1) {
                // Carga la segunda variable al acumulador
                LMS[location] = 2000 + locationVar2;
                location++;
                // Resta la primera variable al acumulador
                LMS[location] = 3100 + locationVar1;
                location++;
                token = strtok(NULL, " ");
                // Si el siguiente token es goto
                if (strcmp(token, "goto") == 0) {
                  token = strtok(NULL, " ");

                  // Se busca la linea
                  int locationLine = findLine(SymbolsTable, atoi(token));
                  if (locationLine != -1) {
                    LMS[location++] = 4100 + locationLine;
                    LMS[location++] = 4200 + locationLine;
                  }
                  // Si no, se agrega al arreglo banderas
                  else {
                    LMS[location] = 4100;
                    flags[location++] = atoi(token);
                    LMS[location] = 4200;
                    flags[location++] = atoi(token);
                  }
                }
              }
            }
            // Si el simbolo es igual que
            else if (strcmp(token, "==") == 0) {
              // Busca la segunda variable
              token = strtok(NULL, " ");
              int locationVar2 = findVariable(SymbolsTable, token[0]);
              if (locationVar2 != -1) {
                // Carga la primera variable al acumulador
                LMS[location] = 2000 + locationVar1;
                location++;
                // Resta la segunda variable del acumulador
                LMS[location] = 3100 + locationVar2;
                location++;
                token = strtok(NULL, " ");
                // Si el siguiente token es goto
                if (strcmp(token, "goto") == 0) {
                  token = strtok(NULL, " ");

                  // Se busca la linea
                  int locationLine = findLine(SymbolsTable, atoi(token));
                  if (locationLine != -1) {
                    LMS[location] = 4200 + locationLine;
                    location++;
                  }
                  // Si no, se agrega al arreglo banderas
                  else {
                    LMS[location] = 4200;
                    flags[location] = atoi(token);
                    location++;
                  }
                }
              }
            }
          }
        } // fin del else if("if");

        // Si el token es end
        else if (strcmp(token, "end") == 0) {
          LMS[location] = 4300;
          location++;
        }
        token = strtok(NULL, " \n");
      }
      // Lee la siguiente linea
      fgets(read, sizeof(read), simpleFile);
    }
    fclose(simpleFile);

    // Resuelve las banderas
    findFlags(flags, LMS, SymbolsTable);
    // Escribe el codigo LMS en un archivo
    char outName[20];
    printf("\n\nIngrese el nombre del ejecutable: ");
    scanf("%s", outName);
    putchar('\n');

    FILE *out = fopen(outName, "w");
    for (int i = 0; i <= 99 && LMS[i] != 0; i++) {
      fprintf(out, "%d\n", LMS[i]);
    }

    fclose(out);

  } else {
    printf("No se pudo abrir el archivo %s\n", simple);
  }

  // Desplegar mensaje de error si no se abre el archivo
  return 0;
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
// Funciones para buscar simbolos en el arreglo banderas
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

// Funciones para calculos postFixed
int calculaExpresionsPostFixed(char *expr) {
  ptrHeapNode heap = NULL;
  int x = 0;
  int y = 0;
  for (; *expr != '\0'; expr++) {
    if (*expr != ' ' && isOperator(*expr)) {
      printHeap(heap);
    }
    // Si el caracter actual es un digito se inserta en la pila
    if (isdigit(*expr)) {
      push(&heap, *expr - '0');
    }
    // Si el caracter actual es un operador
    else if (isOperator(*expr)) {
      /* restar '0' para hacer la conversion a un numero entero */
      x = pop(&heap);
      y = pop(&heap);

      printf("%d %c %d = %d\n", y, *expr, x, calculate(y, x, *expr));
      push(&heap, calculate(y, x, *expr));
    }
  }
  return pop(&heap);
}
void convertToPostFixed(char inFixed[], char postFixed[]) {
  ptrHeapNode heap = NULL;
  int countIn = 0;
  int countPost = 0;
  push(&heap, '(');
  while (inFixed[countIn] != '\0') {
    countIn++;
  }
  // Agrega un parentesis derecho al final de infijo
  inFixed[countIn] = ')';
  inFixed[++countIn] = '\0';

  while (!isEmpty(heap)) {
    for (int i = 0; inFixed[i] != '\0'; i++) {
      // Si el elemento actual de infijo es un digito copiar postfijo
      if (isdigit(inFixed[i])) {
        postFixed[countPost++] = inFixed[i];
      }
      // Si el elemento actual de infijo es un ( meter en la pila
      else if (inFixed[i] == '(') {
        push(&heap, inFixed[i]);
      }
      // Si el elemento actual de infijo es un operador
      else if (isOperator(inFixed[i])) {
        /* Saca los operadores de la pila que tengan una precendencia mayor o
         * igual que el operador actual de infijo */
        while (isOperator(heapTop(heap)) &&
               precedence(heapTop(heap), inFixed[i]) >= 0) {
          postFixed[countPost++] = pop(&heap);
        }

        // Inserta el caracter actual de infijo a la cima de la pila
        push(&heap, inFixed[i]);
      }

      // Si el elemento actual de infijo es un )
      else if (inFixed[i] == ')') {
        /* Saca los operadores de la pila y los inserta en postfijo
         * hasta que haya un ( en la pila */
        while (heapTop(heap) != '(') {
          postFixed[countPost++] = pop(&heap);
        }
      }
    }

    // Extrae el ( de la pila y termina el bucle
    while (!isEmpty(heap)) {
      pop(&heap);
    }
  }
}

int calculate(int op1, int op2, char operator) {
  int total = 1;
  switch (operator) {
  case '+':
    return op1 + op2;
    break;
  case '-':
    return op1 - op2;
    break;
  case '*':
    return op1 * op2;
    break;
  case '%':
    return op1 % op2;
    break;
  case '/':
    return op1 / op2;
    break;
  case '^':
    for (int i = 1; i <= op2; i++) {
      total *= op1;
    }
    return total;
    break;
  }
  return printf("\nNo se pudo realizar una operacion valida\n");
}

int isEmpty(ptrHeapNode ptrTop) {
  /* retorna 1 si la pila esta vacia, retorna 0 si no */
  return ptrTop == NULL;
}

int isOperator(char c) {
  /* retorna 1 si el caracter es un operador, retorna 0 si no */
  switch (c) {
  case '+':
  case '-':
  case '*':
  case '%':
  case '/':
  case '^':
    return 1;
    break;
  }
  return 0;
}
int precedence(char operator1, char operator2) {

  // Retornar 0 si el operador 1 es igual que el operador 2
  if (operator1 == operator2) {
    return 0;
  }

  int value1 = 0;
  int value2 = 0;

  // Determina la jerarquia del operador 1
  switch (operator1) {
  case '+':
  case '-':
    value1 = 1;
    break;

  case '*':
  case '%':
  case '/':
    value1 = 2;
    break;

  case '^':
    value1 = 3;
    break;
  }

  // Determina la jerarquia del operador 2
  switch (operator2) {
  case '+':
  case '-':
    value2 = 1;
    break;

  case '*':
  case '%':
  case '/':
    value2 = 2;
    break;

  case '^':
    value2 = 3;
    break;
  }

  // Retornar -1 si el operador 1 es menor que el operador 2
  if (value1 < value2) {
    return -1;
  }
  // Retornar 1 si el operador 1 es mayor que el operador 2
  else if (value1 > value2) {
    return 1;
  }
  // Retornar 0 si el operador 1 es igual que el operador 2
  else if (value1 == value2) {
    return 0;
  }

  return printf("\nUno de los caracteres no es un operador  caracter1 = %c "
                "caracter 2 = %c\n",
                operator1, operator2);
}

void push(ptrHeapNode *ptrTop, char value) {
  ptrHeapNode New = malloc(sizeof(struct heapNode));

  if (New != NULL) {
    New->data = value;
    New->ptrNextNode = *ptrTop;
    *ptrTop = New;
  } else {
    printf("\nNo hay espacio suficiente para insertar %c\n", value);
  }
}

char pop(ptrHeapNode *ptrTop) {

  ptrHeapNode temp = *ptrTop;
  char value = (*ptrTop)->data;
  *ptrTop = (*ptrTop)->ptrNextNode;
  free(temp);
  // Devolver valor extraido de la pila
  return value;
}
char heapTop(ptrHeapNode ptrTop) {
  /* Retorna el valor que esta en la cima de la pila sin modificarlo */
  return ptrTop->data;
}

void printHeap(ptrHeapNode ptrTop) {
  if (ptrTop != NULL) {
    while (ptrTop != NULL) {
      printf("%c", ptrTop->data);
    }
  } else {
    printf("\nLa pila esta vacia\n");
  }
  putchar('\n');
}
