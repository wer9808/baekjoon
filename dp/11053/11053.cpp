#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/

int main() {

    int N;

    scanf("%d", &N);

    int seq[1000];
    int l[1000], p[1000], max;

    for (int i = 0; i < N; i++) {
        scanf("%d", &seq[i]);
        l[i] = 1;
        p[i] = 0;
    }

    l[0] = 1;
    p[0] = 0;
    max = 1;
    
    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (seq[i] > seq[j]) { // 현재 값보다 작은 값만 조사
                if (l[j] + 1 >= l[i]) { // 현재 값이 포함된 수열보다 더 길 경우
                    l[i] = l[j] + 1; // 최장 수열을 갱신
                    if (l[i] > max) {
                        max = l[i];
                    }
                }
            }
            else { // 현재 값이 더 작은 경우

            }
        }
    }

    printf("%d\n", max);

    return 0;
}