#include <stdio.h>
#include <stdlib.h>

struct nodeTree {
  struct nodeTree *ptrLeft;
  int value;
  struct nodeTree *ptrRight;
};

typedef struct nodeTree *ptrNodeTree;

int deep(ptrNodeTree ptrTree);
void insertNode(ptrNodeTree *ptrTree, int value);
int main() {
  ptrNodeTree root = NULL;
  int deeply = 0;
  insertNode(&root, 32);
  insertNode(&root, 3);
  insertNode(&root, 2);
  insertNode(&root, 4);
  insertNode(&root, 5);
  insertNode(&root, 34);
  insertNode(&root, 35);
  insertNode(&root, 1);
  deeply = deep(root);
  printf("La profundidad del arbol es:%d\n", deeply);
  return 0;
}

int deep(ptrNodeTree ptrTree) {
  static int deeply = 0;
  if (ptrTree != NULL) {
    deeply++;
    deep(ptrTree->ptrLeft);
    if (ptrTree->ptrRight != NULL) {
      deep(ptrTree->ptrRight);
      deeply--;
    }
  }
  return deeply;
}
void insertNode(ptrNodeTree *ptrTree, int value) {
  // El arbol esta vacio
  if (*ptrTree == NULL) {
    *ptrTree = malloc(sizeof(struct nodeTree));

    if (*ptrTree != NULL) {
      (*ptrTree)->value = value;
      (*ptrTree)->ptrLeft = NULL;
      (*ptrTree)->ptrRight = NULL;
    } else {
      printf("\nNo se inserto %d, memoria insuficiente\n", value);
    }
  }

  // El arbol no esta vacio
  else {

    // Si es menor insertar en el nodo actual
    if (value < (*ptrTree)->value) {
      insertNode(&((*ptrTree)->ptrLeft), value);
    }
    // Si es mayor insertar en el nodo actual
    else if (value > (*ptrTree)->value) {
      insertNode(&((*ptrTree)->ptrRight), value);
    }
  }
}
