#include <iostream>
#include <vector>
#include <queue>
#define INF 2502
#define VIRUS 2503
using namespace std;

int N, M;
int ans = INF;
int total = 0;

void BFS(vector<vector<int>>& board, vector<pair<int, int>>& bomb_pos, vector<int>& hubo, int total) {
	queue<pair<int, int>> q;
	vector<vector<int>> Time(N, vector<int>(N, INF));
	for (int i = 0; i < hubo.size(); i++) {
		int idx = hubo[i];
		q.push({bomb_pos[idx].first,bomb_pos[idx].second } );
		Time[bomb_pos[idx].first][bomb_pos[idx].second] = 0;
	}
	int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
	int cnt = 0;
	int total_time = 0;
	while (!q.empty()) {
		int prex = q.front().first;
		int prey = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = prex + dx[i];
			int nexty = prey + dy[i];
			if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N || board[nextx][nexty] == -2) continue;
			if (Time[nextx][nexty] < Time[prex][prey]+1) continue;
			Time[nextx][nexty] = Time[prex][prey] + 1;
			if (board[nextx][nexty] == INF) {
				cnt++;
				total_time = Time[nextx][nexty];
			}
			q.push({nextx, nexty});
		}
	}
	cout << cnt << " " << total << endl;
	if (cnt == total) {
		ans = min(ans, total_time);
	}
}

void DFS(vector<vector<int>>& board, vector<pair<int, int>>& bomb, vector<int> hubo, int idx, int depth) {
	if (depth >= M) {
		BFS(board, bomb, hubo, total);
		return;
	}
	for (int i = idx; i < bomb.size(); i++) {
		vector<int> temp(hubo.begin(), hubo.end());
		
		temp.push_back(i);
		DFS(board, bomb, temp, i + 1, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<vector<int>> board(N, vector<int> (N));
	vector<pair<int, int>> bomb;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 2) {
				bomb.push_back({ i, j });
				board[i][j] = VIRUS; 
			}
			else if (temp == 1) {
				board[i][j] == -2; // º®
			}
			else {
				board[i][j] = INF;
				total++;
			}
		}
	}
	vector<int> hubo;
	
	DFS(board, bomb, hubo, 0, 0);

	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}