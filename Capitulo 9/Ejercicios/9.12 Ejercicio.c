#include <stdio.h>
#include <string.h>
int main() {
  char str[100];
  int len = 0;
  scanf("%[^\n]99s", str);
  len = strlen(str);
  printf("\n%*s", len * 2, str);
  return 0;
}
