#include <stdio.h>

int main(){
    float pi = 4.0;
    int count = 3;
    for(int x = 1; count < 1e6; count += 2,x++){
        if(x % 2 != 0){
           pi -= 4.0 / count;
        }
        else{
            pi += 4.0 / count;
        }
    }
    printf("value of pi = %.4lf\n", pi);
    return 0;
 }
