#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*
문제
FizzBuzz 문제는 
$i = 1, 2, ...에 대해 다음 규칙에 따라 문자열을 한 줄에 하나씩 출력하는 문제입니다.

$i$가 $3$의 배수이면서 $5$의 배수이면 “FizzBuzz”를 출력합니다.
$i$가 $3$의 배수이지만 $5$의 배수가 아니면 “Fizz”를 출력합니다.
$i$가 $3$의 배수가 아니지만 $5$의 배수이면 “Buzz”를 출력합니다.
$i$가 $3$의 배수도 아니고 $5$의 배수도 아닌 경우 $i$를 그대로 출력합니다.

FizzBuzz 문제에서 연속으로 출력된 세 개의 문자열이 주어집니다. 이때, 이 세 문자열 다음에 올 문자열은 무엇일까요?

입력
FizzBuzz 문제에서 연속으로 출력된 세 개의 문자열이 한 줄에 하나씩 주어집니다. 각 문자열의 길이는 
$8$ 이하입니다. 입력이 항상 FizzBuzz 문제에서 연속으로 출력된 세 개의 문자열에 대응됨이 보장됩니다.

출력
연속으로 출력된 세 개의 문자열 다음에 올 문자열을 출력하세요. 여러 문자열이 올 수 있는 경우, 아무거나 하나 출력하세요.

*/

#define FZ "Fizz"
#define BZ "Buzz"
#define FZBZ "FizzBuzz"

int main(int argc, char **argv) {

    string in;
    string last = "";
    int last_n = 0;
    for (int i = 3; i > 0; i--) {
        cin >> in;
        if (isdigit(in[0])) {
            last_n = stoi(in) + i;
            break;
        }
    }

    if (last_n % 3 == 0) {
        last.append(FZ);
    }
    if (last_n % 5 == 0) {
        last.append(BZ);
    }
    
    if (last.length() == 0) {
        last = to_string(last_n);
    }

    printf("%s", last.c_str());

    return 0;
}