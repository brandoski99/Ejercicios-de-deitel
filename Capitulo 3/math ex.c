#include <stdio.h>

double calcpow(int x,double expo){
    double res = 1.0;
    while (expo != 0) {
        res *= x;
        --expo;
    }
    return res;
}

int main()
{
    double result = 0;
    int i=0,x,n,j;
    double fac = 1;
    x = 1;
    scanf("%d", &n);

    while(i <= n){
        j = 1;
        while(j <= i){
            fac *= j;
            j++;

        }
        result += calcpow(x,i)/fac;
        i++;
    }

    printf("%lf", result);
    return 0;
}
