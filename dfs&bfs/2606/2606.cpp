#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

첫째 줄에는 컴퓨터의 수가 주어진다. 
컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 
이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.
*/

/*
그래프 및 BFS&DFS 문제

Set 형태로 주어진 N개의 컴퓨터 노드를 의미하는 포인터 배열 생성 (ex list[1] -> 1번 컴퓨터 )
포인터 배열에는 링크드 리스트 형태로 해당 노드들과 연결된 컴퓨터 노드 표현
1번 컴퓨터의 포인터부터 시작 -> 연결된 노드 방문 여부 확인
미방문시 방문 표시하고 포인터 배열에서 해당 포인터가 가리키는 노드를 방문
방문시 다음 포인터로 넘어감
*/

typedef struct _Node {
    struct _Node *right;
    int key;
    bool visited;
} Node;

void link(Node **l, int a, int b) {
    Node *n_a = new Node { nullptr, a, false };
    Node *n_b = new Node { nullptr, b, false };

    Node *r = l[a];
    while (r->right != nullptr) {
        r = r->right;
    }
    r->right = n_b;
    
    r = l[b];
    while (r->right != nullptr) {
        r = r->right;
    }
    r->right = n_a;
}

int explore(Node **l, int k) {
    Node *r = l[k];
    int cnt = 0;
    if (r->visited) {
        return cnt;
    }
    else {
        r->visited = true;
        r = r->right;
        cnt++;
        while (r != nullptr)
        {
            cnt += explore(l, r->key);
            r = r->right;
        }
        return cnt;
    }
}

void dispose(Node **l, int n) {
    for (int i = 0; i <= n; i++) {
        Node* x = l[i];
        if (x != nullptr) {
            while (x->right != nullptr) {
                Node* t = x->right;
                delete x;
                x = t;
            }
        }
    }
}

int main(int argc, char **argv) {

    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    Node **coms = new Node*[n + 1];
    for (int i = 1; i <= n; i++) {
        coms[i] = new Node { nullptr, i, false };
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        link(coms, a, b);
    }

    int cnt = explore(coms, 1) - 1;
    printf("%d\n", cnt);

    dispose(coms, n);

    return 0;
}