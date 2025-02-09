/*
  6.23 (Gráficos de tortuga.) El lenguaje Logo, que es especialmente popular entre los usuarios de computadoras personales, hizo famoso el concepto de los gráficos de tortuga. Imagine una tortuga mecánica que camina alrededor de
una habitación bajo el control de un programa en C. La tortuga mantiene una pluma en una de dos posiciones: arriba
o abajo. Mientras la pluma está abajo, la tortuga traza las formas mientras se mueve; mientras la pluma está arriba, la tortuga se mueve libremente sin dibujar. En este problema, usted simulará la operación de la tortuga, así cómo
el tablero computarizado.
Utilice un arreglo de 50 por 50 llamado piso, inicializado en ceros. Lea los comandos desde un arreglo que los
contenga. Mantenga la pista de la posición actual de la tortuga en todo momento, y si la pluma está arriba o abajo.
Suponga que la tortuga comienza siempre en la posición 0,0 del piso con la pluma arriba. El conjunto de los comandos de la tortuga que usted debe procesar aparece en la figura 6.24. Suponga que la tortuga se encuentra en algún
lugar cerca del centro del piso. El siguiente “programa” debe dibujar y desplegar un cuadrado de 12 por 12:
2
5, 12
3
5, 12
3
5, 12
3
5, 12
1
6
9
Mientras la tortuga se mueva con la pluma abajo, establezca en 1s los elementos apropiados del arreglo piso.
Cuando se introduzca el comando 6 (imprimir), donde quiera que se encuentre un 1 dentro del arreglo, despliegue
un asterisco o algún otro carácter que elija. Donde quiera que haya un cero, despliegue un blanco. Escriba un programa para implementar las capacidades de los gráficos de tortuga que explicamos aquí. Escriba varios programas
de gráficos de tortuga para dibujar formas interesantes. Agregue otros comandos para incrementar el poder de su
lenguaje de gráficos de tortuga.

  1 Pluma arriba
  2 Pluma abajo
  3 Vuelta a la derecha
  4 vuelta a la izquierda
  5, n  Movimiento hacia adelante n posiciones (n puede ser cualquier numero)
  6 Despliega el arreglo de 50 por 50
  9 Fin de datos (centinela)
*/
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 100 // el numero maximo de comandos

void getCommands(int commands[][2]);
int turnRight(int d);
int turnLeft(int d);
void movePen(int down, int a[][50], int dir, int dist);
void printArray(int a[][50]);

int main(){
    int floor[50][50] = {0};
    int penDown = FALSE;
    int command;
    int direction = 0;
    int commandArray[MAX][2] = {0};
    int distance;
    int count = 0;

    getCommands(commandArray);
    command = commandArray[count][0];

    while(command != 9){
        switch(command){
    case 1:
         penDown = FALSE;
         break;
    case 2:
        penDown = TRUE;
        break;
    case 3:
        direction = turnRight(direction);
        break;
    case 4:
        direction = turnLeft(direction);
        break;
    case 5:
        distance = commandArray[count][1];
        movePen(penDown, floor, direction, distance);
        break;
    case 6:
        printf("\nThe drawing is:\n\n");
        printArray(floor);
        break;
        }
        command = commandArray[++count][0];
    }
    return 0;
}

void getCommands(int commands[][2]){
     int i;
     int tempCommand;

     printf("Enter command ( 9 to end input ): ");
     scanf("%d", &tempCommand);
     //Recibe comandos hasta recibir un 9 o llegar a 100 comandos
     for(i = 0; tempCommand != 9 && i < MAX; i++){
        commands[i][0] = tempCommand;
        //Ignorar coma despues de recibir un 5
        if(tempCommand == 5){
            scanf(",%d", &commands[i][1]);
        }
        printf("Enter command ( 9 to end input ): ");
        scanf("%d", &tempCommand);
     }
     commands[i][0] = 9;
}

int turnRight(int d){
    return ++d > 3 ? 0 : d;
 }

 int turnLeft(int d){
    return --d < 0 ? 3 : d;
 }

 void movePen(int down, int a[][50], int dir, int dist){
      int i;
      int j;
      static int xPos = 0;
      static int yPos = 0;

      switch(dir){
    case 0: //mover a la derecha (predeterminado)
        for(j = 1; j <= dist && yPos+j < 50; j++){
            if(down){
                a[xPos][yPos+j] = 1;
            }
        }
        yPos += j - 1;
        break;
    case 1: //mover abajo
        for(i = 1; i <= dist && xPos+i < 50; i++){
            if(down){
                a[xPos+i][yPos] = 1;
            }
        }
        xPos += i - 1;
        break;
    case 2: // mover a la izquierda
        for(j = 1; j <= dist && yPos-j >= 0; j++){
            if(down){
                a[xPos][yPos-j] = 1;
            }
        }
        yPos -= j - 1;
        break;
     case 3: //mover arriba
        for(i = 1; i <= dist && xPos-i >= 0; i++){
            if(down){
                a[xPos-i][yPos] = 1;
            }
        }
        xPos -= i - 1;
        break;

      }


    }

void printArray(int a[][50]){
     int i;
     int j;

     for(i = 0; i < 50; i++){
        for(j = 0; j < 50; j++){
            putchar(a[i][j] ? '*' : ' ' );
        }
        putchar('\n');
     }
 }
