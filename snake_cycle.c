#include <stdio.h>
#define N 4 - 1
int main() {
    int mat[N + 1][N + 1] = { 0 }; int ch = 0; int a = 0; int b = 0; int flag = 0;
    while (mat[N][N] == 0) {
        ch += 1; mat[a][b] = ch;
        if (flag) {
            if (a > 0 && b < N) { a -= 1; b += 1; }
            else {
                if (a == 0 && b < N) b += 1;
                else if (b == N) a += 1; flag = 0;
            }
        }
        else // ход вниз
        {
            if (a < N && b>0) { a += 1; b -= 1; }
            else {
                if (a < N && b == 0) a += 1;
                else if(a == N) b += 1; flag = 1;
            }
        }
    }
    for (int a1 = 0; a1 <= N; a1++) {
        for (int b1 = 0; b1 <= N; b1++) printf(mat[a1][b1] < 10 ? "%d  " : "%d ", mat[a1][b1]);
        printf("\n");
    }
    return 0;
}