#include <iostream>
#include <vector>
#include <map>
/*
*	- Logic
*	1. 단순 구현 문제로 조건에 맞게 간단하게 구현가능하다. 
*/
using namespace std;
int R, C, N;

void addTime(vector<vector<int>>& board, int time) {
	/**	Add 1 to all elements of board
	*		Bomb blows up after 3 seconds from the absolute time when it was placed.
	*		Bomber place bomb on empty space of board every 1 second, unless time is 0.
	*		So when time is 0 and board element is -1, which means no bomb, dont add 1 to it.
	*		
	* @param	board	Current status of bombs on board
	* @param	time		Current time spent from 0
	* @return	None
	*/
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (time == 0 && board[i][j] == -1) continue;
			board[i][j] += 1;
		}
	}
}


void updateBoard(vector<vector<int>>& board) {
	/**	Update current board state.
	*		Bomb blows up when 3 seconds passed from the time it was placed.
	*		Board element means the passed time of bomb, so if board element is 3, bomb has to be destroyed.
	*		And when the bomb explodes, nearby boms (up, down, left, right) explode together.
	*		At the first loop, find all bomb whose time is 3.
	*		At the second loop, destroy the bomb and its nearby bomb.
	*
	* @param	board	Current status of bombs on board
	* @return	None
	*		
	*/
	vector<vector<int>> check(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] >= 3) {
				check[i][j] = 1;
			}
		}
	}

	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (check[i][j] == 1) {
				board[i][j] = -1;
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
					board[ni][nj] = -1;
				}
			}
		}
	}
}
int main() {
	cin >> R >> C >> N;

	vector<vector<int>> board(R, vector<int>(C, -1));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char t;
			cin >> t;
			if (t == 'O') board[i][j] = 0;
		}
	}

	map<int, char> m;
	m[-1] = '.';
	m[0] = 'O';
	m[1] = 'O';
	m[2] = 'O';

	for (int i = 0; i < N; i++) {
		addTime(board, i);
		updateBoard(board);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << m[board[i][j]];
		}
		cout << "\n";
	}
}