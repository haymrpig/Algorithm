#include <iostream>
#include <vector>
#include <queue>
#define day true
#define night false
#define MAXNUM 1000001
using namespace std;
/*
*  -Logic
*	1. BFS로 탐색하는 간단한 문제이다. 
* 
*	!!!! 주의 !!!!!
*	1. 처음에 메모리 오류가 발생하였다. -> queue에 삽입하는 조건을 제대로 주지 않아 너무 많은 값이 들어가서 메모리초과 발생
*/
struct info {
	int x;
	int y;
	int wallBreak;
	bool isDay;
	int depth;
};

int main() {
	int M = 0, N = 0, K = 0;
	cin >> N >> M >> K;

	vector<string> map;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		map.push_back(temp);
	}

	info info_;
	queue<info> q;

	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K+1,0)));
	visited[0][0][0] = 1;
	q.push({ 0,0,0,day, 1 }); // x, y, K, day/night, depth
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	while (!q.empty()) {
		int px = q.front().x, py = q.front().y, preWallBreak = q.front().wallBreak, preDepth = q.front().depth;
		bool preIsDay = q.front().isDay;
		q.pop();
		if (px== N - 1 && py == M - 1) {
			cout << preDepth;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			bool nextIsDay = !preIsDay;
			int nx = px + dx[i], ny = py + dy[i];
			int nextDepth = preDepth + 1;
			int nextWallBreak = preWallBreak+1;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] == '1' && nextWallBreak <= K && !visited[nx][ny][nextWallBreak] ) {
				if (preIsDay == night) {
					nx = px;
					ny = py;
					nextWallBreak--;
					visited[nx][ny][nextWallBreak] = true;
				}
				else {
					visited[nx][ny][nextWallBreak] = true;
				}
				q.push({ nx, ny, nextWallBreak, nextIsDay, nextDepth });
			}
			else if (map[nx][ny] == '0' && !visited[nx][ny][preWallBreak]) {
				q.push({ nx, ny, preWallBreak, nextIsDay, nextDepth });
				visited[nx][ny][preWallBreak] = true;
			}
		}
	}
	cout << -1;
	return 0;
}