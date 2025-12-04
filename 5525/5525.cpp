#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

    int N, M;

    scanf("%d %d", &N, &M);

    char *S = new char[M + 1];
    scanf("%s", S);

    bool flag = false;
    int ans = 0, cnt = 0;
    for (int i = 0; i <= M; i++) {
        if (flag) {
            // IOI 세기 도중
            if (S[i] == 'I') { // S 세기 도중일 때 I가 나온 경우
                if (S[i - 1] == 'O') { // 이전 문자가 O이면 IOI가 나온 것
                    cnt++; // IOI 카운트 증가
                }
                else { // 이전 문자가 I면 IOI 불연속
                    // 현재까지 연속 IOI 카운트를 기록하고 초기화
                    // 현재 I부터 다시 S 세기 시작
                    if (cnt >= N) {
                        ans += cnt - N + 1;
                    }
                    cnt = 0;
                }
            }
            else if (S[i] == 'O') {
                // S 세기 도중일 때 O가 나온 경우
                if (S[i - 1] == 'O') {
                    // 이전 문자가 O이면 IOI 불연속
                    // 현재까지 IOI 연속 카운트를 기록하고 초기화
                    // I가 나올 때까지 S 세기는 중단
                    if (cnt >= N) {
                        ans += cnt - N + 1;
                    }
                    cnt = 0;
                    flag = false;
                }
            }
            else {
                // 문자열 끝인 경우 그냥 S 세기 종료
                if (cnt >= N) {
                    ans += cnt - N + 1;
                }
                break;
            }
        }
        else {
            // IOI 세기 미진행중
            if (S[i] == 'I') {
                // I가 나오면 세기 시작
                flag = true;
                cnt = 0;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}