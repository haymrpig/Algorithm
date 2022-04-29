#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector<vector<long long>> dp(n, vector<long long>(21, 0));
	dp[0][nums[0]] = 1;
	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				if (j + nums[i] <= 20) dp[i][j + nums[i]] += dp[i-1][j];
				if (j - nums[i] >= 0) dp[i][j - nums[i]] += dp[i-1][j];
			}
		}
	}

	cout << dp[n-2][nums[n - 1]];

}