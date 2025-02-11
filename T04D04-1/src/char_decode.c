#include <stdio.h>
#include <string.h>

void encode(const char *input) {
    while (*input) {
        // Получаем ASCII код символа
        int ascii_value = (unsigned char)(*input);
        // Печатаем в шестнадцатеричном формате
        printf("%02X ", ascii_value);
        input++;
    }
    printf("\n");
}

int hexToDecimal(const char *hex) {
    int decimal_value = 0;
    while (*hex) {
        decimal_value *= 16;
        if (*hex >= '0' && *hex <= '9') {
            decimal_value += *hex - '0';
        } else if (*hex >= 'A' && *hex <= 'F') {
            decimal_value += *hex - 'A' + 10;
        } else if (*hex >= 'a' && *hex <= 'f') {
            decimal_value += *hex - 'a' + 10;
        }
        hex++;
    }
    return decimal_value;
}

void decode(const char *input) {
    while (*input) {
        // Пропускаем пробелы
        while (*input == ' ') {
            input++;
        }

        // Проверяем, достаточно ли символов для двух символов
        if (*(input + 1) == '\0') {
            printf("n/a\n");
            return;
        }

        // Читаем два символа
        char hex[3] = {0};
        hex[0] = *input;

        // Проверяем, что следующий символ не пробел и не конец строки
        if (*(input + 1) == '\0' || *(input + 1) == ' ') {
            printf("n/a\n");
            return;
        }

        hex[1] = *(input + 1);
        input += 2;

        // Преобразуем шестнадцатеричное представление в десятичное
        int ascii_value = hexToDecimal(hex);

        // Проверяем допустимость ASCII
        if (ascii_value < 0 || ascii_value > 255) {
            printf("n/a\n");
            return;
        }

        // Печатаем символ
        printf("%c ", (char)ascii_value);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("n/a\n");
        return 1;
    }

    int mode = argv[1][0] - '0'; // Convert char to int

    if (mode == 0) {
        // Кодирование
        char input[256];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Удаляем символ новой строки, если есть
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
            }
            encode(input);
        }
    } else if (mode == 1) {
        // Декодирование
        char input[256];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Удаляем символ новой строки, если есть
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
            }
            decode(input);
        }
    } else {
        printf("n/a\n");
        return 1;
    }

    return 0;
}
