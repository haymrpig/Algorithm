#include <iostream>
#include <vector>
#include <queue>
/* 
*  1. BFS를 이용하여 외곽 공기를 모두 0 -> 2로 바꿔주었다. 
*/
using namespace std;
int N, M;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
void Check(vector<vector<int>>& info,int x, int y, int from, int to) {
	queue<pair<int, int>> q;
	info[x][y] = to;
	q.push({ x,y });
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && info[nx][ny] == from) {
				info[nx][ny] = to;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> N >> M;
	vector<vector<int>> info(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> info[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ( (i == 0 || i == N-1 || j == 0 || j == M-1 ) && info[i][j] == 0) {
				Check(info, i, j, 0, 2);
			}
		}
	}
	int time = 0;
	while (1) {
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (info[i][j] == 1) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (info[x][y] == 2) cnt++;
					}
					if (cnt >= 2) {
						v.push_back({ i,j });
					}
				}
			}
		}
		if (v.size() < 1) {
			cout << time;
			return 0;
		}
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			info[x][y] = 0;
		}
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			if( info[x][y] == 0)
				Check(info, x, y, 0, 2);
		}
		time++;
	}
	
}