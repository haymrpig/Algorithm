#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, L, R;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
bool BFS(vector<vector<int>>& world, vector<vector<int>>& check, pair<int,int> cur) {
	int total = 0;
	int cnt = 0;
	vector<pair<int, int>> countries;
	queue<pair<int, int>> q;
	check[cur.first][cur.second] = 1;
	q.push(cur);
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		total += world[px][py];
		cnt += 1;
		countries.push_back({ px, py });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || check[nx][ny] == 1 || abs(world[px][py]-world[nx][ny]) < L || abs(world[px][py] - world[nx][ny]) > R) continue;
			q.push({ nx, ny });
			check[nx][ny] = 1;
		}
	}
	if (countries.size() > 1) {
		int num = int(total / cnt);
		for (pair<int, int> pos : countries) {
			world[pos.first][pos.second] = num;
		}
		return true;
	}
	else return false;
}
void move(vector<vector<int>>& world, bool& ifmoved) {
	vector<vector<int>> check(N, vector<int>(N, 0));
	ifmoved = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				ifmoved = (BFS(world, check, { i, j }) | ifmoved);
			}
		}
	}
}
int main() {
	cin >> N >> L >> R;
	vector<vector<int>> world(N, vector<int>(N));
	vector<vector<int>> open;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> world[i][j];
		}
	}
	int answer = 0;
	bool ifmoved = true;
	while (ifmoved) {
		move(world, ifmoved);
		answer++;
	}
	cout << answer-1;

}