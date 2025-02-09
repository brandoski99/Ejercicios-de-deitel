#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  char character;
  struct node *ptrNextNode;
};

typedef struct node *ptrNode;

void push(ptrNode *climb, char character);
void printHeap(ptrNode heap);

int main() {
  ptrNode heap = NULL;
  char str[] = "La ruta nos aporto otro paso natural.";
  int bool = 0;

  // Inserta los caracteres de la cadena en orden inverso en la pila
  for (int i = 0; str[i] != '\0'; i++) {
    push(&heap, str[i]);
  }
  ptrNode temp = heap;
  // determinar si es palindromo
  for (int i = 0; str[i] != '\0' && temp != NULL;
       i++, temp = temp->ptrNextNode) {

    /* Si el caracter es un espacio o signo de puntuacion se omite */
    if (ispunct(temp->character) || isspace(temp->character)) {
      while (ispunct(temp->character) || isspace(temp->character)) {
        temp = temp->ptrNextNode;
      }
    }

    if (ispunct(str[i]) || isspace(str[i])) {
      while (ispunct(str[i]) || isspace(str[i])) {
        i++;
      }

      /*                                                            */
    }
    // printf("%c = %c\n", tolower(str[i]), tolower(temp->character));
    // Transforma en minuscula
    if (tolower(str[i]) == tolower(temp->character)) {
      // printf("%c = %c\n", tolower(str[i]), tolower(temp->character));
      bool = 1;
    } else {
      bool = 0;
      break;
    }
  }

  // Si bool es 1 es un palindromo, si es 0 no lo es
  bool ? printf("\nLa cadena \"%s\" si es un palindromo\n\n", str)
       : printf("\nLa cadena \"%s\" no es un palindromo\n\n", str);

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
    putchar('\n');
  } else {
    printf("\nLa pila esta vacia\n");
  }
}
