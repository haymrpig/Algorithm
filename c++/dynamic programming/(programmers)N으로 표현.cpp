#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
/*
    1. 모든 경우의 수를 모두 탐색하되, dp를 이용해서 다시 계산하는 과정을 줄일 수 있다.
    2. dp[i]는 i개의 숫자를 가지고 만들 수 있는 모든 계산값이다.
    3. dp[i]는 set으로 선언해주어 값의 중복을 없앴다.
    4. dp[i]에는 처음에 N, NN, NNN ....의 숫자를 먼저 넣어준다.
    5. dp[i]를 계산할 때, (dp[1],dp[i-1])....(dp[i-1],dp[i]) 이처럼 두 dp와의 연산을 처리해주어야 한다.
        -> 예를 들어 4개의 N을 이용한 값을 구할 때
        -> 1개를 이용한 경우 & 3개를 이용한 경우 사이 연산을 진행해야 한다.
        -> 2개를 이용한 경우 & 2개를 이용한 경우 사이 연산을 진행해야 한다.
        -> 3개를 이용한 경우 & 1개를 이용한 경우 사이 연산을 진행해야 한다.
        -------> 왜냐하면 예를 들어 5 / 555 와 555 / 5는 계산값이 다르기 때문이다.
*/
int solution(int N, int number) {
    int answer = -1;
    if (N == number) return 1;
    set<int> dp[9];
    for (int i = 1; i <= 8; i++) {
        int cnt = i;
        int num_temp = N;
        while (--cnt) {
            num_temp *= 10;
            num_temp += N;
        }
        dp[i].insert(num_temp);
    }
    for (int i = 2; i < 9; i++) {
        for (int j = 1; j < i; j++) {
            for (auto num : dp[j]) {
                for (auto num1 : dp[i - j]) {
                    dp[i].insert(num + num1);
                    dp[i].insert(num - num1);
                    dp[i].insert(num * num1);
                    if (num1 != 0) dp[i].insert(num / num1);
                }
            }
        }
        if (dp[i].find(number) != dp[i].end()) {
            return i;
        }
    }
    return answer;
}