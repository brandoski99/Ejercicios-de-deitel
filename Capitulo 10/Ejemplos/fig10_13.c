/* Figura 10.13: fig10_13.c
Uso de los operadores de desplazamiento de bits */
#include <stdio.h>
void despliegaBits(unsigned valor); /* prototipo */
int main() {
  unsigned numero1 = 960;
  /* inicializa numero1 */ /* demuestra el operador de desplazamiento a la
                              izquierda a nivel de bits */
  printf("\nEl resultado del desplazamiento a la izquierda de\n");
  despliegaBits(numero1);
  printf("8 posiciones de bit con el uso del ");
  printf("operador de desplazamiento a la izquierda << es\n");
  despliegaBits(numero1 << 8);
  /* demuestra el operador de desplazamiento a la derecha a nivel de bits */
  printf("\nEl resultado del desplazamiento a la derecha de\n");
  despliegaBits(numero1);
  printf("8 posiciones de bit con el uso del ");
  printf("operador de desplazamiento a la derecha >> es\n \n");
  despliegaBits(numero1 >> 8);
  return 0; /* indica terminación exitosa */
} /* fin de main */
/* despliega los bits de un valor entero sin signo */
void despliegaBits(unsigned valor) {
  unsigned c; /* contador */
  /* declara despliegaMascara y desplaza a la izquierda 31 bits */
  unsigned despliegaMascara = 1 << 31;
  printf("%7u = ", valor);
  /* ciclo a través de los bits */
  for (c = 1; c <= 32; c++) {
    putchar(valor & despliegaMascara ? '1' : '0');
    valor <<= 1;      /* despliega el valor 1 posición a la izquierda */
    if (c % 8 == 0) { /* muestra un espacio después de 8 bits */
      putchar(' ');
    } /* fin de if */
  } /* fin de for */
  putchar('\n');
} /* fin de la función despliegaBits */
