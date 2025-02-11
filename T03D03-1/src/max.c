#include <stdio.h>
int find_max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        printf("n/a\n");
        return 1;
    }
    int max = find_max(a, b);
    printf("%d\n", max);

    return 0;
}
