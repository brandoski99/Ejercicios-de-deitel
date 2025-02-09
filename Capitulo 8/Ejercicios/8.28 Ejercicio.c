#include <stdio.h>
// char *strcpy(char *s1, const char *s2);
// char *strncpy(char *s1, const char *s2, size_t n);
// char *strcat(char *s1, const char *s2);
// char *strncat(char *s1, const char *s2, size_t n);
int main() {
  char str1[100] = "que";
  char str2[] = "lo que sea";
  printf("%s", str1);
}

/* strcpy */

// Con arreglos y subindices

/*char *strcpy(char *s1, const char *s2) {
  char *originalS1 = s1;
  int i = 0, j = 0;
  while (s2[i] != '\0') {
    s1[j] = s2[i];
    i++;
    j++;
  }
  s1[j] = '\0';
  return originalS1;
}*/

// Con aritmetica de apuntadores

/*char *strcpy(char *s1, const char *s2) {
  char *originalS1 = s1;
  while (*s2 != '\0') {
    *s1 = *s2;
    s1++;
    s2++;
  }
  *s1 = '\0';
  return originalS1;
}*/

/* strncpy */

// Con arreglos y subindices

/* char *strncpy(char *s1, const char *s2, size_t n) {
  char *originalS1 = s1;
  int i = 0, j = 0;
  while (s2[i] != '\0' && n > 0) {
    s1[j] = s2[i];
    i++;
    j++;
    n--;
  }
  if (n > 0) {
    s1[j] = '\0';
  }
  s1[j] = '\0';
  return originalS1;
} */

// Con aritmetica de apuntadores

/*char *strncpy(char *s1, const char *s2, size_t n) {
  char *originalS1 = s1;
  while (*s2 != '\0' && n > 0) {
    *s1 = *s2;
    s1++;
    s2++;
    n--;
  }
  if (n > 0) {
    *s1 = '\0';
  }
  return originalS1;
}*/

/* strcat */

// Con arreglos y subindices

/*char *strcat(char *s1, const char *s2) {
  char *originalS1 = s1;
  int i = 0, j = 0;
  while (s1[j] != '\0') {
    j++;
  }
  while (s2[i] != '\0') {
    s1[j] = s2[i];
    i++;
    j++;
  }
  s1[j] = '\0';
  return originalS1;
}*/

// Con aritmetica  de apuntadores

/*char *strcat(char *s1, const char *s2) {
  char *originalS1 = s1;
  while (*s1 != '\0') {
    s1++;
  }

  while (*s2 != '\0') {
    *s1 = *s2;
    s1++;
    s2++;
  }
  *s1 = '\0';
  return originalS1;
} */

/* strncat */

// Con arreglos y subindices

/*char *strncat(char *s1, const char *s2, size_t n) {
  char *originalS1 = s1;
  int i = 0, j = 0;
  while (s1[j] != '\0') {
    j++;
  }
  while (s2[i] != '\0' && n > 0) {
    s1[j] = s2[i];
    i++;
    j++;
    n--;
  }
  if (n > 0) {
    s1[j] = '\0';
  }
  return originalS1;
} */

// Con aritmetica de apuntadores

/* char *strncat(char *s1, const char *s2, size_t n) {
  char *originalS1 = s1;

  while (*s1 != '\0') {
    s1++;
  }

  while (*s2 != '\0' && n > 0) {
    *s1 = *s2;
    s1++;
    s2++;
    n--;
  }

  if (n > 0) {
    *s1 = '\0';
  }

  return originalS1;
} */
