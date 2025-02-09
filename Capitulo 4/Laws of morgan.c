#include <stdio.h>

int main(){
    /* a) !(x < 5) && !(y >= 7)
       b) !(a == b) || !(g != 5)
       c) !(x <= 8) && !(y > 4)
       d) !( (i > 4) || (j <= 6) )

       Respuestas:

       a) !( (x < 5) || (y >= 7) )
       b) !( (a == b) && ( g != 5) )
       c) !((x <= 8)  ||  (y > 4))
       d) !( (i > 4) && (j <= 6) )
    */
    int x = 5,  y = 6;
    int a = 2, b = 2, g = 4;
    int i = 5, j = 4;
    printf("%d",   !( (i > 4) || (j <= 6) )== !((i > 4) && (j <= 6)) ); // copie y pegue los ejemplos y respuestas en el printf y compruebe los resultados
    return 0;
 }
