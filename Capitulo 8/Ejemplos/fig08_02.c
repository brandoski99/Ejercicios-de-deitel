/* Figura 8.2: fig08_02.c
Uso de las funciones isdigit, isalpha, isalnum, e isxdigit */
#include <ctype.h>
#include <stdio.h>
int main() {
  printf("%s\n%s%s\n%s%s\n\n",
         "De acuerdo con isdigit: ", isdigit('8') ? "8 es un " : "8 no es un ",
         "digito", isdigit('#') ? "# es un " : "# no es un ", "digito");
  printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
         "De acuerdo con isalpha:", isalpha('A') ? "A es una " : "A no es una ",
         "letra", isalpha('b') ? "b es una " : "b no es una ", "letra",
         isalpha('&') ? "& es una " : "& no es una ", "letra",
         isalpha('4') ? "4 es una " : "4 no es una ", "letra");
  printf("%s\n%s%s\n%s%s\n%s%s\n\n",
         "De acuerdo con isalnum:", isalnum('A') ? "A es un " : "A no es un ",
         "digito o una letra", isalnum('8') ? "8 es un " : "8 no es un ",
         "digito o una letra", isalnum('#') ? "# es un " : "# no es un ",
         "digito o una letra");
  printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n",
         "De acuerdo con isxdigit:", isxdigit('F') ? "F es un " : "F no es un ",
         "digito hexadecimal", isxdigit('J') ? "J es un " : "J no es un ",
         "digito hexadecimal", isxdigit('7') ? "7 es un " : "7 no es un ",
         "digito hexadecimal", isxdigit('$') ? "$ es un " : "$ no es un ",
         "digito hexadecimal", isxdigit('f') ? "f es un " : "f no es un ",
         "digito hexadecimal");
  return 0; /* indica terminación exitosa */
} /* fin de main */
