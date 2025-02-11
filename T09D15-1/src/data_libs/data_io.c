#include "data_io.h"

#include <stdio.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);  // Используем %lf для double
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", data[i]);  // Используем %lf для double
    }
    printf("\n");
}