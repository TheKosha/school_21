#include <math.h>
#include <stdio.h>

#define MAX_NUMBERS 30

double calculate_mean(int numbers[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

double calculate_variance(int numbers[], int count, double mean) {
    double variance = 0;
    for (int i = 0; i < count; i++) {
        variance += pow(numbers[i] - mean, 2);
    }
    return variance / count;
}

int is_valid_number(int number, double mean, double std_dev) {
    return (number != 0) && (number % 2 == 0) && (number >= mean) && (number <= mean + 3 * std_dev);
}

int search(int numbers[], int count) {
    if (count == 0) {
        return 0;
    }

    double mean = calculate_mean(numbers, count);
    double variance = calculate_variance(numbers, count, mean);
    double std_dev = sqrt(variance);

    for (int i = 0; i < count; i++) {
        if (is_valid_number(numbers[i], mean, std_dev)) {
            return numbers[i];
        }
    }

    return 0;
}

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    int number;

    while (scanf("%d", &number) == 1 && count < MAX_NUMBERS) {
        numbers[count++] = number;
    }

    // Проверка на корректность ввода
    if (count == 0 || count > MAX_NUMBERS) {
        printf("n/a\n");
        return 0;
    }

    int result = search(numbers, count);
    printf("%d\n", result);

    return 0;
}
