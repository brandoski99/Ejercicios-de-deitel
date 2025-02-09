#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *ptrNextNode;
};

typedef struct node *ptrNode;

void insert(ptrNode *ptrList, int value);
void printList(ptrNode ptrList);
void reverseList(ptrNode ptrList);
int main() {
  ptrNode list = NULL;
  for (int i = 1; i <= 15; i++) {
    insert(&list, i);
  }
  printf("La lista en orden normal:\n");
  printList(list);
  printf("\nLa lista en orden inverso:\n");
  reverseList(list);
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
  if (ptrList != NULL) {
    while (ptrList != NULL) {
      printf("%d ", ptrList->value);
      ptrList = ptrList->ptrNextNode;
    }
  }
}

void reverseList(ptrNode ptrList) {
  if (ptrList != NULL) {
    reverseList(ptrList->ptrNextNode);
    printf("%d ", ptrList->value);
  }
}
