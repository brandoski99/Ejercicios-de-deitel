#include <stdio.h>
#include <string.h>
void reverseLine(char line[]);
int main(int argc, char *argv[]) {
  char line[256];

  if (argc == 3) {
    FILE *readFile =
        fopen(argv[1], "r"); // Abre el primer archivo en modo lectura

    if (readFile != NULL) {
      FILE *newFile = fopen(argv[2], "w"); // Crear el segundo archivo
      if (newFile != NULL) {
        // Lee el primer archivo hasta llegar al final

        fgets(line, sizeof(line), readFile);

        while (!feof(readFile)) {
          // Empieza a escribir el archivo en reversa
          for (int i = strlen(line) - 1; i >= 0; i--) {
            putc(line[i], newFile);
          }
          fgets(line, sizeof(line), readFile);
        }
      }
      // Despliega error si el archivo no se puede crear
      else {
        printf("\nNo se pudo crear el archivo %s\n", argv[2]);
      }
    }
    // Despliega error si el primer archivo no se puede abrir
    else {
      printf("\nNo se pudo abrir el archivo %s\n", argv[1]);
    }
  }
  // Despliega error si el numero de argumentos es insuficiente
  else {
    printf("\nNumero de argumentos invalido\nLa ejecucion debe ser main.o "
           "archivo1.txt archivo2.txt\n");
  }
  return 0;
}
