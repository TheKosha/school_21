#include <stdio.h>
#include <math.h>

double calculate_function(double x) {
    double term1 = 7e-3 * pow(x, 4);
    double term2 = (22.8 * pow(x, 1.0/3.0) - 1e3) * x + 3;
    double denominator = (x * x) / 2.0;
    double term3 = (denominator != 0) ? (term2 / denominator) : 0;
    double term4 = x * pow(10 + x, 2.0/x);
    return term1 + term3 - term4 - 1.01;
}
int main() {
    double x;
    if (scanf("%lf", &x) != 1) {
        printf("n/a\n");
        return 1;
    }
    double result = calculate_function(x);
    result = round(result * 10) / 10;
    printf("%.1f\n", result);
    return 0;
}
