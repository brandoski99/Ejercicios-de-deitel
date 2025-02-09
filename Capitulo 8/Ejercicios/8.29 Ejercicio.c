#include <stdio.h>

int getchar(void);
char *gets(char *s);
int putchar(int c);
int puts(const char *s);
int main() {
  int letter = getchar();
  getchar(); // Vaciamos el buffer
  putchar(letter);

  char str[100];
  gets(str);
  puts(str);
  return 0;
}

int getchar(void) {
  char ch;
  scanf("%c", &ch);
  return ch;
}

char *gets(char *s) {
  char ch;
  scanf("%c", &ch);
  while (ch != '\n') {
    *s = ch;
    s++;
    scanf("%c", &ch);
  }
  *s = '\0';
  return s;
}

int putchar(int c) { return printf("%c", c); }

int puts(const char *s) { return printf("%s\n", s); }
