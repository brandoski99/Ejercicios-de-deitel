#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char character;
  struct node *ptrNextNode;
};

typedef struct node *ptrNode;
void push(ptrNode *climb, char character);
void printHeap(ptrNode heap);

int main() {
  char line[256];
  ptrNode heap = NULL;
  printf("Inserte una linea:\n");
  fgets(line, sizeof(line), stdin);
  // Intercambia '\n' por '\0'
  line[strlen(line) - 1] = line[strlen(line)];
  line[strlen(line)] = ' '; // Elimina el '\0' sobrante

  // Inserta los caracteres de la linea en la pila
  for (int i = 0; i < strlen(line); i++) {
    push(&heap, line[i]);
  }
  printf("La linea es: %s\n", line);
  printf("La linea invertida es:");
  printHeap(heap);
  return 0;
}

void push(ptrNode *climb, char character) {
  ptrNode New = malloc(sizeof(struct node));

  if (New != NULL) {
    New->character = character;
    New->ptrNextNode = *climb;
    *climb = New;
  } else {
    printf("\nNo hay memoria suficiente para insertar %c en la pila\n",
           character);
  }
}

void printHeap(ptrNode heap) {
  if (heap != NULL) {
    while (heap != NULL) {
      printf("%c", heap->character);
      heap = heap->ptrNextNode; // Pasar al siguiente nodo
    }
  } else {
    printf("\nLa pila esta vacia\n");
  }
}
