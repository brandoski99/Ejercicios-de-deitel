#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *ptrNextNode;
};

typedef struct node *ptrNode;

void insert(ptrNode *ptrList, int value);
void printList(ptrNode ptrList);
ptrNode searchValue(ptrNode ptrList, int key);
int main() {
  ptrNode list = NULL;
  int value = 0;
  ptrNode search = NULL;
  for (int i = 1; i <= 15; i++) {
    insert(&list, i);
  }
  printf("Introduzca un valor a buscar: ");
  scanf("%d", &value);

  search = searchValue(list, value);
  if (search != NULL) {
    printf("\nEl valor %d, si se encuentra en la lista\n", search->value);
  } else {
    printf("\nEl valor %d, no se encuentra en la lista\n", value);
  }
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

ptrNode searchValue(ptrNode ptrList, int key) {
  if (ptrList->value != key) {
    // Si el siguiente nodo es NULL, retorna NULL(el valor no esta en la lista)
    if (ptrList->ptrNextNode == NULL) {
      return NULL;
    } else {
      // Si el siguiente nodo no es NULL, se ejecuta la funcion con ese nodo
      searchValue(ptrList->ptrNextNode, key);
    }
  }
  // Si el valor de la lista es igual al valor, retornar apuntador a ese nodo
  else {
    return ptrList;
  }
}
