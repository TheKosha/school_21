#include <stdio.h>

int Fibonacci(int N) {
  if (N == 0) {
    return 0;
  } else if (N == 1) {
    return 1;
  } else {
    return Fibonacci(N - 1) + Fibonacci(N - 2);
  }
}

int main() {
  int N;
  if (scanf("%d", &N) != 1 || N < 0) {
    printf("n/a\n");
    return 1;
  }

  char C;
  while ((C = getchar()) != '\n' && C != EOF) {
    if (C != ' ' && C != '\t') {
      printf("n/a\n");
      return 1;
    }
  }

  int Result = Fibonacci(N);
  printf("%d\n", Result);

  return 0;
}
