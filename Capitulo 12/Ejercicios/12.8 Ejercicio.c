#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
  int value;
  struct node *ptrNextNode;
};

typedef struct node *ptrNode;

void insert(ptrNode *ptrList, int value);
void printList(ptrNode ptrList);
int sumList(ptrNode ptrList, int count);

int main() {
  srand(time(NULL));

  ptrNode list = NULL;
  int total = 0;
  // Insertar 25 numeros a aleatorios del 0-100
  for (int i = 1; i <= 25; i++) {
    insert(&list, 0 + rand() % 100);
  }

  printList(list);
  total = sumList(list, 25);
  printf("\nLa suma de los 25 enteros es: %d\n", total);
  printf("\nEl promedio de todos los valores es: %.2f\n", (double)total / 25);
  return 0;
}

void insert(ptrNode *ptrList, int value) {
  ptrNode Current;
  ptrNode New;
  ptrNode Last;

  New = malloc(sizeof(struct node)); // Crear nuevo nodo

  if (New != NULL) {
    New->value = value;
    New->ptrNextNode = NULL;
    Current = *ptrList;
    Last = NULL;

    // Ubicar el entero en la posicion correcta
    while (Current != NULL && value > Current->value) {
      Last = Current;
      Current = Current->ptrNextNode;
    }

    // Insertar el entero al inicio de la list
    if (Last == NULL) {
      New->ptrNextNode = *ptrList;
      *ptrList = New;
    }
    // Insertar entre Last y Current
    else {
      Last->ptrNextNode = New;
      New->ptrNextNode = Current;
    }

  } else {
    printf("\nNo se pudo crear el nuevo nodo, memoria insuficiente\n");
  }
}

void printList(ptrNode ptrList) {
  if (ptrList == NULL) {
    printf("\nLa lista esta vacia\n");
  } else {
    while (ptrList != NULL) {
      printf("%d --> ", ptrList->value);
      ptrList = ptrList->ptrNextNode;
    }
    printf("NULL\n\n");
  }
}

int sumList(ptrNode ptrList, int count) {
  int i = 1; // Cuenta cuantos numeros sean sumado
  int total = 0;

  if (ptrList == NULL) {
    printf("\nLa lista esta vacia\n");
  }
  while (ptrList != NULL && i <= count) {
    total += ptrList->value;
    ptrList = ptrList->ptrNextNode; // Pasar al siguente nodo
    i++;
  }
  return total;
}
