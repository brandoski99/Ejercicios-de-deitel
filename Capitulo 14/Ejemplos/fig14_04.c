/* Figura 14.4: fig14_04.c
Uso de las funciones exit y atexit */
#include <stdio.h>
#include <stdlib.h>
void imprime(void); /* prototipo */
int main() {
  int respuesta;   /* elección de menú del usuario */
  atexit(imprime); /* registra la nueva función imprime */
  printf("Introduzca 1 para terminar el programa con la funcion exit"
         "\nIntroduzca 2 para terminar el programa de manera normal\n");
  scanf("%d", &respuesta);
  /* llama a exit si la respuesta es 1 */
  if (respuesta == 1) {
    printf("\nTermina el programa con la funcion exit\n");
    exit(EXIT_SUCCESS);

  } /* fin de if */
  printf("\nTermina el programa al encontrar el final de main\n");
  return 0; /* indica terminación exitosa */
} /* fin de main */
/* despliega un mensaje antes de terminar */
void imprime(void) {
  printf("Ejecuta la funcion imprime al "
         "finalizar el programa\n");
} /* fin de la función imprime */
