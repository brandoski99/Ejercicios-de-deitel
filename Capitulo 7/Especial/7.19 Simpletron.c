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

int main() {
  int memory[100];
  int accumulator;            // Representa el registro del acumulador +0000
  int instructionCounter = 0; // registra la instruccion que se ejecuta 00
  int instructionRegister;    // registra las siguientes instrucciones +0000
  int operationCode;          // Indica la operacion que se va ejecutar 00
  int operand = 0; // Indica la ubicacion en memoria de la operacion actual 00

  printf("*** Bienvenido a Simpletron!                       ***\n*** Por "
         "favor, introduzca a su programa una instruccion ***\n*** a la vez (o "
         "palabra de datos).         ***\n*** Yo escribire el numero de "
         "ubicacion y un      ***\n*** signo de interrogacion (?). Usted "
         "escriba ***\n*** la palabra para dicha ubicacion. Escriba el   "
         "****** centinela -99999 para terminar la    ***\n*** introduccion de "
         "datos a su programa.                  ***\n");

  for (int i = 0; i < 100; i++) {
    printf("%d ? ", i);
    scanf("%d", &memory[i]);
    if (memory[i] == -9999) {
      break;
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
    switch (operand) {
    case READ:
      scanf("%d", &memory[operand]);
      break;
    case LOAD:
      accumulator = memory[operand];
      break;
    case ADD:
      accumulator += memory[operand];
      break;
    case BRANCH:
      instructionCounter = operand;
      break;
    case BRANCHZERO:
      if (accumulator == 0) {
        instructionCounter = operand;
      }
      break;
    case HALT:
      printf("\n*** Finaliza ejecución de Simpletron ***\n");
      instructionCounter = 100;
      break;
    }
    instructionCounter++;
  }

  return 0;
}
