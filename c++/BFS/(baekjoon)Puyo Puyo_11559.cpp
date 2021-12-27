#include <iostream>
#include <vector>
#include <queue>
/*
*	- Logic
*	1. 단순 BFS를 이용하는 문제이다.
* 
*	!!! 주의 !!!
*	1. flag를 세워 부숴지는 경우 계속 반복하였다. 
*		-> flag를 false로 초기화하고 ||를 이용하여 부숴지면 false || true로 flag=true가 된다. 
*		-> 여기서 문제점이 발생!!
*		-> flag = true가 되면 더이상 || 뒤의 조건을 확인하지 않는다.
*		-> flag = flag || BreakBlock() 한줄로 작성하였더니 뒤의 조건을 확인하지 않는 경우가 생기게 되었다.
*		-> 두 줄로 나눠서 작성해주었다. 
*	
*/

using namespace std;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int answer = 0;
bool BreakBlock(vector<vector<char>>& board, int x, int y) {
	char alphabet = board[x][y];
	vector<vector<char>> visited(board.begin(), board.end());
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = '.';
	int cnt = 0;
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && visited[nx][ny] == alphabet  ) {
				q.push({ nx,ny });
				visited[nx][ny] = '.';
			}
		}
	}
	if (cnt >= 4) {
		board = visited;
		return true;
	}
	else return false;
}

void ClearBlocks(vector<vector<char>>& board) {
	for (int i = 0; i < 6; i++) {
		int start = 11;
		int end = start-1;
		while (end >= 0) {
			if (board[start][i] == '.') {
				while (end >= 0 && board[end][i] == '.') {
					end--;
				}
				if (end >= 0) {
					board[start][i] = board[end][i];
					board[end][i] = '.';
				}
				start--;
			}
			else {
				start--;
				end=start - 1;
			}
		}
	}
	return;
}

int main(int* argc, char** argv) {
	vector<vector<char>> board(12, vector<char>(6));
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.') {
					bool temp = BreakBlock(board, i, j);
					flag = flag || temp;
				}
			}
		}

		ClearBlocks(board);
		if (flag) answer++;
		
	}
	cout << answer;
}