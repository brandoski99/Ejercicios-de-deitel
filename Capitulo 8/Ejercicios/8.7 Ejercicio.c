#include <stdio.h>
#include <stdlib.h>

int main() {
  char string1[100];
  char string2[100];
  char string3[100];
  char string4[100];
  scanf("%99s%99s%99s%99s", string1, string2, string3, string4);
  printf("String1: %s\nString2: %s\nString3: %s\nString4: %s\n", string1,
         string2, string3, string4);
  printf("Total: %d",
         atoi(string1) + atoi(string2) + atoi(string3) + atoi(string4));
  return 0;
}
