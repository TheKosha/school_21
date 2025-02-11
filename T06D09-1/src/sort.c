#include <stdio.h>

#define SIZE 10

int read_arr(int *arr) {
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

void sort_arr(int *arr) {
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

void print_arr(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", arr[i]);
        if (i < SIZE - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    if (!read_arr(arr)) {
        printf("n/a\n");
        return 1;
    }
    sort_arr(arr);
    print_arr(arr);

    return 0;
}