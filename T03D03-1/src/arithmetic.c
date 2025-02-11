#include <stdio.h>

int main() {
    int a, b;
    
    if (scanf("%d%d", &a, &b) != 2) {
        printf("n/a\n");
        return 0;
    }
    if (b == 0) {
        printf("%d %d %d n/a\n", a + b, a - b, a * b);
    } else {
        printf("%d %d %d %d\n", a + b, a - b, a * b, a / b);
    }
    return 0;
}
