#include <stdio.h>
#include <stdlib.h>

#define STATIC_MAX 100

void input(int **matrix, int n, int a) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < a; j++)
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
}

void output(int **matrix, int n, int a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a; j++) printf(j == a - 1 ? "%d" : "%d ", matrix[i][j]);
        if (i < n - 1) printf("\n");
    }
}

int **allocate_matrix(int n, int a, int choice) {
    if (choice == 1) return NULL;  // Статическое выделение
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (!matrix) return NULL;

    if (choice == 2) {
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *)malloc(a * sizeof(int));
            if (!matrix[i]) {
                // Освобождаем память, выделенную для предыдущих строк
                for (int j = 0; j < i; j++) {
                    free(matrix[j]);
                }
                free(matrix);
                return NULL;
            }
        }
    } else if (choice == 3 || choice == 4) {
        matrix[0] = (int *)malloc(n * a * sizeof(int));
        if (!matrix[0]) {
            free(matrix);  // Освобождаем память для matrix
            return NULL;
        }
        for (int i = 1; i < n; i++) matrix[i] = matrix[0] + i * a;
    }
    return matrix;
}

void free_matrix(int **matrix, int n, int choice) {
    if (choice == 2) {
        for (int i = 0; i < n; i++) free(matrix[i]);
    } else if (choice == 3 || choice == 4) {
        free(matrix[0]);
    }
    free(matrix);
}

int main() {
    int n, a, choice;
    if (scanf("%d %d %d", &choice, &n, &a) != 3 || n <= 0 || a <= 0 || n > STATIC_MAX || a > STATIC_MAX ||
        choice < 1 || choice > 4) {
        printf("n/a");
        return 1;
    }

    int static_matrix[STATIC_MAX][STATIC_MAX];
    int **matrix = (choice == 1) ? (int **)static_matrix : allocate_matrix(n, a, choice);
    if (!matrix) {
        printf("n/a");
        return 1;
    }

    input(matrix, n, a);
    output(matrix, n, a);
    if (choice != 1) free_matrix(matrix, n, choice);

    return 0;
}