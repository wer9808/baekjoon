#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/

/*

N부터 너비우선탐색 시작
-1, +1, x2 위치의 최소 비용 확인
현재 위치 비용 + 1보다 비용이 큰 경우 최소 비용을 갱신하고 재탐색을 위해 큐에 삽입

*/

#define N_MAX 100001

int main(int argc, char **argv) {

    int N, K;
    // int *bt = new int[N_MAX];
    int *min = new int[N_MAX];
    queue<int> q;

    scanf("%d %d", &N, &K);

    // 초기화

    for (int i = 0; i < N_MAX; i++) {
        // bt[i] = -1;
        min[i] = N_MAX;
    }

    q.push(N);
    min[N] = 0;


    int x, a, b, c, new_min;

    while (q.size() > 0) {
        x = q.front();
        q.pop();

        if (x == K) continue;

        a = x - 1;
        b = x + 1;
        c = 2 * x;
        new_min = min[x] + 1;

        if (a >= 0 && min[a] > new_min) {
            q.push(a);
            min[a] = new_min;
            // bt[a] = x;
        }
        if (b < N_MAX && min[b] > new_min) {
            q.push(b);
            min[b] = new_min;
            // bt[b] = x;
        }
        if (c < N_MAX && min[c] > new_min) {
            q.push(c);
            min[c] = new_min;
            // bt[c] = x;
        }
        
    }

    printf("%d\n", min[K]);

    /* 
    백트래킹 확인용
    int t = K;
    while (t != N) {
        printf("%d-", t);
        t = bt[t];
    }
    printf("%d\n", N);
     */

    return 0;
}