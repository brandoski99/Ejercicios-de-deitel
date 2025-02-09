#include <stdio.h>
#include <string.h>

typedef struct tool {
  int number;
  char name[50];
  int amount;
  float price;
} Tool;

int menu();
void makeRegister(FILE *file);
void listTools(FILE *file);
void deleteRegister(FILE *file);
void updateRegister(FILE *file);

int main() {
  FILE *ptrTF = fopen("herram.dat", "rb+");
  Tool voidRegister = {0, "", 0, 0.0};
  int option = 0;
  /* crear los registros en blanco
      FILE *ptrTF = fopen("herram.dat", "w");
    for (int i = 1; i <= 100; i++) {
      fprintf(ptrTF, "%d %s %d %.2f\n", voidRegister.number, voidRegister.name,
              voidRegister.amount, voidRegister.price);
    } */
  while ((option = menu()) != 5) {
    switch (option) {
    case 1:
      listTools(ptrTF);
      break;
    case 2:
      deleteRegister(ptrTF);
      break;
    case 3:
      updateRegister(ptrTF);
      break;
    case 4:
      makeRegister(ptrTF);
      break;
    default:
      printf("\nOpcion invalida\n\n");
      break;
    }
  }
  return 0;
}

int menu() {
  int input = 0;
  printf("Elija alguna opcion:\n");
  printf("1-Listar herramientas\n2-Eliminar registro\n3-Actualizar "
         "informacion\n4-Crear registro\n5-Salir\n");
  scanf("%d", &input);
  return input;
}

void listTools(FILE *file) {
  Tool readTool = {0, "", 0, 0.0};
  fread(&readTool, sizeof(Tool), 1, file);
  printf("\nRegistro\tNombre\t\tCantidad\tPrecio c\\u\n");
  while (!feof(file)) {
    if (readTool.number != 0) {
      printf("%2d%24s%10d%19.2f\n\n", readTool.number, readTool.name,
             readTool.amount, readTool.price);
    }
    fread(&readTool, sizeof(Tool), 1, file);
  }
  putchar('\n');
  // Devolver apuntador de posicion al principio
  rewind(file);
}

void deleteRegister(FILE *file) {
  Tool voidRegister = {0, "", 0, 0.0};
  Tool readTool = {0, "", 0, 0.0};
  int registerNumber = 0;
  char option = ' ';
  printf("Introduzca el registro que desea eliminar (1-100)\n");
  scanf("%d", &registerNumber);
  fseek(file, (registerNumber - 1) * sizeof(Tool), SEEK_SET);
  fread(&readTool, sizeof(Tool), 1, file);
  if (readTool.number != registerNumber) {
    printf("\nEl registro %d no contiene datos\n\n", registerNumber);
  } else {
    printf("Desea eliminar el registro?\n");
    printf("\nRegistro\tNombre\t\tCantidad\tPrecio c\\u\n");
    printf("%2d%24s%10d%19.2f\n\n", readTool.number, readTool.name,
           readTool.amount, readTool.price);

    getchar(); // Vaciar buffer
    printf("Y//N:");
    option = getchar();
    if (option == 'Y' || option == 'y') {
      fseek(file, (registerNumber - 1) * sizeof(Tool), SEEK_SET);
      fwrite(&voidRegister, sizeof(Tool), 1, file); // Eliminamos el registro
      printf("Cuenta eliminada correctamente\n\n");
    }
  }
  // Devolver apuntador de posicion al principio
  rewind(file);
}

void updateRegister(FILE *file) {
  int updateMenu();
  Tool readTool = {0, "", 0, 0.0};
  int registerNumber = 0;
  int option = 0;
  printf("Elija el registro que desea actualizar(1-100)\n");
  scanf("%d", &registerNumber);
  fseek(file, (registerNumber - 1) * sizeof(Tool), SEEK_SET);
  fread(&readTool, sizeof(Tool), 1, file);
  if (readTool.number != registerNumber) {
    printf("\nEl registro %d no contiene datos\n\n", registerNumber);
  } else {
    printf("\nRegistro\tNombre\t\tCantidad\tPrecio c\\u\n");
    printf("%2d%24s%10d%19.2f\n\n", readTool.number, readTool.name,
           readTool.amount, readTool.price);

    while ((option = updateMenu()) != 4) {
      switch (option) {
      case 1: // Actualizar nombre

        getchar(); // Vaciar buffer
        printf("\nIntroduzca el nuevo nombre: ");
        fgets(readTool.name, sizeof(readTool.name), stdin);

        // Intercambiar '\n' con '\0'
        readTool.name[strlen(readTool.name) - 1] =
            readTool.name[strlen(readTool.name)];
        readTool.name[strlen(readTool.name)] = ' '; // Eliminar \0 sobrante
        putchar('\n');
        break;
      case 2:
        printf("\nIntroduzca la nueva cantidad: ");
        scanf("%d", &readTool.amount);
        putchar('\n');
        break;
      case 3:
        printf("\nIntroduzca el nuevo precio: ");
        scanf("%f", &readTool.price);
        putchar('\n');
        break;
      default:
        printf("\nOpcion invalida!\n");
        break;
      }
    }
    fseek(file, (registerNumber - 1) * sizeof(Tool), SEEK_SET);
    fwrite(&readTool, sizeof(Tool), 1, file);
  }

  // Devolver apuntador de posicion al principio
  rewind(file);
}
void makeRegister(FILE *file) {
  Tool input = {0, "", 0, 0.0};
  int registerNumber = 0;
  printf("Introduzca un numero de registro (1-100)\n");
  scanf("%d", &registerNumber);
  fseek(file, (registerNumber - 1) * sizeof(Tool), SEEK_SET);
  fread(&input, sizeof(Tool), 1, file);

  // Verificar que el registro este vacio
  if (input.number != 0) {
    printf("El registro %d ya contiene informacion\n", input.number);
  } else {
    printf("Introduzca el nombre de la herramienta\n");

    getchar(); // Vaciar buffer
    fgets(input.name, sizeof(input.name), stdin);

    // Intercambiar '\n' con '\0'
    input.name[strlen(input.name) - 1] = input.name[strlen(input.name)];
    input.name[strlen(input.name)] = ' '; // Eliminar \0 sobrante

    printf("Introduzca su cantidad y su precio "
           "unitario\n");
    scanf("%d%f", &input.amount, &input.price);

    input.number = registerNumber;
    // Escribir registro en la posicion indicada
    fseek(file, (registerNumber - 1) * sizeof(Tool), SEEK_SET);
    fwrite(&input, sizeof(Tool), 1, file);
  }
  // Devolver apuntador de posicion al principio
  rewind(file);
}

int updateMenu() {
  int input = 0;
  printf("1-Actualizar nombre de la herramienta\n2-Actualizar "
         "cantidad\n3-Actualizar costo\n4-Salir\n");
  scanf("%d", &input);
  return input;
}
