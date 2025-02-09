#include <stdio.h>
#include <stdlib.h>

struct node {
  char letter;
  struct node *ptrNextNode;
};

typedef struct node *ptrNode;

void insert(ptrNode *ptrS, char letter);
void printList(ptrNode ptrCurrent);
ptrNode reverseList(ptrNode originalList);

int main() {
  ptrNode list = NULL;
  ptrNode reverse = NULL;

  insert(&list, 'T');
  insert(&list, 'e');
  insert(&list, 'r');
  insert(&list, 'r');
  insert(&list, 'y');
  printf("La lista original es:\n");
  printList(list);
  printf("La lista invertida es:\n");
  reverse = reverseList(list);
  printList(reverse);
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

ptrNode reverseList(ptrNode originalList) {
  ptrNode reverse = NULL;
  ptrNode List = originalList;
  ptrNode Current = NULL;
  ptrNode Last = NULL;
  ptrNode New = malloc(sizeof(struct node));
  int i = 0;

  // Cuenta cuantos caracteres tiene la lista
  while (List != NULL) {
    List = List->ptrNextNode;
    i++;
  }
  List = originalList;

  while (i > 0) {
    int j = 1;
    // Recorre desde el ultimo caracter, luego el penultimo...primero
    while (j < i) {
      List = List->ptrNextNode;
      j++;
    }
    ptrNode New = malloc(sizeof(struct node));
    New->letter = List->letter;
    New->ptrNextNode = NULL;
    Current = reverse;
    while (Current != NULL) {
      Last = Current;
      Current = Current->ptrNextNode;
    }
    if (Last == NULL) {
      reverse = New;
    } else {
      Last->ptrNextNode = New;
      New->ptrNextNode = Current;
    }
    i--;
    List = originalList;
  }
  return reverse;
}
