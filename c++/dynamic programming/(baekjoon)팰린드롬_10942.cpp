#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checkPelindrome(vector<int>& numbers, vector<vector<int>>& dp, int N, int start, int end) {
	if (start > end) {
		return 1;
	}
	if (dp[start][end] != -1) {
		return dp[start][end];
	}

	if (numbers[start] == numbers[end] && checkPelindrome(numbers, dp, N, start + 1, end - 1)) {
		dp[start][end] = 1;
		return 1;
	}
	
	dp[start][end] = 0;
	return 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> numbers(N+1);
	for (int i = 1; i < N+1; i++) {
		cin >> numbers[i];
	}

	vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
	for (int i = 1; i < N + 1; i++) {
		dp[i][i] = 1;	
	}

	int M;
	cin >> M;

	int a, b;
	while (M--) {
		cin >> a >> b;
		cout << checkPelindrome(numbers, dp, N, a, b) << '\n';
	}
}