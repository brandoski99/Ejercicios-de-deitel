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
ptrNode mixList(ptrNode firstList, ptrNode secondList);

int main() {
  ptrNode firsList = NULL;
  ptrNode secondList = NULL;
  ptrNode sortMix = NULL;
  // Inicializar las 2 listas
  srand(time(NULL));
  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
      insert(&firsList, 1 + rand() % 100);
    } else {
      insert(&secondList, 1 + rand() % 100);
    }
  }

  printf("La primera lista es:\n");
  printList(firsList);

  printf("La segunda lista es:\n");
  printList(secondList);

  sortMix = mixList(firsList, secondList);
  printf("La mezcla de ambas listas es:\n");
  printList(sortMix);

  // printList(firsList);
  // printList(secondList);
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

ptrNode mixList(ptrNode firstList, ptrNode secondList) {
  ptrNode mix = NULL;

  while (firstList != NULL || secondList != NULL) {

    // inserta por VALOR los enteros de firstList
    if (firstList != NULL) {
      insert(&mix, firstList->value);
      firstList = firstList->ptrNextNode;
    }

    // inserta por VALOR los enteros de secondList
    if (secondList != NULL) {
      insert(&mix, secondList->value);
      secondList = secondList->ptrNextNode;
    }
  }
  return mix;
}
