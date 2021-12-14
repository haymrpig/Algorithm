#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int answer = 1000000;
/*
*  1. BFS를 이용하여 같은 땅끼리 같은 번호를 매겨준다. 
*  2. 땅과 땅을 연결할때도 BFS를 통해 최단 거리를 모든 땅에 대해서 검사해준다. 
*/
void Find(vector<vector<int>>&map, int N, int start) {
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	queue <pair<int, int>> q1;
	vector<vector<int>> visited(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == start) {
				q1.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	int dist = 0;
	while (!q1.empty()) {
		int s = q1.size();
		for (int i = 0; i < s; i++) {
			int px = q1.front().first;
			int py = q1.front().second;
			q1.pop();
			
			for (int k = 0; k < 4; k++) {
				int nx = px + dx[k];
				int ny = py + dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N){
					if (map[nx][ny] != 0 && map[nx][ny] != start) {
						answer = min(answer, dist);
						return;
					}
					else if (map[nx][ny] == 0 && visited[nx][ny] == 0) {
						visited[nx][ny] = 1;
						q1.push({ nx,ny });
					}
				}
			}
		}
		dist++;
	}
	
}
int main() {
	int N;
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> q;
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	int index = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				index++;
				map[i][j] = index;
				q.push({ i,j });
				while (!q.empty()) {
					int px = q.front().first;
					int py = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = px + dx[k];
						int ny = py + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] == 1) {
							q.push({ nx,ny });
							map[nx][ny] = index;
						}
					}
				}
			}
		}
	}
	for (int i = 2; i <= index; i++) {
		Find(map, N, i);
	}
	cout << answer;
}