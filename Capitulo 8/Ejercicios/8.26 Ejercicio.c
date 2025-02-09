#include <stdio.h>

int isdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isxdigit(int c);
int islower(int c);
int isupper(int c);
int tolower(int c);
int toupper(int c);
int isspace(int c);
int iscntrl(int c);
int ispunct(int c);
int isprint(int c);
int isgraph(int c);

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

  printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
         "De acuerdo con islower:", islower('p') ? "p es una " : "p no es una ",
         "letra minuscula", islower('P') ? "P es una " : "P no es una ",
         "letra minuscula", islower('5') ? "5 es una " : "5 no es una ",
         "letra minuscula", islower('!') ? "! es una " : "! no es una ",
         "letra minuscula");
  printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
         "De acuerdo con isupper:", isupper('D') ? "D es una " : "D no es una ",
         "letra mayuscula", isupper('d') ? "d es una " : "d no es una ",
         "letra mayuscula", isupper('8') ? "8 es una " : "8 no es una ",
         "letra mayuscula", isupper('$') ? "$ es una " : "$ no es una ",
         "letra mayuscula");
  printf("%s%c\n%s%c\n%s%c\n%s%c\n", "u convertida a mayuscula es ",
         toupper('u'), "7 convertida a mayuscula es ", toupper('7'),
         "$ convertida a mayuscula es ", toupper('$'),
         "L convertida a minuscula es ", tolower('L'));

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
  return 0;
}

int isdigit(int c) {
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}

int isalpha(int c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return 1;
  }
  return 0;
}

int isalnum(int c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9')) {
    return 1;
  }
  return 0;
}

int isxdigit(int c) {
  if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
      (c >= 'A' && c <= 'F')) {
    return 1;
  }
  return 0;
}

int islower(int c) {
  if (c >= 'a' && c <= 'z') {
    return 1;
  }
  return 0;
}

int isupper(int c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  }
  return 0;
}

int tolower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 32;
  }
  return c;
}

int toupper(int c) {
  if (c >= 'a' && c <= 'z') {
    return c - 32;
  }
  return c;
}

int isspace(int c) {
  if (c == '\n' || c == ' ' || c == '\f' || c == '\r' || c == '\t' ||
      c == '\v') {
    return 1;
  }
  return 0;
}

int iscntrl(int c) {
  if (c >= 0 && c <= 32 || c == 127) {
    return 1;
  }
  return 0;
}

int ispunct(int c) {
  if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') && (c == ' '))) {
    return 1;
  }
  return 0;
}

int isprint(int c) {
  if (!(c >= 0 && c <= 32)) {
    return 1;
  }
  return 0;
}

int isgraph(int c) {
  if (!(c >= 0 && c <= 32) && c != ' ') {
    return 1;
  }
  return 0;
}
