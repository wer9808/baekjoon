#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int find_root(int **all_set, int size, int e) {
    int x = e;
    while (x != (*all_set)[x]) {
        x = (*all_set)[x];
    }
    return x;
}

int merge_root(int **all_set, int size, int e1, int e2) {
    int s1 = find_root(all_set, size, e1);

    int x = e2;
    int tmp;
    while (x != (*all_set)[x]) {
        tmp = x;
        x = (*all_set)[x];
        (*all_set)[tmp] = s1;
    }
    (*all_set)[x] = s1;
    
    return s1;
}

int main(int argc, char **argv) {

    int N, M;
    int u, v;

    scanf("%d %d", &N, &M);

    int *all_set = new int[N + 1];
    for (int i = 0; i < N + 1; i++) {
        all_set[i] = i;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        merge_root(&all_set, N + 1, u, v);
    }

    int c = 1;
    int r = find_root(&all_set, N + 1, 1);
    int prev = r;
    for (int i = 2; i < N + 1; i++) {
        r = find_root(&all_set, N + 1, i);
        if (prev != r) {
            c++;
            prev = merge_root(&all_set, N + 1, prev, r);
        }
    }

    printf("%d\n", c);

    return 0;
}