#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

n=1 -> | 1개
n=2 -> || - -> 2
n=3 -> ||| |- -| -> 3
n=4 -> |||| ||- -|| |-| -- -> 5
n=5 -> ||||| |||- ||-| -||| |-|| |-- --| -|- -> 8
n=6 -> |||||| ||||- |||-| |||=| ||=|| |=||| =|||| ||== |==| ==|| |=|= =|=| === >> 13
? 피보나치?

*/

int main() {

    int n;

    scanf("%d", &n);

    long long *ans = new long long[n + 1];
    ans[1] = 1;
    ans[2] = 2;

    for (int i = 3; i < n + 1; i++) {
        ans[i] = (ans[i - 1] + ans[i - 2]) % 10007;
    }

    printf("%lld\n", ans[n]);

    return 0;
}