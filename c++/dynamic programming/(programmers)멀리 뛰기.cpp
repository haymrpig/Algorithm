#include <string>
#include <vector>
#define MOD 1234567
/*
    ���� 11:55
    ���� 12:00
    - Logic
    1. dp�� �̿��ϴ� ���̽��� 1�� 2��ŭ�� �� �� �ֱ� ������, �ٷ� ����ĭ���� +1 �ٴ� ���� ��������ĭ���� +2 �ٴ� ���� ���� �� �ִ�.
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