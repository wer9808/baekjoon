#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main(int argc, char **argv) {

    int N, M, B;

    scanf("%d %d %d", &N, &M, &B);

    int grd[N][M];

    int l = 256, h = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            grd[i][j] = x;
            if (x < l) l = x;
            if (x > h) h = x;
        }
    }

    /*
    l과 h 사이에서 m을 선택
    모든 땅을 m으로 만드려고 시도
    블록이 모자라면 m = (l + h) / 2로 중간 지점 탐색
    안 모자라면 l++, m = l로 해서 시간 줄어드는지 확인
    */

    long long b;
    int m = (l + h) / 2;
    long long level = l, min_time = LONG_LONG_MAX, time;
    while (l <= h) {
        b = B;
        time = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int dt = grd[i][j] - m;
                if (dt > 0) { // 땅이 더 높으면
                    time += 2 * dt;
                    b += dt;
                }
                else {
                    time -= dt;
                    b += dt;
                }
            }
        }
        /*
        b가 0보다 작으면 블록 모자라므로 불가능한 값
        갱신 안 함
        */
        if (b < 0) {
            h = m - 1;
            m = (l + h) / 2;
        }
        /*
        0보다 크거나 같으면 가능
        최소 시간이면 시간, 높이 갱신
        시간 같은데 m이 더 크면 높이 갱신

        여기서가 문제인데...
        */
        else {
            if (time < min_time) {
                min_time = time;
                level = m;
            }
            else if (time == min_time) {
                if (m > level) {
                    level = m;
                }
            }
            l++;
            m = l;
        }
    }

    printf("%lld %lld\n", min_time, level);

    return 0;
}