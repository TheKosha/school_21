#include <stdio.h>

#define MAX_SIZE 10

void input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void cycle_shift(int *buffer, int length, int shift);

int main() {
    int buffer[MAX_SIZE], length, shift;

    input(buffer, &length, &shift);

    if (length <= 0 || length > MAX_SIZE) {
        printf("n/a\n");
        return 1;
    }

    cycle_shift(buffer, length, shift);
    output(buffer, length);

    return 0;
}
void input(int *buffer, int *length, int *shift) {
    if (scanf("%d", length) != 1 || *length <= 0 || *length > MAX_SIZE) {
        *length = 0;
        return;
    }

    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            *length = 0;
            return;
        }
    }

    if (scanf("%d", shift) != 1) {
        *length = 0;
    }
}
void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
void cycle_shift(int *buffer, int length, int shift) {
    shift = shift % length;
    if (shift < 0) {
        shift += length;
    }
    int temp[MAX_SIZE];
    for (int i = 0; i < length; i++) {
        temp[i] = buffer[(i + shift) % length];
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }
}10