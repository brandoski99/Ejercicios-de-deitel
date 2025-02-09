#include <stdio.h>
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

int main() {
  char str1[100] = "holz";
  char str2[100] = "hola";

  if (strncmp(str1, str2, 4) == 0) {
    printf("Las cadenas son iguales");
  } else if (strncmp(str1, str2, 3) > 0) {
    printf("La cadena1 es mayor que la cadena2");
  } else {
    printf("La cadena1 es menor que la cadena2");
  }
  return 0;
}

/* strcmp */

// Con aritmetica de apuntadores

/*int strcmp(const char *s1, const char *s2) {
  while (*s1 && *s2) {
    if (*s1 != *s2) {
      return *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return *s1 - *s2;
} */

// Con arreglos y subindices

/*int strcmp(const char *s1, const char *s2) {
  int i = 0, j = 0;
  while (s1[i] && s2[j]) {
    if (s1[i] != s2[j]) {
      return s1[i] - s2[j];
    }
    i++;
    j++;
  }
  return s1[i] - s2[j];
} */

/* strncmp */

// Con arreglos y subindices

/*int strncmp(const char *s1, const char *s2, size_t n) {
  int i = 0, j = 0;
  while (n > 0) {
    if (s1[i] == s2[j]) {
        if(s1[i] == '\0'){
           return 0;
        }
    }else{
       return (unsigned char)s1[i] - (unsigned char)s2[j];
    }
    i++;
    j++;
    n--;
  }
  return  0;
}*/

// Con aritmetica de apuntadores

/*int strncmp(const char *s1, const char *s2, size_t n) {

  while (n > 0) {
    if (*s1 == *s2) {
      // Si los caracteres son iguales y  el caracter de s1 es '\0' las cadenas
      // son iguales
      if (*s1 == '\0') {
        return 0;
      }
    } else {
      return (unsigned char)*s1 - (unsigned char)*s2;
    }
    s1++;
    s2++;
    n--;
  }
  return 0;
} */
