#inc#include <stdio.h>

#define SHIFT 3 // Размер сдвига для кодирования и декодирования

void encode() {
    char input, output;
    printf("Введите символ (заканчивайте ввод нажатием Enter):\n");
    while ((input = getchar()) != '\n') { // Считываем символы до нажатия Enter
        output = input + SHIFT; // Кодируем символ
        printf("%c", output); // Выводим закодированный символ
    }
    printf("\n");
}

void decode() {
    char input, output;
    printf("Введите закодированный символ (заканчивайте ввод нажатием Enter):\n");
    while ((input = getchar()) != '\n') { // Считываем символы до нажатия Enter
        output = input - SHIFT; // Декодируем символ
        printf("%c", output); // Выводим декодированный символ
    }
    printf("\n");
}

int main() {
    int choice;

    printf("Введите 0 для кодирования или 1 для декодирования: ");
    scanf("%d", &choice);
    getchar(); // Очищаем символ новой строки из буфера ввода

    if (choice == 0) {
        encode();
    } else if (choice == 1) {
        decode();
    } else {
        printf("Неверный выбор. Пожалуйста, введите 0 или 1.\n");
    }

    return 0;
}
