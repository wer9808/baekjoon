#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.
*/

/*
아래층에 있는 수는 현재 층에서 선택된 수의 왼쪽 또는 오른쪽에서만 선택
반대로 각 칸의 최대값은 현재 칸 위층의 대각선 왼쪽 또는 오른쪽 중 최대값에 현재 칸의 값을 더한 것
예를 들어 2층 2칸은 1층 1칸 또는 1층 2칸 최대값 중 더 큰 값에 2층 2칸 값을 더한 값이 된다.
따라서 i층 j칸의 최대값 M(i,j) = max(M(i-1,j-1),M(i-1,j)) + V(i,j)가 된다.
이 때, j-1이 0보다 작거나 j가 i-1의 최대 칸을 넘어가는지 확인해야 한다.
*/

int main(int argc, char **argv) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int **v = new int*[n];
    int **M = new int*[n];
    int max = 0;

    for (int i = 0; i < n; i++) {
        v[i] = new int[i + 1];
        M[i] = new int[i + 1];
        for (int j = 0; j < i + 1; j++) {
            cin >> v[i][j];
            M[i][j] = 0;
        }
    }

    M[0][0] = v[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            int x = 0, y = 0;
            if (j - 1 >= 0) {
                x = M[i - 1][j - 1];
            }
            if (j < i) {
                y = M[i - 1][j];
            }
            M[i][j] = x > y ? x + v[i][j] : y + v[i][j];
            max = M[i][j] > max ? M[i][j] : max;
        }
    }

    cout << max << '\n';

    return 0;
}