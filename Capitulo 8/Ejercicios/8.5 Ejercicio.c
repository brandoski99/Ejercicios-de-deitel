#include <ctype.h>
#include <stdio.h>

int main() {
  char character = getchar();
  printf("\n%c %2s %2s", character, isdigit(character) ? "Es un" : "No es un",
         "Numero\n");
  printf("%c %2s %2s", character, isalpha(character) ? "Es una" : "No es una",
         "Letra\n");
  printf("%c %2s %2s", character, isalnum(character) ? "Es un" : "No es un",
         "Numero o Letra\n");

  printf("%c %2s %2s", character, isxdigit(character) ? "Es un" : "No es un",
         "Numero Hexadecimal\n");

  printf("%c %2s %2s", character, islower(character) ? "Es una" : "No es una",
         "Minuscula\n");
  printf("%c %2s %2s", character, isupper(character) ? "Es una" : "No es una",
         "Mayuscula\n");
  printf("%c %2s %2s", character, isspace(character) ? "Es un" : "No es un",
         "Espacio en blanco\n");
  printf("%c %2s %2s", character, iscntrl(character) ? "Es un" : "No es un",
         "Caracter de Control\n");
  printf("%c %2s %2s", character, ispunct(character) ? "Es un" : "No es un",
         "Signo\n");
  printf("%c %2s %2s", character, isprint(character) ? "Es un" : "No es un",
         "Caracter de impresion\n");
  printf("%c %2s %2s", character, isgraph(character) ? "Es un" : "No es un",
         "Caracter de impresion(Sin espacios)\n");
  return 0;
}
