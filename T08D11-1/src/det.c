#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
void input(double **matrix, int n, int m, int *flag);
void output(double det);
double det(double **matrix, int n) {
    double determinant = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    for (int col = 0; col < n; col++) {
        double **submatrix = (double **)malloc((n - 1) * sizeof(double *));
        for (int i = 0; i < n - 1; i++) {
            submatrix[i] = (double *)malloc((n - 1) * sizeof(double));
        }
        for (int i = 1; i < n; i++) {
            int subcol = 0;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                submatrix[i - 1][subcol] = matrix[i][j];
                subcol++;
            }
        }

        double sub_det = det(submatrix, n - 1);

        if (col % 2 == 0) {
            determinant += matrix[0][col] * sub_det;
        } else {
            determinant -= matrix[0][col] * sub_det;
        }

        for (int i = 0; i < n - 1; i++) {
            free(submatrix[i]);
        }
        free(submatrix);
    }

    return determinant;
}

void input(double **matrix, int n, int m, int *flag) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                *flag = 0;
                return;
            }
        }
    }
    *flag = 1;
}
void output(double det) { printf("%.6lf\n", det); }

int main() {
    int n, m;
    int flag = 1;
    double determinant;
    if (scanf("%d %d", &n, &m) != 2 || n != m) {
        printf("n/a\n");
        return 1;
    }
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(m * sizeof(double));
    }

    input(matrix, n, m, &flag);
    if (flag == 0) {
        printf("n/a\n");
    } else {
        determinant = det(matrix, n);
        output(determinant);
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}