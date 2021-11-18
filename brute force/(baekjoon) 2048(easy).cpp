#include <iostream>
#include <vector>
#include <deque>
#define L 0
#define R 1
#define U 2
#define D 3
/*
*	- Logic
*	1. 브루트 포스로 모든 경우의 수를 탐색한다. 
*	2. 시중 게임과 다르게 한번 시행에서 숫자가 한번 합쳐지면 그 숫자는 인접한 숫자와 같더라도 합쳐지지 않는다. 
*/
using namespace std;
int N = 0;
int maxNum;
void move(vector<vector<int>>& board, int depth, int maxTemp=0 ) {
	if (depth == 5) {
		maxNum = max(maxNum, maxTemp);
		return;
	}
	vector<vector<int>> boardCopy(board.begin(), board.end());
	for (int i = 0; i < 4; i++) {
		boardCopy = board;
		int maxTemp = 0;
		bool jump = false;
		for (int j = 0; j < N; j++) {
			deque<int> dq;
			int num=0;
			for (int k = 0;k<N; k++) {
				if (i == L) {
					num = boardCopy[j][k];
				}
				else if (i == R) {
					num = boardCopy[j][N-k-1];
				}
				else if (i == U) {
					num = boardCopy[k][j];
				}
				else {
					num = boardCopy[N - k - 1][j];
				}
				if (num == 0) continue;
				if (!dq.empty() && dq.back() == num && jump == false) {
					dq.pop_back();
					num *= 2;
					jump = true;
				}
				else {
					jump = false;
				}
				dq.push_back(num);
			}
			for (int k = 0; k < N; k++) {
				num = 0;
				if (!dq.empty()) {
					num = dq.front();
					dq.pop_front();
					if (depth == 4) {
						maxTemp = max(maxTemp, num);
					}
				}
				if (i == L) {
					boardCopy[j][k]=num;
				}
				else if (i == R) {
					boardCopy[j][N - k - 1]=num;
				}
				else if (i ==U) {
					boardCopy[k][j]=num;
				}
				else {
					boardCopy[N - k - 1][j]=num;
				}
			}
		}
		
		
		move(boardCopy, depth+1, maxTemp);
		boardCopy = board;
	}
}
int main() {
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	move(board, 0);
	cout << maxNum;

}