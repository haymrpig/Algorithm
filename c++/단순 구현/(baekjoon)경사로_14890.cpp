#include <iostream>
#include <vector>

/*
*	-Logic
*	1. 단순 구현 문제이지만, 조건이 여러개라 조금 까다롭다. 
*	2. 모든 열, 행을 검사할 때, 0번째 index부터 시작한다. 
*	3. 만약 다음 index의 높이가 이전 index와 다를 경우 경사로가 필요하다. 
*		-> 만약 이전 높이가 더 높고, 차이가 1이라면 그 다음 L만큼의 높이가 같은지 확인한다. (경사로는 항상 높이가 1, 바닥에 붙어있어야 한다.)
*		-> 반대이면 그 이전 L만큼의 높이가 같은지 확인
*		-> 그렇지 않으면 break
*	4. 만약 마지막 index까지 루프가 돌면 answer+1
* 
*	!!! 주의 !!!
*	1. L=2일 경우, 3 2 2 3 3 일 때 이 경우는 불가능하다. 하지만 위의 알고리즘 대로라면 가능하다.
*		-> 높아지는 경사로를 설치하고, 중복으로 낮아지는 경사로를 설치함으로
*		-> 따라서, 경사로를 설치했으면 visited=1로 표시를 해주어 중복을 제거하였다. 
*/
using namespace std;

void Rotate(vector<vector<int>>& board, int N) {
	vector<vector<int>> temp(board.begin(), board.end());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[j][N-i-1] = temp[i][j];
		}
	}
}
int main() {
	int N, L;
	cin >> N >> L;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int answer = 0;
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < N; i++) {
			vector<int> visited(N, 0);
			int ph = board[i][0];
			int cur = 1;
			while (1) {
				if (cur >= N) {
					answer++;
					break;
				}
				if (board[i][cur] == ph) cur++;
				else if (board[i][cur] < ph && board[i][cur] +1 == ph) {
					int j;
					for (j = 0; j < L; j++) {
						if (cur + j >= N || board[i][cur + j] != board[i][cur]) break;
						visited[cur + j] = 1;
					}
					if (j != L) break;
					else {
						ph = board[i][cur + j - 1];
						cur += j;
					}
				}
				else if (board[i][cur] > ph && ph + 1 == board[i][cur]) {
					int j;
					for (j = 1; j <= L; j++) {
						if (cur - j < 0 || visited[cur - j] == 1 || board[i][cur - j] != ph) break;
					}
					if (j != L + 1) break;
					else {
						ph = board[i][cur];
						cur++;
					}
				}
				else break;
			}
		}
		Rotate(board, N);
	}
	cout << answer << endl;
}