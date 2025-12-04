#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

#define NAME_MAX 21

int main(int argc, char **argv) {

    int N, M;
    int cnt = 0;
    set<string> ans;
    unordered_map<string, bool> l;

    scanf("%d %d", &N, &M);

    char name[NAME_MAX];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", name);
        string s = name;
        l[s] = true;
    }

    for (int i = 0; i < M; i++) {
        scanf("%s", name);
        string s = name;
        if (l.find(s) != l.end()) {
            ans.insert(s);
        }
    }

    printf("%ld\n", ans.size());
    
    for (set<string>::iterator iter = ans.begin(); iter != ans.end(); iter++) {
        printf("%s\n", ((string)*iter).c_str());
    }

    return 0;
}