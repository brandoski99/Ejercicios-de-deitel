/* Figura 9.9: fig09_09.c */
/* Uso de la precisión durante la impresión de enteros,
números de punto flotante, y cadenas */
#include <stdio.h>
int main() {
  int i = 873;
  /* inicializa el entero int i */
  double f = 123.94536;
  /* inicializa el double f */
  char s[] = "Feliz Cumpleanios"; /* inicializa el arreglo char s */
  printf("Uso de la precision en enteros\n");
  printf("\t%.4d\n\t%.9d\n\n", i, i);
  printf("Uso de la precision en numeros de punto flotante\n");
  printf("\t%.3f\n\t%.3e\n\t%.3g\n\n", f, f, f);
  printf("Uso de la precision en cadenas\n");
  printf("\t%.11s\n", s);
  return 0; /* indica terminacion exitosa */
} /* fin de main */
