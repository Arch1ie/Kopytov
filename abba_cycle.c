#include <stdio.h>

int FindAbba(char mas[8][8], int i, int j) {
    int cnt = 0;
    if (mas[i][j] == 'A') { // текущее
        if (j + 1 < 8 && mas[i][j + 1] == 'B') { // вправо
            if (j + 2 < 8 && mas[i][j + 2] == 'B') { // вправо+вправо
                if (j + 3 < 8 && mas[i][j + 3] == 'A') cnt++; // вправо+вправо+вправо
                if (i + 1 < 8 && mas[i + 1][j + 2] == 'A') cnt++; // вправо+вправо+вниз
            }
            if (i + 1 < 8 && mas[i + 1][j + 1] == 'B') { // вправо+вниз
                if (j + 2 < 8 && mas[i + 1][j + 2] == 'A') cnt++; // вправо+вниз+вправо
                if (i + 2 < 8 && mas[i + 2][j + 1] == 'A') cnt++; // вправо+вниз+вниз
            }
            if (i - 1 > -1 && mas[i - 1][j + 1] == 'B') { // вправо+вверх
                if (j + 2 < 8 && mas[i - 1][j + 2] == 'A') cnt++; // вправо+вверх+вправо
                if (mas[i - 2][j + 1] == 'A') cnt++; // вправо+вверх+вверх
                if (mas[i - 1][j] == 'A') cnt++; // вправо+вверх+влево
            }
        }
        if (i + 1 < 8 && mas[i + 1][j] == 'B') { // вниз
            if (j + 1 < 8 && mas[i + 1][j + 1] == 'B') { // вниз+вправо
                if (j + 2 < 8 && mas[i + 1][j + 2] == 'A') cnt++; // вниз+вправо+вправо
                if (i + 2 < 8 && mas[i + 2][j + 1] == 'A') cnt++; // вниз+вправо+вниз
            }
            if (i + 2 < 8 && mas[i + 2][j] == 'B') { // вниз+вниз
                if (j + 1 < 8 && mas[i + 2][j + 1] == 'A') cnt++; // вниз+вниз+вправо
                if (i + 3 < 8 && mas[i + 3][j] == 'A') cnt++; // вниз+вниз+вниз
            }
            if (j - 1 > -1 && mas[i + 1][j - 1] == 'B') { // вниз+влево
                if (i + 2 < 8 && mas[i + 2][j - 1] == 'A') cnt++; // вниз+влево+вниз
                if (mas[i][j - 1] == 'A') cnt++; // вниз+влево+вверх
                if (j - 2 > -1 && mas[i - 1][j - 2] == 'A') cnt++; // вниз+влево+влево
            }
        }
    }
    printf("%d %d %d ", i, j, cnt);
    return cnt;
}
int Abba(int sample[8]) {
    int n; char charMassive[8][8]; int k; int cnt = 0;
    for (int i = 0; i < 8; i++) {
        n = sample[i]; k = 0;
        for (int j = 7; j >= 0; j--) {
            int x = (n >> j * 4) & 0x0000000F; 
            charMassive[i][k] = x < 10 ? x + '0' : x - 10 + 'A';
            k += 1;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", charMassive[i][j]);
            cnt += FindAbba(charMassive, i, j);
        }
        printf("\n");
    } return cnt;
}
int main() {
    int sample1[8] = { -1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592 };
    int sample2[8] = { -1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840 };
    printf("%d\n", Abba(sample1));
    printf("%d", Abba(sample2)); return 0;
}