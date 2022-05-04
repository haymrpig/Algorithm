#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int M, N;
int DFS(vector<vector<int>>& m, vector<vector<int>> &visited, vector<vector<int>>& dp, int x, int y) {
	if (x == M - 1 && y == N - 1) {
		return 1;
	}
	if (dp[x][y] != -1) return dp[x][y];
	
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && visited[nx][ny]==0 && m[nx][ny] < m[x][y]) {
			visited[nx][ny] = 1;
			sum += DFS(m, visited, dp, nx, ny);
			visited[nx][ny] = 0;
		}
	}
	dp[x][y] = sum;
	return dp[x][y];
}
int main() {
	cin >> M >> N;

	vector<vector<int>> m(M, vector<int>(N, 0));
	vector<vector<int>> dp(m);
	vector<vector<int>> visited(m);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(m, visited, dp, 0, 0);

}