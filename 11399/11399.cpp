#include <cstdio>
#include <vector>
using namespace std;

#define MAX_VAL 1000

int pp[MAX_VAL + 1] = { 0, };

int main(int argc, char **argv) {

    int N;

    scanf("%d", &N);

    int p;
    for (int i = 0; i < N; i++) {
        scanf("%d", &p);
        pp[p]++;
    }

    int res = 0;
    int cnt = N;
    for (int i = 0; i < MAX_VAL + 1; ) {
        if (pp[i] > 0) {
            res += cnt * i;
            pp[i]--;
            cnt--;
        }
        else i++;
    }

    printf("%d\n", res);

    return 0;
}