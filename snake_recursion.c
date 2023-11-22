#include <stdio.h>
#define N 4 - 1
void snake(int example[N + 1][N + 1], int i, int j, int _cur, int _moveUp) {
    example[i][j] = _cur;
    if (i == N && j == N) return;
    if (_moveUp) return i > 0 && j < N ? snake(example, i - 1, j + 1, _cur + 1, 1) : snake(example, i == 0 & j < N ? i : i + 1, j < N ? j + 1 : j, _cur + 1, 0);
    else return i < N && j > 0 ? snake(example, i + 1, j - 1, _cur + 1, 0) : snake(example, i < N ? i + 1 : i, i < N && j == 0 ? j : j + 1, _cur + 1, 1);
}
int main() {

    int example[N + 1][N + 1]; snake(example, 0, 0, 1, 0);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) printf(example[i][j] < 10 ? "%d  " : "%d ", example[i][j]);
        printf("\n");
    } return 0;
}