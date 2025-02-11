#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix;
    int n, m;
    int flag = 0;
    input(&matrix, &n, &m);
    if (n <= 0 || m <= 0) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (flag == 1) {
        int **result_vertical = (int **)malloc(n * sizeof(int *));
        int **result_horizontal = (int **)malloc(n * sizeof(int *));

        for (int i = 0; i < n; i++) {
            result_vertical[i] = (int *)malloc(m * sizeof(int));
            result_horizontal[i] = (int *)malloc(m * sizeof(int));
        }
        sort_vertical(matrix, n, m, result_vertical);
        output(result_vertical, n, m);
        printf("\n");
        printf("\n");
        sort_horizontal(matrix, n, m, result_horizontal);
        output(result_horizontal, n, m);
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
            free(result_vertical[i]);
            free(result_horizontal[i]);
        }
        free(matrix);
        free(result_vertical);
        free(result_horizontal);
    } else {
        printf("n/a");
    }

    return 0;
}
void input(int ***matrix, int *n, int *m) {
    scanf("%d %d", n, m);
    *matrix = (int **)malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (int *)malloc(*m * sizeof(int));
        for (int j = 0; j < *m; j++) {
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}
void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}
void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *temp = (int *)malloc(n * m * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[k++] = matrix[i][j];
        }
    }
    for (int i = 0; i < n * m - 1; i++) {
        for (int j = 0; j < n * m - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    k = 0;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][j] = temp[k++];
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                result_matrix[i][j] = temp[k++];
            }
        }
    }
    free(temp);
}
void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *temp = (int *)malloc(n * m * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[k++] = matrix[i][j];
        }
    }
    for (int i = 0; i < n * m - 1; i++) {
        for (int j = 0; j < n * m - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = temp[k++];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = temp[k++];
            }
        }
    }

    free(temp);
}