#include <stdio.h>
void reverseString(char arr[]);
int main(){
    char example[] = "Hola Mundo";
    reverseString(example);
    return 0;
 }

void reverseString(char arr[]){
   if(arr[0] == '\0'){
    return;
   }
   reverseString(&arr[1]);
   printf("%c ", arr[0]);
}
