#include <stdio.h>
// char *strchr(const char *s, int c);
//  size_t strcspn(const char *s1, const char *s2);
//  size_t strspn(const char *s1, const char *s2);
//  char *strpbrk(const char *s1, const char *s2);
//  char *strrchr(const char *s, int c);
//  char *strstr(const char *s1, const char *s2);
// char *strtok(char *s1, const char *s2);
int main() {
  char str[] = "Hello, world! This is a test.";
  return 0;
}

/*char *strchr(const char *s, int c) {
  while (*s != '\0') {
    if (*s == c) {
      return (char *)s;
    }
    s++;
  }
  return NULL;
}*/

/*size_t strcspn(const char *s1, const char *s2) {
  size_t count = 0;
  while (s1[count] != '\0') {
    const char *temp = s2;
    while (*temp != '\0') {
      if (s1[count] == *temp) {
        return count;
      }
      temp++;
    }
    count++;
  }
  return count;
}*/

/* size_t strspn(const char *s1, const char *s2) {
  size_t count = 0;
  while (s1[count] != '\0') {
    const char *temp = s2;
    while (*temp != '\0') {
      if (s1[count] == *temp) {
        break;
      }
      temp++;
    }
    if (*temp == '\0') {
      break;
    }
    count++;
  }
  return count;
}*/

/* char *strpbrk(const char *s1, const char *s2) {
  while (*s1 != '\0') {
    const char *temp = s2;
    while (*temp != '\0') {
      if (*s1 == *temp) {
        return (char *)s1;
      }
      temp++;
    }
    s1++;
  }
  return NULL;
} */

/* char *strrchr(const char *s, int c) {
  char *lastOcurrence = NULL;
  while (*s != '\0') {
    if (*s == c) {
      lastOcurrence = (char *)s;
    }
    s++;
  }
  return lastOcurrence;
}*/

// ChatGPT porque no sabia como hacerlo
/* char *strstr(const char *s1, const char *s2) {
  if (*s2 == '\0') {
    return (char *)s1; // If s2 is an empty string, return s1
  }

  while (*s1 != '\0') {
    const char *p1 = s1;
    const char *p2 = s2;

    // Check for the substring
    while (*p2 != '\0' && *p1 == *p2) {
      p1++;
      p2++;
    }

    // If we reached the end of s2, we found a match
    if (*p2 == '\0') {
      return (char *)s1; // Return the pointer to the start of the match
    }

    s1++; // Move to the next character in s1
  }

  return NULL;
}*/

/*char *strtok(char *s1, const char *s2) {
  static char *lastStr = NULL;
  char *currentToken;
  if (s1 == NULL) {
    s1 = lastStr;
  }

  while (*s1 && strchr(s2, *s1)) {
    s1++;
  }

  if (*s1 == '\0') {
    return NULL;
  }
  currentToken = s1;

  while (*s1 && !strchr(s2, *s1)) {
    s1++;
  }

  if (*s1) {
    *s1 = '\0';
    lastStr = s1 + 1;
  } else {
    lastStr = NULL;
  }

  return currentToken;
}*/
