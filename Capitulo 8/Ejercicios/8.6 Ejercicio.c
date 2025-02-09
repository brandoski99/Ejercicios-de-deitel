#include <ctype.h>
#include <stdio.h>

int main() {
  char s[100];
  /* La funcion gets esta en desuso desde C99, debido al riesgo de un
   * bufferoverflow
   */
  fgets(s, sizeof(s), stdin);
  printf("\nEn Mayusculas: ");
  for (int i = 0; s[i] != '\0'; i++) {
    printf("%c", toupper(s[i]));
  }
  putchar('\n');
  printf("\nEn Minusculas: ");
  for (int i = 0; s[i] != '\0'; i++) {
    printf("%c", tolower(s[i]));
  }
  return 0;
}
