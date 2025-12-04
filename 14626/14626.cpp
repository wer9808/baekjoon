#include <stdio.h>
#include <string>

using namespace std;

#define N 13

int main(int argc, char **argv) {

    char num;
    int checksum = 0;
    int missed = -1;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        scanf("%c", &num);
        if (num != '*') {
            int mul = i % 2 ? 3 : 1;
            checksum += mul * (int)(num - '0');
        }
        else {
            missed = i;
        }
    }

    if (missed % 2) {
        //합에 소실번호 * 3을 더했을 때 10으로 나눠떨어져야 함
        for (int i = 1; i < 10; i++) {
            if ((i * 3 + checksum) % 10 == 0) {
                ans = i;
                break;
            }
        }
    }
    else {
        ans = 10 - (checksum % 10);
    }

    printf("%d", ans);

    return 0;
}