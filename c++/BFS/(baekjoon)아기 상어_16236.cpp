#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
*  1. 단순한 구현 문제였지만, 거리가 같은 경우를 구분하는 데에서 시간이 오래 걸렸다. 
*		-> 거리가 같은 경우 가장 위의 칸으로 이동
*		-> 거리가 같고 가장 위의 칸이 여러개일 경우 그 중 가장 왼쪽 선택
*		-> 처음에는 BFS 탐색시, 위, 왼쪽, 오른쪽, 아래로 탐색하는 경우로 해결이 될 줄 알았지만 좀 더 세부적으로 나눠줄 필요가 있었다. 
*		-> 0 0 9 0 1
*		-> 0 1 0 0 0
*		-> . . . . .
*		-> 이런 경우에 오른쪽 1로 가야하지만, 위의 탐색순으로 검사할 경우 왼쪽 아래 1을 먼저 찾게 된다. 
*		-> 따라서, 같은 depth이면서 여러개의 최단 거리를 찾은 경우 vector에 좌표들을 넣어주고 정렬하여 가장 위, 왼쪽 값을 찾도록 하였다. 
*/
using namespace std;
int N;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second < b.second) return true;
		else return false;
	}
	else return false;
}
int Search(vector<vector<int>>& info, pair<int,int>& cur, int size, int& cnt ) {
	queue<pair<int, int>> q;
	vector<vector<int>> visited(N, vector<int>(N, 0));
	visited[cur.first][cur.second] = 1;
	int dx[4] = { -1,0,0,1}, dy[4] = { 0,-1,1,0 };
	q.push(cur);
	int depth = 0;
	vector<pair<int, int>> hubo;
	while (!q.empty()) {
		int len = q.size();
		for (int j = 0; j < len; j++) {
			int pre_x = q.front().first;
			int pre_y = q.front().second;
			if (info[pre_x][pre_y]!= 0 && info[pre_x][pre_y] < size) {
				hubo.push_back({ pre_x, pre_y });
			}
			if (j == len - 1 && hubo.size()>0) {
				if( hubo.size()>1 )
					sort(hubo.begin(), hubo.end(), compare);
				cur.first = hubo[0].first;
				cur.second = hubo[0].second;
				info[cur.first][cur.second] = 0;
				cnt++;
				return depth;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = pre_x + dx[i];
				int next_y = pre_y + dy[i];
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && visited[next_x][next_y] == 0 && info[next_x][next_y] <= size ) {
					visited[next_x][next_y] = 1;
					q.push({ next_x, next_y });
				}
			}
		}
		depth++;
	}
	return -1;
}
int main() {
	cin >> N;
	vector<vector<int>> info(N, vector<int>(N));
	pair<int,int> cur;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> info[i][j];
			if (info[i][j] == 9) {
				info[i][j] = 0;
				cur = { i,j };
			}
		}
	}
	int size = 2;
	int cnt = 0;
	int answer = 0;
	while (1) {
		
		int temp_time = Search(info, cur, size, cnt);
		if (temp_time == -1) {
			cout << answer;
			return 0;
		}
		if (cnt == size) {
			size++;
			cnt = 0;
		}
		answer += temp_time;
		

		
	}

}