#include <stdio.h>
#include <stdlib.h>
int main()
{
    int binario,contador = 1,decimal = 0, res = 0;
    scanf("%d", &binario);
    while(binario > 0){
        res = binario % 10 * contador;
        binario = binario / 10;
        contador += contador;
        decimal += res;
    }
    printf("Valor decimal: %d\n", decimal);
    system("pause");
    return 0;
}
