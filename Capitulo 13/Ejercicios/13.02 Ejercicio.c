/* Imprime los valores de las macros predefinidas */
#include <stdio.h>
int main() {
  printf("__LINE__ = %d\n", __LINE__);
  printf("__FILE__ = %s\n", __FILE__);
  printf("__DATE__ = %s\n", __DATE__);
  printf("__TIME__ = %s\n", __TIME__);
  return 0;
}
