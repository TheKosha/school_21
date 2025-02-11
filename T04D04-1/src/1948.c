#include <math.h>
#include <stdio.h>

int IsPrime(int N) {
  if (N < 2)
    return 0;
  for (int J = 2; J <= sqrt(N); J++) {
    if (N % J == 0) {
      return 0;
    }
  }
  return 1;
}

int IsDivisor(int Num, int Divisor) { return Num % Divisor == 0; }

int main() {
  int Number;
  int LargestPrimeDivisor = -1;
  scanf("%d", &Number);
  for (int I = 2; I <= Number; I++) {
    if (IsPrime(I) && IsDivisor(Number, I)) {
      LargestPrimeDivisor = I;
    }
  }
  if (LargestPrimeDivisor > 0) {
    printf("%d\n%d\n", Number, LargestPrimeDivisor);
  } else {
    printf("n/a\n");
  }
  return 0;
}
