#include <stdio.h>
#include <stdlib.h>
struct node {
  char letter;
  struct node *ptrNextNode;
};

typedef struct node *ptrNode;

void insert(ptrNode *ptrS, char letter);
void printList(ptrNode ptrCurrent);
void concatList(ptrNode *ptrList1, ptrNode ptrList2);

int main() {
  ptrNode firstList = NULL;
  ptrNode secondList = NULL;

  // Inicializa la primera lista
  for (int i = 'a'; i <= 'm'; i++) {
    insert(&firstList, i);
  }
  printf("La primera lista ligada es:\n");
  printList(firstList);

  // Inicializa la segunda lista
  for (int i = 'n'; i <= 'z'; i++) {
    insert(&secondList, i);
  }
  printf("La segunda lista ligada es:\n");
  printList(secondList);

  concatList(&firstList, secondList);
  printf("La lista concatenada es:\n");
  printList(firstList);
  return 0;
}

void insert(ptrNode *ptrS, char letter) {
  ptrNode ptrNew;
  ptrNode ptrLast;
  ptrNode ptrCurrent;

  ptrNew = malloc(sizeof(struct node)); // Crear nuevo nodo

  if (ptrNew != NULL) {
    ptrNew->letter = letter;
    ptrNew->ptrNextNode = NULL;
    ptrLast = NULL;
    ptrCurrent = *ptrS;

    // Ubicar la letra en la posicion correcta
    while (ptrCurrent != NULL && letter > ptrCurrent->letter) {
      ptrLast = ptrCurrent;
      ptrCurrent = ptrCurrent->ptrNextNode; // Pasar al siguiente nodo
    }

    // insertar nuevo nodo al principio de la lista
    if (ptrLast == NULL) {
      ptrNew->ptrNextNode = *ptrS;
      *ptrS = ptrNew;
    } else { /* inserta un nuevo nodo entre ptrLast y ptrCurrent */
      ptrLast->ptrNextNode = ptrNew;
      ptrNew->ptrNextNode = ptrCurrent;
    }

  } else {
    printf("No se inserto %c, no hay memoria disponible", letter);
  }
}

void printList(ptrNode ptrCurrent) {
  if (ptrCurrent == NULL) {
    printf("La lista esta vacia");
  } else {
    putchar('\n');

    while (ptrCurrent != NULL) {
      printf("%c --> ", ptrCurrent->letter);
      ptrCurrent = ptrCurrent->ptrNextNode;
    }
    printf("NULL\n\n");
  }
}

void concatList(ptrNode *ptrList1, ptrNode ptrList2) {

  ptrNode ptrCurrent = *ptrList1;
  ptrNode ptrLast = NULL;
  if (*ptrList1 == NULL || ptrList2 == NULL) {
    printf("Una de las listas esta vacia\n");
  } else {
    // Llevar la primera lista hasta su ultimo elemento(NULL)
    while (ptrCurrent != NULL) {
      ptrLast = ptrCurrent;
      ptrCurrent = ptrCurrent->ptrNextNode;
    }
    ptrLast->ptrNextNode = ptrList2;
  }
}
