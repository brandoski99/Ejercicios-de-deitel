#include <stdio.h>
#include <string.h>
void inverseToken(char *word);

int main() {
  char word[100];
  fgets(word, sizeof(word), stdin);
  inverseToken(word);
  return 0;
}

void inverseToken(char *word) {
  char *ptrWord = strtok(word, " \n");
  if (ptrWord != NULL) {
    char remainingWords[100];
    strcpy(remainingWords, word + (ptrWord - word) + strlen(ptrWord) + 1);
    inverseToken(remainingWords);
    printf("%s\n", ptrWord);
  }
}
