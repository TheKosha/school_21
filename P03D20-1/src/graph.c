#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POLE_VERT 80
#define POLE_GARIS 25

void grapih_logic(char grapih[POLE_GARIS][POLE_VERT], char grafic) {
    for (int i = 0; i < POLE_GARIS; i++) {
        for (int j = 0; j < POLE_VERT; j++) {
            if (grapih[i][j] != grafic) {
                grapih[i][j] = '.';
            } else {
                grapih[i][j] = '*';
            }
        }
    }
}
void printf_grapih(char grapih[POLE_GARIS][POLE_VERT]) {
    for (int h = 0; h < POLE_GARIS; h++) {
        for (int n = 0; n < POLE_VERT; n++) {
            printf("%c", grapih[h][n]);
        }
        printf("\n");
    }
}
int main() {
    char grafic = '*';
    char grapih[POLE_GARIS][POLE_VERT];
    grapih[10][20] = '*';
    grapih_logic(grapih, grafic);
    printf_grapih(grapih);
}