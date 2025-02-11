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
                for (int j = 0; j < i; j++) free(matrix[j]);
                free(matrix);
                return NULL;
            }
        }
    } else if (choice == 3 || choice == 4) {
        matrix[0] = (int *)malloc(n * a * sizeof(int));
        if (!matrix[0]) {
            free(matrix);
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

void compute_max_row(int **matrix, int n, int a, int *max_row) {
    for (int i = 0; i < n; i++) {
        max_row[i] = matrix[i][0];
        for (int j = 1; j < a; j++) {
            if (matrix[i][j] > max_row[i]) {
                max_row[i] = matrix[i][j];
            }
        }
    }
}

void compute_min_col(int **matrix, int n, int a, int *min_col) {
    for (int j = 0; j < a; j++) {
        min_col[j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] < min_col[j]) {
                min_col[j] = matrix[i][j];
            }
        }
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf(i == size - 1 ? "%d" : "%d ", arr[i]);
    }
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

    // Вычисление максимальных элементов в строках
    int max_row[n];
    compute_max_row(matrix, n, a, max_row);

    // Вычисление минимальных элементов в столбцах
    int min_col[a];
    compute_min_col(matrix, n, a, min_col);

    // Вывод результатов
    printf("\n");
    print_array(max_row, n);
    printf("\n");
    print_array(min_col, a);

    if (choice != 1) free_matrix(matrix, n, choice);

    return 0;
}