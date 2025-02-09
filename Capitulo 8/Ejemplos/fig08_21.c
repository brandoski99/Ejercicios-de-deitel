/* Figura 8.21: fig08_21.c
Uso de strcmp y strncmp */

#include <stdio.h>
#include <string.h>
int main() {
  const char *s1 = "Feliz anio nuevo"; /* inicializa el apuntador a char */
  const char *s2 = "Feliz anio nuevo"; /* inicializa el apuntador a char */
  const char *s3 = "Felices fiestas";  /* inicializa el apuntador a char */

  printf("%s%s\n%s%s\n%s%s\n\n%s%2d\n%s%2d\n%s%2d\n\n", "s1 = ", s1,
         "s2 = ", s2, "s3 = ", s3, "strcmp(s1, s2) = ", strcmp(s1, s2),
         "strcmp(s1, s3) = ", strcmp(s1, s3),
         "strcmp(s3, s1) = ", strcmp(s3, s1));
  printf("%s%2d\n%s%2d\n%s%2d\n", "strncmp(s1, s3, 6) = ", strncmp(s1, s3, 6),
         "strncmp(s1, s3, 7) = ", strncmp(s1, s3, 7),
         "strncmp(s3, s1, 7) = ", strncmp(s3, s1, 7));
  return 0; /* indica terminación exitosa */
} /* fin de main */
