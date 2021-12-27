#include <iostream>
#include <vector>
#include <queue>
/*
*	- Logic
*	1. �ܼ� BFS�� �̿��ϴ� �����̴�.
* 
*	!!! ���� !!!
*	1. flag�� ���� �ν����� ��� ��� �ݺ��Ͽ���. 
*		-> flag�� false�� �ʱ�ȭ�ϰ� ||�� �̿��Ͽ� �ν����� false || true�� flag=true�� �ȴ�. 
*		-> ���⼭ �������� �߻�!!
*		-> flag = true�� �Ǹ� ���̻� || ���� ������ Ȯ������ �ʴ´�.
*		-> flag = flag || BreakBlock() ���ٷ� �ۼ��Ͽ����� ���� ������ Ȯ������ �ʴ� ��찡 ����� �Ǿ���.
*		-> �� �ٷ� ������ �ۼ����־���. 
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