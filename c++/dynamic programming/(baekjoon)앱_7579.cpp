#include <iostream>
#include <vector>
#include <algorithm>
#define LIMIT 10001
#define INF 10000001

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> memories(101);
	vector<int> costs(101);

	int memory, cost;
	for (int i = 1; i <= N; i++) {
		cin >> memories[i];
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> costs[i];
		sum += costs[i];
	}

	vector<vector<int>> dp(2, vector<int>(LIMIT, 0));
	int fake_idx;
	for (int i = 1; i <= N; i++) {
		fake_idx = i % 2;
		for (int j = 0; j <= sum; j++) {
			if (j - costs[i] >= 0) {
				dp[fake_idx][j] = max(dp[fake_idx][j], dp[!fake_idx][j - costs[i]] + memories[i]);
			}
			dp[fake_idx][j] = max(dp[fake_idx][j], dp[!fake_idx][j]);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[N % 2][i] >= M) {
			cout << i << endl;
			break;
		}
	}
}