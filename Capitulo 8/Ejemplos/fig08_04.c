/* Figura 8.4: fig08_04.c
Uso de las funciones isspace, iscntrl, ispunct, isprint, isgraph */
#include <ctype.h>
#include <stdio.h>
int main() {
  printf(
      "%s\n%s%s%s\n%s%s%s\n%s%s\n\n", "De acuerdo con isspace:", "Nueva linea",
      isspace('\n') ? " es un " : " no es un ", "caracter espacio en blanco",
      "Tabulador horizontal", isspace('\t') ? " es un " : " no es un ",
      "caracter espacio en blanco", isspace('%') ? "% es un " : "% no es un ",
      "caracter espacio en blanco");

  printf("%s\n%s%s%s\n%s%s\n\n", "De acuerdo con iscntrl:", "Nueva linea",
         iscntrl('\n') ? " es un " : " no es un ", "caracter de control",
         iscntrl('$') ? "$ es un " : "$ no es un ", "control character");
  printf("%s\n%s%s\n%s%s\n%s%s\n\n",
         "De acuerdo con ispunct:", ispunct(';') ? "; es un " : "; no es un ",
         "caracter de puntuacion", ispunct('Y') ? "Y es un " : "Y no es un ",
         "caracter de puntuacion ", ispunct('#') ? "# es un " : "# no es un ",
         "caracter de puntuacion");
  printf("%s\n%s%s\n%s%s%s\n\n",
         "De acuerdo con isprint:", isprint('$') ? "$ es un " : "$ no es un ",
         "caracter de impresion", "Alerta",
         isprint('\a') ? " es un " : " no es un ", "caracter de impresion");
  printf("%s\n%s%s\n%s%s%s\n",
         "De acuerdo con isgraph:", isgraph('Q') ? "Q es un " : "Q no es un ",
         "caracter de impresion diferente a un espacio", "Espacio",
         isgraph(' ') ? " es un " : " no es un ",
         "caracter de impresion diferente a un espacio");
  return 0; /* indica terminación exitosa */
} /* fin de main */
