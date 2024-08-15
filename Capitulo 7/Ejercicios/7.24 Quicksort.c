#include <stdio.h>

void Quicksort(int arr[], int start, int end);
int main() {
  int example[10] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
  int length = (sizeof example / sizeof example[0]);

  Quicksort(example, 0, length);
  return 0;
}

void Quicksort(int arr[], int start, int end) {
  // void Partition(int arr[], int element);
  void swap(int arr[], int arr2[]);
  int less = 0;
  int greater = 0;
  int temp = 0;
  /* Se determina la longitud de los subarreglos */
  for (int i = start; i < end; i++) {
    if (arr[start] > arr[i]) {
      less++;
    }
  }
  for (int i = end; i >= start; i--) {
    if (arr[start] < arr[i]) {
      greater++;
    }
  }
  int lessArray[less];
  int greaterArray[greater];

  printf("less: %d\ngreater: %d", less, greater);
}

void swap(int *arr, int *arr2) {
  int temp = *arr;
  *arr = *arr2;
  *arr2 = temp;
}
/*void Partition(int arr[],int element){

}*/
