// IMPORTANTE LEER LOS ENUNCIADOS DE LOS PROBLEMAS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
struct heapNode {
  int data; // Aqui habia puesto char
  struct heapNode *ptrNextNode;
};
typedef struct heapNode *ptrHeapNode;

int calculaExpresionsPostFixed(char *expr);
int isEmpty(ptrHeapNode ptrTop);
void printHeap(ptrHeapNode ptrTop);
void push(ptrHeapNode *ptrTop, int value);
int pop(ptrHeapNode *ptrTop);
int calculate(int op1, int op2, char operator);
int isOperator(char c);

int main() {
  char postFix[] = "62 + 5 * 8 4 / -";

  printf("El resultado de la operacion es: %d\n",
         calculaExpresionsPostFixed(postFix));
  return 0;
}

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
int isEmpty(ptrHeapNode ptrTop) {
  /* retorna 1 si la pila esta vacia, retorna 0 si no */
  return ptrTop == NULL;
}

void printHeap(ptrHeapNode ptrTop) {
  if (ptrTop != NULL) {
    while (ptrTop != NULL) {
      printf("%d-> ", ptrTop->data);
      ptrTop = ptrTop->ptrNextNode;
    }
    printf("NULL\n\n");
  } else {
    printf("\nLa pila esta vacia\n");
  }
}

void push(ptrHeapNode *ptrTop, int value) {
  ptrHeapNode New = malloc(sizeof(struct heapNode));

  if (New != NULL) {
    New->data = value;
    New->ptrNextNode = *ptrTop;
    *ptrTop = New;
  } else {
    printf("\nNo hay espacio suficiente para insertar %c\n", value);
  }
}

int pop(ptrHeapNode *ptrTop) {

  ptrHeapNode temp = *ptrTop;
  int value = (*ptrTop)->data;
  *ptrTop = (*ptrTop)->ptrNextNode;
  free(temp);
  // Devolver valor extraido de la pila
  return value;
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
