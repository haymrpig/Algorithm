#include <string>
#include <vector>
#define MOD 1234567
/*
    시작 11:55
    종료 12:00
    - Logic
    1. dp를 이용하는 케이스로 1과 2만큼만 뛸 수 있기 때문에, 바로 이전칸에서 +1 뛰는 경우와 이전이전칸에서 +2 뛰는 경우로 나눌 수 있다.
*/
using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    answer = dp[n];
    return answer;
}