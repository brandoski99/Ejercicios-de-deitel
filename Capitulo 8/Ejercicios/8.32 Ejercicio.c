#include <stdio.h>

void *memcpy(void *s1, const void *s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);
int memmcmp(const void *s1, const void *s2, size_t n);
void *memchr(const void *s, int c, size_t n);
void *memset(void *s, int c, size_t n);

int main() {
  char cadena1[15] = "BBBBBBBBBBBBBB"; /* inicializa cadena1 */
  printf("cadena1 = %s\n", cadena1);
  printf("cadena1 despues de memset = %s\n", memset(cadena1, 'b', 7));
  ;
  return 0;
}

void *memcpy(void *s1, const void *s2, size_t n) {
  // Se convierte los punteros voids a bytes para manejarlos facilmene
  char *dest = (char *)s1;
  char *src = (char *)s2;
  while (n > 0) {
    *dest = *src;
    dest++;
    src++;
    n--;
  }
  return dest;
}

/*void *memmove(void *s1, const void *s2, size_t n) {
  char *dest = (char *)s1;
  char *src = (char *)s2;
  if (dest < src) {
    // Copia hacia adelante
    while (n--) {
      *dest++ = *src++;
    }
  } else {
    // Copia hacia atras
    dest += n;
    src += n;
    while (n--) {
      *(--dest) = *(--src);
    }
  }
  return dest;
}*/

int memmcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *Argument1 = (const unsigned char *)s1;
  const unsigned char *Argument2 = (const unsigned char *)s2;

  while (n > 0) {
    if (*Argument1 != *Argument2) {
      return (*Argument1 < *Argument2) ? -1 : 1;
    }
    Argument1++;
    Argument2++;
    n--;
  }
  return 0;
}

void *memchr(const void *s, int c, size_t n) {
  char *src = (char *)s;
  while (n > 0) {
    if (*src == c) {
      return (void *)src;
    }
    src++;
    n--;
  }
  return NULL;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *src = (unsigned char *)s;
  while (n > 0) {
    *src = (unsigned char)c;
    src++;
    n--;
  }
  return (void *)s;
}
