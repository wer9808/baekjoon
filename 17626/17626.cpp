#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

    int n;

    scanf("%d", &n);

    int *ans = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        ans[i] = 4;
    }

    vector<int> v;
    int j = 1, k = 1;
    for (int i = 1; i <= n; i++) {
        if (k > i) {
            for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
                int x = ans[*it] + ans[i - *it];
                if (ans[i] > x) {
                    ans[i] = x;
                }
            }
        }
        else if (k == i) {
            ans[i] = 1;
            v.push_back(k);
            j++;
            k = j * j;
        }
    }

    printf("%d\n", ans[n]);

    return 0;
}