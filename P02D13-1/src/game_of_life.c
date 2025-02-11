#include <stdio.h>
#include <stdlib.h>

#define VERX 25
#define POPEREK 80

void clearScreen() { printf("\033[2J\033[H"); }

int life_sosed(int pole[VERX][POPEREK], int x, int y) {
    int life = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = (x + i + VERX) % VERX;
            int ny = (y + j + POPEREK) % POPEREK;
            if (pole[nx][ny] == 1) life++;
        }
    }
    return life;
}

void up_pole(int pole[VERX][POPEREK]) {
    int new_pole[VERX][POPEREK] = {0};
    for (int i = 0; i < VERX; i++) {
        for (int j = 0; j < POPEREK; j++) {
            int neighbors = life_sosed(pole, i, j);
            if (pole[i][j] == 1) {
                new_pole[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_pole[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < VERX; i++) {
        for (int j = 0; j < POPEREK; j++) {
            pole[i][j] = new_pole[i][j];
        }
    }
}

void print_pole(int pole[VERX][POPEREK]) {
    clearScreen();
    for (int i = 0; i < VERX; i++) {
        for (int j = 0; j < POPEREK; j++) {
            printf("%c", pole[i][j] ? 'O' : '.');
        }
        printf("\n");
    }
}

void read_file(char *filename, int pole[VERX][POPEREK]) {
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < VERX; ++i) {
        for (int j = 0; j < POPEREK; ++j) {
            int value = fgetc(file) - '0';
            if (value != 0 && value != 1) {
                fclose(file);
                exit(EXIT_FAILURE);
            }
            pole[i][j] = value;
        }
        fgetc(file);
    }

    fclose(file);
}

int main() {
    int pole[VERX][POPEREK] = {0};
    printf("Выберите начальное состояние: 1-5\n");
    printf("Введите номер: ");

    int choice;
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
        char *filenames[] = {"initial_state_1.txt", "initial_state_2.txt", "initial_state_3.txt",
                             "initial_state_4.txt", "initial_state_5.txt"};
        read_file(filenames[choice - 1], pole);
    } else {
        printf("Неправильный выбор.\n");
        return EXIT_FAILURE;
    }

    int delay = 100000;

    while (1) {
        print_pole(pole);
        up_pole(pole);
        for (int i = 0; i < delay * 1000; i++);
    }

    return 0;
}
