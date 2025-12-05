#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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