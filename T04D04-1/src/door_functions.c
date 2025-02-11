#include <math.h>
#include <stdio.h>

double verger_a(double x) { return sin(x) * (1 + cos(x)); }

double lemniscate(double x) {
  double result = sin(2 * x);
  return (result < 0) ? -1 : sqrt(result);
}

double hyperbola(double x) { return (x == 0) ? -1 : 1 / x; }

int main() {
  const int steps = 42;
  const double start = -M_PI;
  const double end = M_PI;
  double step_size = (end - start) / (steps - 1);

  for (int i = 0; i < steps; i++) {
    double x = start + i * step_size;
    double verger_value = verger_a(x);
    double lemniscate_value = lemniscate(x);
    double hyperbola_value = hyperbola(x);

    if (lemniscate_value < 0) {
      printf("%.7f | %.7f | - | ", x, verger_value);
    } else {
      printf("%.7f | %.7f | %.7f | ", x, verger_value, lemniscate_value);
    }

    if (hyperbola_value < 0) {
      printf("-\n");
    } else {
      printf("%.7f\n", hyperbola_value);
    }
  }

  return 0;
}
