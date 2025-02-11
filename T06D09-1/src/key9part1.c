#include <stdio.h>

#define MAX_SIZE 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);  // Updated declaration
int find_numbers(const int *buffer, int length, int number, int *numbers);

int main() {
    int buffer[MAX_SIZE], length;
    int numbers[MAX_SIZE], count;

    input(buffer, &length);

    if (length <= 0 || length > MAX_SIZE) {
        printf("n/a\n");
        return 1;
    }

    int sum = sum_numbers(buffer, length);

    if (sum == 0) {
        printf("n/a\n");
        return 1;
    }

    count = find_numbers(buffer, length, sum, numbers);
    printf("%d\n", sum);
    output(numbers, count);

    return 0;
}

void input(int *buffer, int *length) {
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

int sum_numbers(const int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }

    return sum;
}

int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count++] = buffer[i];
        }
    }

    return count;
}