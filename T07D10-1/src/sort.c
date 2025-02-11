#include <stdio.h>
#include <stdlib.h>

int read_arr(int *arr, int SIZE) {
    int cnt = 0;
    while (scanf("%d", &arr[cnt]) == 1) {
        cnt++;
        if (cnt == SIZE) {
            break;
        }
    }
    if (cnt != SIZE || getchar() != '\n') {
        return 0;
    }
    return 1;
}

void sort_arr(int *arr, int SIZE) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void print_arr(int *arr, int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", arr[i]);
        if (i < SIZE - 1) {
            printf(" ");
        }
    }
}

int main() {
    int *arr;
    int SIZE;
    scanf("%d", &SIZE);
    arr = (int *)malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("n\a");
        return 1;
    }
    if (!read_arr(arr, SIZE)) {
        printf("n/a");
        return 1;
    }
    sort_arr(arr, SIZE);
    print_arr(arr, SIZE);

    free(arr);
    return 0;
}