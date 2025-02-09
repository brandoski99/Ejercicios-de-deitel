/* Figura 14.2: fig14_02.c
Uso de listas de argumentos de longitud variable*/
#include <stdarg.h>
#include <stdio.h>

double promedio(int i, ...); /* prototipo */
int main() {
  double w = 37.5;
  double x = 22.5;
  double y = 1.7;
  double z = 10.2;
  printf("%s%.1f\n%s%.1f\n%s%.1f\n%s%.1f\n\n", "w = ", w, "x = ", x, "y = ", y,
         "z = ", z);
  printf("%s%.3f\n%s%.3f\n%s%.3f\n", "El promedio de w y x es ",
         promedio(2, w, x), "El promedio de w, x, y y es ",
         promedio(3, w, x, y), "El promedio de w, x, y, y z es ",
         promedio(4, w, x, y, z));
  return 0; /* indica terminación exitosa */
} /* fin de main */
/* calcula el promedio */
double promedio(int i, ...) {
  double total = 0; /* inicializa el total */
  int j;            /* contador para seleccionar argumentos */
  va_list ap; /* almacena la información necesaria para va_start y va_end */
  va_start(ap, i); /* inicializa el objeto va_list */
  /* procesa la lista de argumentos de longitud variable */
  for (j = 1; j <= i; j++) {
    total += va_arg(ap, double);
  } /* fin de for */
  va_end(ap);       /* limpia la lista de argumentos de longitud variable */
  return total / i; /* calcula el promedio */
} /* fin de la función promedio */
