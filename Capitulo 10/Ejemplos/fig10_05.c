/* Figura 10.5: fig10_05.c
Un ejemplo de unión */
#include <stdio.h>
/* definición de la unión numero */
union numero {
  int x;
  double y;
}; /* fin de la unión numero */
int main() {
  union numero valor; /* define la variable de unión */
  valor.x = 100;      /* coloca un entero dentro de la unión */
  printf("%s\n%s\n%s%d\n%s%f\n\n", "Coloca un valor en el miembro entero",
         "e imprime ambos miembros.", "int: ", valor.x, "double:\n", valor.y);
  valor.y = 100.0; /* coloca un double dentro de la misma unión */
  printf("%s\n%s\n%s%d\n%s%f\n", "Coloca un valor en el miembro flotante",
         "e imprime ambos miembros.", "int: ", valor.x, "double:\n", valor.y);
  return 0; /* indica terminación exitosa */
} /* fin de main */
