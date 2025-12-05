#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제
상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 
정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.

목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 
그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 
예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 
상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. 
(총 7미터를 집에 들고 간다) 절단기에 설정할 수 있는 높이는 양의 정수 또는 0이다.

상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 
이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.
*/

/*
현재 설정한 H에 대해 나무들 중에 잘린 나무 높이들의 총합이 몇인지 구해야 함
잘린 나무 합을 구하지 않고는 H 최대값을 못 구하므로, 나무 높이 합을 구하는 시간은 O(N)으로 줄일 수 없음

1. 브루트포스
H를 0으로 하고, H를 1씩 높여가면서 M을 충족하는지 확인
H 값이 커지다가 M을 충족 못하는 상황이 오면 해당 지점이 H의 최대값이 됨.
이러면 O(H*N) 시간복잡도를 가짐

2. 이진탐색
어떤 높이 x에 대해 M을 충족 못했다면, x보다 높게 설정한 높이들에 대해서는 무조건 M을 만족시킬 수 없음.
높이 x에 대해 잘린 총합 S(x) = max(T1 - x, 0) + max(T2 - x, 0) + ... + max(Tn - x, 0) = SUM_i(max(Ti - x, 0)으로 표현 가능함
정수 x에 대해 항상 max(T - x, 0) >= max(T - (x + 1), 0)이 성립하므로 S(x) >= S(x + 1)도 성립한다.
따라서 S(x) < M이면 S(x + 1) < M이다.
반대로 x > y인 모든 y에 대해서 S(x) <= S(y)이 된다.
즉 어떤 x에 대해 S(x) >= M일 때, x보다 작은 y에 대해서는 검사할 필요 없다.

따라서 어떤 높이 x를 검사했을 때 M을 충족시키면, x < y인 모든 S(y)에 대해 S(x)가 최소이므로 검사할 필요가 없어진다.
반대로 어떤 높이 x를 검사했을 때 M을 충족시키지 못하면, x > y인 모든 S(y)에 S(y) < M이므로 검사할 필요가 없어진다.

결과적으로 특정 x를 검사함으로써 검사를 수행할 구간을 줄여나갈 수 있다.
이런 특성을 통해 이진 탐색으로 문제에 접근할 수 있다.
low = 0, high = max(Ti)로 정하고
low과 high의 중간값 mid로 합을 구했을 때

1. mid에서의 합이 M보다 작은 경우
- 그보다 큰 H들은 M을 충족시키지 못하므로 high 기준을 mid로 낮춘다.

2. mid에서의 합이 M보다 큰 경우
- 그보다 작은 H들은 mid에서의 합보다 크므로 low 기준을 mid로 높인다.
- 최대 높이인 H를 mid로 변경한다.

*/

long long sum_tree(vector<int> trees, int H) {
    int size = trees.size();
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        if (trees[i] > H) sum += trees[i] - H;
    }

    return sum;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;

    vector<int> trees(N);
    int low = 0, high = 0;
    int mid, H;
    long long sum;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        trees[i] = x;
        if (x >= high) high = x;
    }

    while (low <= high) {
        mid = (low + high) / 2;
        sum = sum_tree(trees, mid);
        if (sum >= M) {
            low = mid + 1;
            H = mid;
        }
        else {
            high = mid - 1;
        }
    }

    cout << H << "\n";

    return 0;
}