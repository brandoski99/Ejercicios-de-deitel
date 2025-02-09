#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct heapNode {
  char data;
  struct heapNode *ptrNextNode;
};
typedef struct heapNode *ptrHeapNode;

void convertToPostFixed(char inFixed[], char postFixed[]);
int isOperator(char c);
int precedence(char operator1, char operator2);
void push(ptrHeapNode *ptrTop, char value);
char pop(ptrHeapNode *ptrTop);
char heapTop(ptrHeapNode ptrTop);
int isEmpty(ptrHeapNode ptrTop);
void printHeap(ptrHeapNode ptrTop);

int main() {
  char inFix[30] = "(6 + 2) * 5 - 8 / 4";
  char postFix[30];

  convertToPostFixed(inFix, postFix);
  printf("%s\n", postFix);
  return 0;
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
