#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.
*/

int main(int argc, char **argv) {

    int N, M;

    scanf("%d %d", &N, &M);

    int x;
    int *p_sum = new int[N + 1];

    p_sum[0] = 0;
    for (int k = 1; k < N + 1; k++) {
        scanf("%d", &x);
        p_sum[k] = p_sum[k - 1] + x;
    }
    
    int i, j;

    for (int k = 0; k < M; k++) {
        scanf("%d %d", &i, &j);
        printf("%d\n", p_sum[j] - p_sum[i - 1]);
    }

    return 0;
}