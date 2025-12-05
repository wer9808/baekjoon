#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main() {

    int N;

    scanf("%d", &N);

    int score[N + 1];
    int max[N + 1];

    for (int i = 1; i <= N; i++) {
        scanf("%d", &score[i]);
        max[i] = INT_MIN;
    }

    /*
    2칸 전 max + 현재 칸
    1칸 전의 2칸 전 max + 1칸 전 + 현재 칸

    max[i - 2] + sc[i]
    max[i - 3] + sc[i - 1] + sc[i]
    */

    score[0] = 0;
    max[0] = 0;
    max[1] = score[1];
    if (N >= 2) max[2] = score[1] + score[2];

    for (int i = 3; i <= N; i++) {
        int x = max[i - 2] + score[i];
        int y = max[i - 3] + score[i - 1] + score[i];
        max[i] = MAX(x, y);
    }

    printf("%d\n", max[N]);

    return 0;
}