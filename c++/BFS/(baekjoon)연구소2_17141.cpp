#include <iostream>
#include <vector>
#include <queue>
#define INF 25000
/*
*  1. �������� virus�� ���� �� �ִ� ��ġ�� �������� �����ؾ� �ߴµ�, �׷��� ���Ͽ� �ð��� ���� �����.
*  2. DFS�� �̿��Ͽ� ������ ������ ���ϰ�, �� ���տ� ���� BFS�� �̿��Ͽ� �ɸ��� �ð��� �����Ͽ���. 
*/
using namespace std;
int N, M;
int num_zero = 0;
int answer = INF;
void DFS(vector<vector<int>>& info, vector<pair<int, int>>& virus, vector<int> check, int index,  int depth) {
	if (depth == M) {
		queue<pair<int, int>> q;
		vector<vector<int>> visited(N, vector<int>(N, 0));
		int zeros = 0;
		for (int i = 0; i < check.size(); i++) {
			if (check[i] == 1) {
				q.push(virus[i]);
				visited[virus[i].first][virus[i].second] = 1;
				zeros++;
			}
		}
		int time = 0;
		int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
		while (!q.empty()) {
			int len = q.size();
			for (int i = 0; i < len; i++) {
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				for (int j = 0; j < 4; j++) {
					int nx = px + dx[j];
					int ny = py + dy[j];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0 && info[nx][ny] != 1) {
						visited[nx][ny] = 1;
						zeros++;
						q.push({ nx,ny });
					}
				}
			}
			time++;
		}

		if (zeros == num_zero) {
			answer = min(answer, time-1);
		}
		return;
	}
	for (int i = index; i < virus.size(); i++) {
		check[i] = 1;
		DFS(info, virus, check, i + 1, depth + 1);
		check[i] = 0;
	}
}
int main() {
	cin >> N >> M;
	vector<vector<int>> info(N, vector<int>(N));
	vector<pair<int, int>> virus;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> info[i][j];
			if (info[i][j] == 2) {
				virus.push_back({ i,j });
				num_zero++;
			}
			else if( info[i][j]== 0) num_zero++;
		}
	}

	vector<int> check(virus.size(), 0);
	DFS(info, virus, check, 0, 0);
	answer = answer == INF ? -1 : answer;
	cout << answer;
	return 0;
}