#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int answer;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = {0, 0, 1, -1};
int dp[50][50] = { -1, };
int DFS(vector<vector<int>>& visited, vector<vector<int>>& board, int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 0) {
		return 0;
	}
	if (visited[x][y] == 1) {
		cout << -1;
		exit(0);
	}
	if (dp[x][y] != -1) return dp[x][y];
	visited[x][y] = 1;
	dp[x][y] = 0;
	int num = board[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + num * dx[i];
		int ny = y + num * dy[i];
		dp[x][y] = max(dp[x][y], DFS(visited, board, nx, ny)+1 );
	}
	visited[x][y] = 0;
	return dp[x][y];
}

int main() {
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	vector<vector<int>> visited(N, vector<int>(M,0));
	memset(dp, -1, sizeof(dp));
	string check="";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check += '0';
			char temp;
			cin >> temp;
			if (temp == 'H') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = temp - '0';
			}
		}
	}
	queue<pair<string,pair<int, int>>> q;
	/*
	int depth = 1;
	check[0] = 1;
	q.push({ check,{ 0,0 } });
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			string pre_check = q.front().first;
			int px = q.front().second.first;
			int py = q.front().second.second;
			int num = board[px][py];
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = px + num * dx[i];
				int ny = py + num * dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny]!=0) {
					if (pre_check[nx*M+ny] == 1) {
						cout << -1;
						return 0;
					}
					check[nx*M+ny] = 1;
					q.push({ check, {nx, ny } });
				}
			}
		}
		depth++;
	}
	cout << depth-1;
	*/
	cout << DFS(visited, board, 0, 0);

	return 0;
}