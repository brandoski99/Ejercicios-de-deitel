#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodeTree {
  struct nodeTree *ptrLeft;
  char *word;
  struct nodeTree *ptrRight;
};

typedef struct nodeTree *ptrNodeTree;

void insertNode(ptrNodeTree *ptrTree, char *word);
void inOrden(ptrNodeTree ptrTree);
void preOrden(ptrNodeTree ptrTree);
void postOrden(ptrNodeTree ptrTree);
int main() {

  char text[256];
  fgets(text, sizeof(text), stdin);
  text[strlen(text) - 1] = '\0'; // Elimina el '\n'
  ptrNodeTree root = NULL;
  char *token = strtok(text, " ");
  while (token != NULL) {
    insertNode(&root, token);
    token = strtok(NULL, " ");
  }
  printf("\nInOrden:\n");
  inOrden(root);
  printf("\npreOrden:\n");
  preOrden(root);
  printf("\npostOrden:\n");
  postOrden(root);
  return 0;
}

void insertNode(ptrNodeTree *ptrTree, char *word) {
  // El arbol esta vacio
  if (*ptrTree == NULL) {
    *ptrTree = malloc(sizeof(struct nodeTree));

    if (*ptrTree != NULL) {
      (*ptrTree)->word = word;
      (*ptrTree)->ptrLeft = NULL;
      (*ptrTree)->ptrRight = NULL;
    } else {
      printf("\nNo se inserto %s, memoria insuficiente\n", word);
    }
  }

  // El arbol no esta vacio
  else {

    // Si es menor/igual insertar en el nodo actual
    if (strcmp(word, (*ptrTree)->word) < 0) {
      insertNode(&((*ptrTree)->ptrLeft), word);
    }
    // Si es mayor insertar en el nodo actual
    else if (strcmp(word, (*ptrTree)->word) > 0 ||
             strcmp(word, (*ptrTree)->word) == 0) {
      insertNode(&((*ptrTree)->ptrRight), word);
    }
  }
}

void inOrden(ptrNodeTree ptrTree) {
  if (ptrTree != NULL) {
    inOrden(ptrTree->ptrLeft);
    printf("%s ", ptrTree->word);
    inOrden(ptrTree->ptrRight);
  }
}

void preOrden(ptrNodeTree ptrTree) {
  if (ptrTree != NULL) {
    printf("%s ", ptrTree->word);
    preOrden(ptrTree->ptrLeft);
    preOrden(ptrTree->ptrRight);
  }
}

void postOrden(ptrNodeTree ptrTree) {
  if (ptrTree != NULL) {
    postOrden(ptrTree->ptrLeft);
    postOrden(ptrTree->ptrRight);
    printf("%s ", ptrTree->word);
  }
}
