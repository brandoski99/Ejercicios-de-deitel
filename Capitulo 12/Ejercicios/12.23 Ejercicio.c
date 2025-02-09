#include <stdio.h>
#include <stdlib.h>

struct nodeTree {
  struct nodeTree *ptrLeft;
  int value;
  struct nodeTree *ptrRight;
};

typedef struct nodeTree *ptrNodeTree;

void insertNode(ptrNodeTree *ptrTree, int value);
ptrNodeTree searchValue(ptrNodeTree ptrTree, int key);
int main() {
  ptrNodeTree root = NULL;
  ptrNodeTree search = NULL;
  int key = 0;
  insertNode(&root, 23);
  insertNode(&root, 13);
  insertNode(&root, 44);
  insertNode(&root, 26);
  insertNode(&root, 3);
  insertNode(&root, 99);

  scanf("%d", &key);
  search = searchValue(root, key);

  if (search != NULL) {
    printf("\nEl valor %d si se encuentra en el arbol\n", search->value);
  } else {

    printf("\nEl valor %d no se encuentra en el arbol\n", key);
  }

  return 0;
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

ptrNodeTree searchValue(ptrNodeTree ptrTree, int key) {
  if (ptrTree != NULL) {

    // Si se encuentra el valor se retorna la direccion a ese nodo
    if (ptrTree->value == key) {
      return ptrTree;
    }

    /* Si el valor a buscar es menor que el valor del nodo actual, se busca en
       el subarbol-izquierdo */
    else if (key < ptrTree->value) {
      searchValue(ptrTree->ptrLeft, key);
    }

    /* Si el valor a buscar es mayor que el valor del nodo actual, se busca en
             el subarbol-Derecho */
    else if (key > ptrTree->value) {
      searchValue(ptrTree->ptrRight, key);
    }
  }
}
