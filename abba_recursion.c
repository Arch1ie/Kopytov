#include <stdio.h>
int abbaRec(char _cur, char _prev, int cnt, int i, int j, char sampleChar[8][8]) {
    if (i == -1 || j == -1) { return 0; } _cur = sampleChar[i][j];
    if (((_cur == 'A' && (_prev == '0' || _prev == 'B')) || (_cur == 'B' && (_prev == 'B' || _prev == 'A'))) && cnt < 4) {
        return abbaRec('0', _cur, cnt + 1, i < 8 ? i + 1 : -1, j, sampleChar) + abbaRec('0', _cur, cnt + 1, i, j > 0 ? j - 1 : -1, sampleChar) + abbaRec('0', _cur, cnt + 1, i > 0 ? i - 1 : -1, j, sampleChar) + abbaRec('0', _cur, cnt + 1, i, j < 8 ? j + 1 : -1, sampleChar);
    }
    else if (cnt == 4) {
        if (_cur == 'A' && _prev == 'B') return 1;
        else return 0;
    }
    else return 0;
}
int abba(int sample[8]) {
    int n; char sampleChar[8][8]; int k; int cnt = 0;
    for (int i = 0; i < 8; i++) {
        n = sample[i]; k = 0;
        for (int j = 7; j >= 0; j--) {
            int x = (n >> j * 4) & 0x0000000F;
            sampleChar[i][k] = x < 10 ? x + '0' : x - 10 + 'A';
            k += 1;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", sampleChar[i][j]);
            cnt += abbaRec('0', '0', 1, i, j, sampleChar);
        }
        printf("\n");
    } return cnt;
}
int main() {
    int sample1[8] = { -1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592 };
    int sample2[8] = { -1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840 };
    printf("%d\n", abba(sample1) / 2);
    printf("%d", abba(sample2) / 2); return 0;
}