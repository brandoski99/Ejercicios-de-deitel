#include <stdio.h>
size_t strlen(const char *s);
int main() {
  /* inicializa los 3 apuntadores a char */
  const char *cadena1 = "abcdefghijklmnopqrstuvwxyz";
  const char *cadena2 = "cuatro";
  const char *cadena3 = "Mexico";
  printf("%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n", "La longitud de ",
         cadena1, " es ", (unsigned long)strlen(cadena1), "La longitud de ",
         cadena2, " es ", (unsigned long)strlen(cadena2), "La longitud de ",
         cadena3, " es ", (unsigned long)strlen(cadena3));
  return 0;
}

// Con arreglos y subindices
/*size_t strlen(const char *s) {
  size_t i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}*/

// Con aritmetica de punteros

size_t strlen(const char *s) {
  size_t len = 0;
  while (*s != '\0') {
    len++;
    s++;
  }
  return len;
}
