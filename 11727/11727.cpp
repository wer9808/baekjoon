#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    long long dp[n + 1];

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
    }

    cout << dp[n] << '\n';

    return 0;
}