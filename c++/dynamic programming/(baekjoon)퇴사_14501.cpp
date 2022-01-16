#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
*	-Logic
*	1. dp를 이용하여 푸는 문제이다. 
*	2. 앞에서 뒤로 가는 것이 아닌, 뒤에서 앞으로 계산한다.
*	3. dp[i]는 i일에서의 최대 값을 의미한다. 
*	4. i일에서 상담을 진행하였을 때, 퇴사 전까지 끝내지 못한다면, i일의 상담을 진행하지 않기에, i+1일에서의 최대값을 그대로 가져온다. 
*	5. 만약 i일에서의 상담이 진행할 수 있을 경우 가능한 2가지 경우의 수
*			-> i일에서 상담을 진행하고,( i일+i일 상담 지속 일 )일때의 dp값
*			-> i일에서 상담을 진행하지 않는다고 가정하면, i+1에서의 값을 그대로 가져온다. 
*			-> 위 두 값 중 큰 값을 dp[i]에 저장
*	6. dp[1]이 최대 가능한 값이 된다. 
*/
int main() {
	int N;
	cin >> N;
	vector<int> dp(N + 2, 0);
	// dp[i][j] = i일 째, j일을 이전에 고른 경우
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