#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
1. x / 3 if x % 3 = 0
2. x / 2 if x % 2 = 0
3. x--

minop(x) = MIN(minop(x / 3), minop(x / 2), minop(x - 1)) + 1

0 if x = 1
minop(x - 1) if x % 3 != 0 & x % 2 != 0
MIN(minop(x - 1), minop(x / 2)) if x % 3 != 0 & x % 2 = 0
MIN(minop(x - 1), minop(x / 3)) if x % 3 = 0 & x % 2 != 0
MIN(minop(x / 3), minop(x / 2)) if x % 3 = 0 & x % 2 = 0

*/

/*
recursive
--> time over
*/
int minop(int x) {
    if (x == 1) {
        return 0;
    }
    else if (x % 3 && x % 2) {
        return minop(x - 1) + 1;
    }
    else if (x % 3) {
        return min(minop(x / 2), minop(x - 1)) + 1;
    }
    else if (x % 2) {
        return min(minop(x / 3), minop(x - 1)) + 1;
    }
    else {
        int minval = min(minop(x / 3), minop(x / 2));
        return minval + 1;
    }
}

int main(int argc, char **argv) {

    int N;
    int cnt = 0;

    scanf("%d", &N);

    int *tb = new int[N + 1];
    for (int i = 0; i < N + 1; i++) {
        tb[i] = N;
    }
    
    tb[N] = 0;

    for (int i = N; i > 1; i--) {
        int mod3 = i % 3, mod2 = i % 2;
        int div3 = i / 3, div2 = i / 2;

        int next = tb[i] + 1;

        if (mod3 == 0) {
            if (tb[div3] > tb[i] + 1) {
                tb[div3] = next;
            }
        }
        if (mod2 == 0) {
            if (tb[div2] > tb[i] + 1) {
                tb[div2] = next;
            }
        }
        if (tb[i - 1] > next) {
            tb[i - 1] = next;
        }
    }

    printf("%d\n", tb[1]);

    delete tb;

    return 0;
}