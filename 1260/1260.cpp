#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    int N, M, V;

    scanf("%d %d %d", &N, &M, &V);

    vector<int> *g = new vector<int>[N + 1];
    bool *visited = new bool[N + 1];

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < N + 1; i++) {
        sort(g[i].begin(), g[i].end());
    }

    vector<int> dfs;
    queue<int> bfs;

    for (int i = 0; i < N + 1; i++) {
        visited[i] = false;
    }

    int n;
    dfs.push_back(V);
    while (dfs.size() > 0) {
        n = dfs.back();
        dfs.pop_back();
        if (!visited[n]) {
            visited[n] = true;
            printf("%d ", n);
        }
        for (vector<int>::reverse_iterator c = g[n].rbegin(); c != g[n].rend(); c++) {
            if (!visited[*c]) {
                dfs.push_back(*c);
            }
        }
    }

    printf("\n");


    for (int i = 0; i < N + 1; i++) {
        visited[i] = false;
    }

    bfs.push(V);
    while (bfs.size() > 0) {
        n = bfs.front();
        bfs.pop();
        if (!visited[n]) {
            visited[n] = true;
            printf("%d ", n);
        }
        for (vector<int>::iterator c = g[n].begin(); c != g[n].end(); c++) {
            if (!visited[*c]) {
                bfs.push(*c);
            }
        }
    }

    return 0;
}