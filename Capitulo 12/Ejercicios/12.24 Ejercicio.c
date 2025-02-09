#include <stdio.h>
#include <stdlib.h>

// Estructura arbol binario
struct nodeTree {
  struct nodeTree *ptrLeft;
  int value;
  struct nodeTree *ptrRight;
};
typedef struct nodeTree *ptrNodeTree;

// Estructura Cola
struct nodeLine {
  ptrNodeTree value;
  struct nodeLine *ptrNextNode;
};
typedef struct nodeLine *ptrNodeLine;

// Funciones de la cola
void add(ptrNodeLine *head, ptrNodeLine *foot, ptrNodeTree value);
ptrNodeTree retire(ptrNodeLine *head, ptrNodeLine *foot);
void insertNode(ptrNodeTree *root, int value);
void levelsOrder(ptrNodeTree root);
int main() {
  ptrNodeTree root = NULL;

  insertNode(&root, 99);
  insertNode(&root, 43);
  insertNode(&root, 102);
  insertNode(&root, 2);
  insertNode(&root, 4);
  insertNode(&root, 1);

  levelsOrder(root);
  return 0;
}

void levelsOrder(ptrNodeTree root) {
  ptrNodeLine head = NULL;
  ptrNodeLine foot = NULL;

  add(&head, &foot, root);
  while (head != NULL) {
    root = retire(&head, &foot);
    printf("%d ", root->value);

    if (root->ptrLeft != NULL) {
      add(&head, &foot, root->ptrLeft);
    }

    if (root->ptrRight != NULL) {
      add(&head, &foot, root->ptrRight);
    }
  }
}
void add(ptrNodeLine *head, ptrNodeLine *foot, ptrNodeTree value) {
  ptrNodeLine New = malloc(sizeof(struct nodeLine));

  if (New != NULL) {
    New->value = value;
    New->ptrNextNode = NULL;
    // Si la cola esta vacia se agrega el nodo al principio
    if (*head == NULL) {
      *head = New;
    } else {
      (*foot)->ptrNextNode = New;
    }
    *foot = New;
  }

  else {
    printf("\nNo se inserto el nodo, memoria insuficiente\n");
  }
}
ptrNodeTree retire(ptrNodeLine *head, ptrNodeLine *foot) {
  ptrNodeTree value;
  ptrNodeLine temp;

  value = (*head)->value;
  temp = *head;
  *head = (*head)->ptrNextNode;

  if (*head == NULL) {
    *foot = NULL;
  }

  free(temp);

  return value;
}
void insertNode(ptrNodeTree *root, int value) {

  if (*root == NULL) {
    *root = malloc(sizeof(struct nodeTree));

    if (*root != NULL) {
      (*root)->value = value;
      (*root)->ptrLeft = NULL;
      (*root)->ptrRight = NULL;
    }

    else {
      printf("\nNo se inserto %d, memoria insuficiente\n", value);
    }

  }

  else {

    // Si el dato es menor al valor del nodo actual se inserta al lado izquierdo
    if (value < (*root)->value) {
      insertNode(&((*root)->ptrLeft), value);
    }

    // Si el dato es mayor al valor del nodo actual se inserta al lado derecho
    else if (value > (*root)->value) {
      insertNode(&((*root)->ptrRight), value);
    }
  }
}
