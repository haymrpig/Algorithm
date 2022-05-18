#include <iostream>
#include <vector>

using namespace std;
int n;

int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> dp(501, vector<int>(501, 1));

int Search(vector<vector<int>>& forest, int x, int y) {
	if (dp[x][y] != 1) return dp[x][y];

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny<n && forest[nx][ny] > forest[x][y]) {
			sum = max(sum, Search(forest, nx, ny));
		}
	}
	if (sum != 0) dp[x][y] = sum + 1;
	return dp[x][y];
}

int main() {
	cin >> n;

	vector<vector<int>> forest(n, vector<int> (n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, Search(forest, i, j));
		}
	}
	cout << answer;
}