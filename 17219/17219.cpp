#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool compare(const pair<string, string> &a, const pair<string, string> &b) {
    return a.first < b.first;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    unordered_map<string, string> sites;

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        sites[a] = b;
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        cout << sites[s] << "\n";
    }

    return 0;
}