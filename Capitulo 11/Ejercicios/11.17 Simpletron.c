#include <stdio.h>
/* Operaciones entrada y salida */
#define READ 10
#define WRITE 11
/* Operaciones de carga/almacenamiento */
#define LOAD 20
#define STORE 21
/* Operaciones aritmeticas */
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
/*Operaciones de transferencia de control*/
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void memoryDump(int memory[]);
int main() {
  int memory[100] = {0};
  int accumulator;            // Representa el registro del acumulador +0000
  int instructionCounter = 0; // registra la instruccion que se ejecuta 00
  int instructionRegister;    // registra las siguientes instrucciones +0000
  int operationCode;          // Indica la operacion que se va ejecutar 00
  int operand = 0; // Indica la ubicacion en memoria de la operacion actual 00
  char instructions[20];
  printf("*** Bienvenido a Simpletron!                       ***\n*** Por "
         "favor, introduzca a su programa una instruccion ***\n*** a la vez (o "
         "palabra de datos).         ***\n*** Yo escribire el numero de "
         "ubicacion y un      ***\n*** signo de interrogacion (?). Usted "
         "escriba ***\n*** la palabra para dicha ubicacion. Escriba el   "
         "****** centinela -9999 para terminar la    ***\n*** introduccion de "
         "datos a su programa.                  ***\n");

  printf("\nIntroduzca el archivo para leer las instrucciones: ");
  scanf("%s", instructions);
  putchar('\n');
  FILE *instructionsFile = fopen(instructions, "r");

  if (instructionsFile == NULL) {
    printf("\n***Error al intentar abrir el archivo %s***\n", instructions);
  } else {
    for (int i = 0; i < 100; i++) {
      fscanf(instructionsFile, "%d", &memory[i]);

      // Si la instruccion es 0 o -9999, entonces se deja de imprimir %d ? %d
      if (memory[i] == 0 || memory[i] == -9999) {
        i = 100;
      } else {
        printf("%d ? %+d\n", i, memory[i]);
        /* Verifica si el rango de la palabra es correcto */
        if (memory[i] > 9999 || memory[i] < -9999) {
          printf("***La palabra introducida excede el rango***\n");
          printf("***Introduzca una palabra en el rango de +9999 y -9999***\n");
          i--;
        }
      }

      printf("\n");
    }
    printf("*** Carga del programa completa ***\n*** Comienza la ejecucion del "
           "programa ***\n");

    while (memory[instructionCounter] != -9999 && instructionCounter < 100) {

      instructionRegister = memory[instructionCounter];
      operationCode = instructionRegister / 100;
      operand = instructionRegister % 100;
      // Operaciones
      switch (operationCode) {
      case READ:
        scanf("%d", &memory[operand]);
        break;
      case WRITE:
        printf("%d\n", memory[operand]);
        break;
      case LOAD:
        accumulator = memory[operand];
        break;
      case STORE:
        memory[operand] = accumulator;
        break;
      case ADD:
        accumulator += memory[operand];
        break;
      case SUBTRACT:
        accumulator -= memory[operand];
        break;
      case MULTIPLY:
        accumulator *= memory[operand];
        break;
      case DIVIDE:
        if (accumulator == 0 || memory[operand] == 0) {
          printf("***Division entre 0***\n");
          printf("***Finalizando Ejecucion del programa***\n");
          instructionCounter = 100;
        } else {
          accumulator /= memory[operand];
        }
        break;
        /* En las instrucciones BRANCH se resta 1 ya que se incrementa luego en
         * InstructionCounter++ */
      case BRANCH:
        instructionCounter = operand - 1;
        break;
      case BRANCHZERO:
        if (accumulator == 0) {
          instructionCounter = operand - 1;
        }
        break;
      case BRANCHNEG:
        if (accumulator < 0) {
          instructionCounter = operand - 1;
        }
        break;
      case HALT:
        printf("\n*** Finaliza ejecución de Simpletron ***\n");
        instructionCounter = 100;
        break;
      default:
        printf("ERROR: %d : %d ", operand, memory[instructionCounter]);
        printf("*** Palabra invalida, corriga la palabra ***\n");
        break;
      }
      instructionCounter++;
    }
    memoryDump(memory);
    fclose(instructionsFile);
  }
  return 0;
}

void memoryDump(int memory[]) {
  FILE *dataFile = fopen("data.dat", "w");
  fprintf(dataFile, "MEMORIA\n");
  printf("MEMORIA\n");
  for (int i = 0; i < 10; i++) {
    printf("\t%2d", i);
    fprintf(dataFile, "\t%6d", i);
  }

  for (int i = 0; i < 100; i++) {
    if (i % 10 == 0) {
      printf("\n%2d", i);
      fprintf(dataFile, "\n%2d", i);
    }
    memory[i] ? fprintf(dataFile, "%8d", memory[i])
              : fprintf(dataFile, "%8s", "+0000");
    memory[i] ? printf("%8d", memory[i]) : printf("%8s", "+0000");
  }
  fclose(dataFile);
}
