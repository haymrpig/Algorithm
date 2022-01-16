#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
*	-Logic
*	1. dp�� �̿��Ͽ� Ǫ�� �����̴�. 
*	2. �տ��� �ڷ� ���� ���� �ƴ�, �ڿ��� ������ ����Ѵ�.
*	3. dp[i]�� i�Ͽ����� �ִ� ���� �ǹ��Ѵ�. 
*	4. i�Ͽ��� ����� �����Ͽ��� ��, ��� ������ ������ ���Ѵٸ�, i���� ����� �������� �ʱ⿡, i+1�Ͽ����� �ִ밪�� �״�� �����´�. 
*	5. ���� i�Ͽ����� ����� ������ �� ���� ��� ������ 2���� ����� ��
*			-> i�Ͽ��� ����� �����ϰ�,( i��+i�� ��� ���� �� )�϶��� dp��
*			-> i�Ͽ��� ����� �������� �ʴ´ٰ� �����ϸ�, i+1������ ���� �״�� �����´�. 
*			-> �� �� �� �� ū ���� dp[i]�� ����
*	6. dp[1]�� �ִ� ������ ���� �ȴ�. 
*/
int main() {
	int N;
	cin >> N;
	vector<int> dp(N + 2, 0);
	// dp[i][j] = i�� °, j���� ������ �� ���
	vector<pair<int, int>> v;
	
	for (int i = 0; i < N; i++) {
		int time, cost;
		cin >> time >> cost;
		v.push_back({ time, cost });
	}
	
	for (int i = N; i > 0; i--) {
		if (v[i - 1].first + i > N+1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[v[i - 1].first + i] + v[i - 1].second);
		}
	}
	cout << dp[1];


}