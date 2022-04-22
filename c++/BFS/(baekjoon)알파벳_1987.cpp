#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int R, C;
	cin >> R >> C;

	vector<vector<int>> board(R,vector<int>(C));
	char alphabet;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> alphabet;
			board[i][j] = alphabet - 'A';
		}
	}

	int check = 0;
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0,0,1,-1 };
	queue<pair<int, pair<int, int>>> q;
	
	pair<int, int> start = {0,0};
	if ( (check | (1 << board[start.first][start.second])) != check) {
		check |= (1 << board[start.first][start.second]);
		q.push({ check, start });
	}
	while (!q.empty()) {
		int pc = q.front().first;
		int px = q.front().second.first;
		int py = q.front().second.second;
		check = pc;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && (pc | (1<<board[nx][ny])) != pc) {
				int nc = pc | (1<<board[nx][ny]);
				q.push({ nc, {nx,ny} });
			}
		}
	}
	
	int answer=0;
	for (int i = 0; i < 26; i++) {
		int num = (1 << i);
		if ((check & num) == num) answer++;
	}

	cout << answer;
	
}
