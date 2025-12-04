#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int N, K;
    int M = 0;

    scanf("%d %d", &N, &K);

    int coin[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &coin[i]);
    }

    for (int i = N - 1; i >= 0; ) {
        if (coin[i] > K) {
            i--;
        }
        else {
            M += K / coin[i];
            K %= coin[i];
        }

        if (K == 0) break;
    }

    printf("%d\n", M);

    return 0;
}