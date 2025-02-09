#include <stdio.h>

void ordenamientoCubeta(int arr[], int n) {
    int cubetas[10][n];

    // Inicializar cubetas
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            cubetas[i][j] = -1;
        }
    }

    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    int exp = 1;
    while (max_num / exp > 0) {
        for (int i = 0; i < n; i++) {
            int cubeta_index = (arr[i] / exp) % 10;
            int j = 0;
            while (cubetas[cubeta_index][j] != -1) {
                j++;
            }
            cubetas[cubeta_index][j] = arr[i];
        }

        int k = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < n; j++) {
                if (cubetas[i][j] != -1) {
                    arr[k] = cubetas[i][j];
                    cubetas[i][j] = -1;
                    k++;
                }
            }
        }

        exp *= 10;
    }
}

int main() {
    int arr[] = {97, 3, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    ordenamientoCubeta(arr, n);

    printf("Arreglo ordenado por cubetas: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
