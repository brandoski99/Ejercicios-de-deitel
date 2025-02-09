#include <stdio.h>
#include <stdlib.h>

// Estructura arbol binario
struct nodeTree {
  struct nodeTree *ptrLeft;
  int value;
  struct nodeTree *ptrRight;
};
typedef struct nodeTree *ptrNodeTree;

void insertNode(ptrNodeTree *root, int value);
void printTree(ptrNodeTree root, int totalSpaces);
int main() {
  ptrNodeTree binaryTree = NULL;

  insertNode(&binaryTree, 49);
  insertNode(&binaryTree, 83);
  insertNode(&binaryTree, 28);
  insertNode(&binaryTree, 97);
  insertNode(&binaryTree, 71);
  insertNode(&binaryTree, 40);
  insertNode(&binaryTree, 18);
  insertNode(&binaryTree, 99);
  insertNode(&binaryTree, 92);
  insertNode(&binaryTree, 72);
  insertNode(&binaryTree, 69);
  insertNode(&binaryTree, 44);
  insertNode(&binaryTree, 32);
  insertNode(&binaryTree, 19);
  insertNode(&binaryTree, 11);

  printTree(binaryTree, 0);
  return 0;
}

void printTree(ptrNodeTree root, int totalSpaces) {
  if (root != NULL) {
    printTree(root->ptrRight, totalSpaces + 5);
    for (int i = 1; i <= totalSpaces; i++) {
      printf(" ");
    }
    printf("%d\n", root->value);
    printTree(root->ptrLeft, totalSpaces + 5);
  }
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
