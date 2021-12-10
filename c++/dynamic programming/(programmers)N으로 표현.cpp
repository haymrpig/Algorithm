#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
/*
    1. ��� ����� ���� ��� Ž���ϵ�, dp�� �̿��ؼ� �ٽ� ����ϴ� ������ ���� �� �ִ�.
    2. dp[i]�� i���� ���ڸ� ������ ���� �� �ִ� ��� ��갪�̴�.
    3. dp[i]�� set���� �������־� ���� �ߺ��� ���ݴ�.
    4. dp[i]���� ó���� N, NN, NNN ....�� ���ڸ� ���� �־��ش�.
    5. dp[i]�� ����� ��, (dp[1],dp[i-1])....(dp[i-1],dp[i]) ��ó�� �� dp���� ������ ó�����־�� �Ѵ�.
        -> ���� ��� 4���� N�� �̿��� ���� ���� ��
        -> 1���� �̿��� ��� & 3���� �̿��� ��� ���� ������ �����ؾ� �Ѵ�.
        -> 2���� �̿��� ��� & 2���� �̿��� ��� ���� ������ �����ؾ� �Ѵ�.
        -> 3���� �̿��� ��� & 1���� �̿��� ��� ���� ������ �����ؾ� �Ѵ�.
        -------> �ֳ��ϸ� ���� ��� 5 / 555 �� 555 / 5�� ��갪�� �ٸ��� �����̴�.
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