#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 0) {
    printf("Los argumentos introducidos son:\n");
    for (int count = 0; count < argc; count++) {
      printf("%s\t", argv[count]);
    }
    putchar('\n');

  }
  // Si el usuario no introduce ningun argumento
  else {
    printf("No se introdujo ningun argumento!\n");
  }
}
