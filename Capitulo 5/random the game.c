#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum RespuestasJuego {CORRECTO, ABAJO, ARRIBA};
void play(void);

int num;
int player;

enum RespuestasJuego juego;

int main(){
    srand(time(NULL));
    num = 1 + rand() % 1000;
    printf("Tengo un numero entre 1 y 1000\n");
    printf("Puedes adivinar cual es?\n");
    printf("Porfavor escribe tu primera respuesta\n");
    scanf("%d", &player);
    play();
    while(juego != CORRECTO)
        play();
 }

void play(void){
    if(player > num){
        printf("Muy arriba, intenta denuevo\n");
        juego = ARRIBA;
        scanf("%d", &player);
    }
    else if(player < num){
        printf("Muy abajo, intenta denuevo\n");
        juego = ABAJO;
        scanf("%d", &player);
    }
    else{
       juego = CORRECTO;
       printf("!Excelente! !Adivinaste el numero!\n");
    }
 }
