#include <iostream>

using namespace std;

/*
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
*/

/*
N자리 계단 수는
N-1자리 모든 계단 수의 뒤에 마지막자리의 +- 값
마지막자리가 9인 경우 +는 10이 되므로 제외
0인 경우도 -가 -1이므로 제외

그러면 N자리 수에 대해 끝자리가 x인 경우?
f(N-1, x-1) + f(N-1, x+1)
x-1 < 0? f(N-1, x+1)
x+1 > 9? f(N-1, x-1)

근데 0으로 시작하는 경우도 있으면 안됨.
즉 N=1일 때
f(2,1) = f(1,0) + f(1,2)
인데, f(1,0)을 0으로 처리하면 됨

*/

#define MOD 1000000000

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    long long stair[N + 1][10];

    stair[1][0] = 0;
    for (int i = 1; i < 10; i++) {
        stair[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            stair[i][j] = 0;
            if (j - 1 >= 0) {
                stair[i][j] += stair[i - 1][j - 1];
            }
            if (j + 1 < 10) {
                stair[i][j] += stair[i - 1][j + 1];
            }
            stair[i][j] %= MOD;
        }
    }

    long long sum = 0;
    for (int i = 0; i < 10; i++) sum += stair[N][i];
    
    cout << sum % MOD << "\n";

    return 0;
}