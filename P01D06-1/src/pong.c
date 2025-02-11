#include <stdio.h>
#define FIELD_WIDTH 25
#define FIELD_LENGTH 80
#define ROCKET_1_STAND_POS_X 2
#define ROCKET_2_STAND_POS_X 77
#define Winpoint 21
int moveRocket(int rocket_1_Y, int rocket_2_Y);
int moveBall(int ball_X, int ball_Y,int rocket_1_Y, int rocket_2_Y);
void screenRendering(int rocket_1_Y, int rocket_2_Y, int ball_X, int ball_Y, int score_Pl_1, int score_Pl_2);
int checkTablo(int score_Pl_1, int score_Pl_2);
void clearScreen();
int main() {
    int rocket_1_Y = 12;
    int rocket_2_Y = 12;
    int ball_X = FIELD_LENGTH / 2;
    int ball_Y = FIELD_WIDTH / 2;
    int vec_X = -1;
    int vec_Y = 1;
    int score_Pl_1 = 0;
    int score_Pl_2 = 0;
    int game_over = 0;
    while (!game_over) {
        clearScreen();
        screenRendering(rocket_1_Y, rocket_2_Y, ball_X, ball_Y, score_Pl_1, score_Pl_2);

        int flag = moveRocket(rocket_1_Y, rocket_2_Y);
        if (flag == 1) {
            rocket_1_Y -= 1;
        } else if (flag == 2) {
            rocket_1_Y += 1;
        } else if (flag == 3) {
            rocket_2_Y -= 1;
        } else if (flag == 4) {
            rocket_2_Y += 1;
        }

        int ballResult = moveBall(ball_X, ball_Y, rocket_1_Y, rocket_2_Y);
        if (ballResult == 1) {
            vec_Y = -vec_Y;
        } else if (ballResult == 2) {
            vec_X = -vec_X;
        } else if (ballResult == 3) {
            score_Pl_1++;
            ball_X = FIELD_LENGTH / 2;
            ball_Y = FIELD_WIDTH / 2;
            vec_X = -1;
            vec_Y = 1;
        } else if (ballResult == 4) {
            score_Pl_2++;
            ball_X = FIELD_LENGTH / 2;
            ball_Y = FIELD_WIDTH / 2;
            vec_X = 1;
            vec_Y = 1;
        }

        ball_Y += vec_Y;
        ball_X += vec_X;

        int tablo_result = checkTablo(score_Pl_1, score_Pl_2);
        if (tablo_result == 1) {
            game_over = 1;
        }
    }
    return 0;
}

int moveRocket(int rocket_1_Y, int rocket_2_Y) {
    char temp = 0;
    int flag = 0;

    temp = getchar();

    if (temp == 'a' || temp == 'A') {
        if ((rocket_1_Y - 2) >= 1) {
            flag = 1;
        }
    } else if (temp == 'z' || temp == 'Z') {
        if ((rocket_1_Y + 2) < FIELD_WIDTH - 1) {
            flag = 2;
        }
    } else if (temp == 'k' || temp == 'K') {
        if ((rocket_2_Y - 2) >= 1) {
            flag = 3;
        }
    } else if (temp == 'm' || temp == 'M') {
        if ((rocket_2_Y + 2) < FIELD_WIDTH - 1) {
            flag = 4;
        }
    }

    if (temp != 'a' && temp != 'A' && temp != 'z' && temp != 'Z' && temp != 'k' && temp != 'K' &&
        temp != 'm' && temp != 'M' && temp != '\n') {
        while (getchar() != '\n');
    }

    return flag;
}

int moveBall(int ball_X, int ball_Y, int rocket_1_Y, int rocket_2_Y) {
    int flag = 0;
    if (ball_Y == 1 || ball_Y == FIELD_WIDTH - 2) {
        flag = 1;
    }
    if ((ball_X == ROCKET_1_STAND_POS_X + 1) &&
        (ball_Y == rocket_1_Y - 1 || ball_Y == rocket_1_Y || ball_Y == rocket_1_Y + 1)) {
        flag = 2;
    }
    if (ball_X == ROCKET_2_STAND_POS_X - 1 &&
        (ball_Y == rocket_2_Y - 1 || ball_Y == rocket_2_Y || ball_Y == rocket_2_Y + 1)) {
        flag = 2;
    }
    if (ball_X <= 1) {
        flag = 3;
    }
    if (ball_X >= (FIELD_LENGTH - 2)) {
        flag = 4;
    }
    return flag;
}

void screenRendering(int rocket_1_Y, int rocket_2_Y, int ball_X, int ball_Y, int score_Pl_1, int score_Pl_2) {
    clearScreen();

    for (int y = 0; y < FIELD_WIDTH; ++y) { 1
        for (int x = 0; x < FIELD_LENGTH; ++x) {
            if ((x == ROCKET_1_STAND_POS_X &&
                 (y == rocket_1_Y - 1 || y == rocket_1_Y || y == rocket_1_Y + 1)) ||
                (x == ROCKET_2_STAND_POS_X &&
                 (y == rocket_2_Y - 1 || y == rocket_2_Y || y == rocket_2_Y + 1))) {
                printf("|");
            } else if (x == ball_X && y == ball_Y) {
                printf("*");
            } else if (y == 0 || y == FIELD_WIDTH - 1 || x == 0 || x == FIELD_LENGTH - 1) {
                printf("'");
            } else if (x == FIELD_LENGTH / 2) {
                printf(":");
            } else if (y == FIELD_WIDTH / 10 && x == FIELD_LENGTH / 2 + 7) {
                printf("%d", score_Pl_1);
            } else if (y == FIELD_WIDTH / 10 && x == FIELD_LENGTH / 2 - 7) {
                printf("%d", score_Pl_2);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int checkTablo(int score_Pl_1, int score_Pl_2) {
    if (score_Pl_1 == Winpoint) {
        clearScreen();
        printf("Player 1 wins\n");
        return 1;
    }
    if (score_Pl_2 == Winpoint) {
        clearScreen();
        printf("Player 2 wins\n");
        return 1;
    }
    return 0;
}

void clearScreen() { printf("\033[2J\033[H"); }
