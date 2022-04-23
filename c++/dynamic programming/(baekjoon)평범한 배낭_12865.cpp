#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int W, V;
	vector<pair<int, int>> v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> W >> V;
		v[i] = { W,V };
	}

	vector<vector<int>> dp(N+1, vector<int>(K+1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j >= v[i].first) {
				dp[i][j] = max(dp[i - 1][j - v[i].first] + v[i].second, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
}