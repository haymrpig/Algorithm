#include <iostream>
#include <vector>

/*
*	-Logic
*	1. �ܼ� ���� ����������, ������ �������� ���� ��ٷӴ�. 
*	2. ��� ��, ���� �˻��� ��, 0��° index���� �����Ѵ�. 
*	3. ���� ���� index�� ���̰� ���� index�� �ٸ� ��� ���ΰ� �ʿ��ϴ�. 
*		-> ���� ���� ���̰� �� ����, ���̰� 1�̶�� �� ���� L��ŭ�� ���̰� ������ Ȯ���Ѵ�. (���δ� �׻� ���̰� 1, �ٴڿ� �پ��־�� �Ѵ�.)
*		-> �ݴ��̸� �� ���� L��ŭ�� ���̰� ������ Ȯ��
*		-> �׷��� ������ break
*	4. ���� ������ index���� ������ ���� answer+1
* 
*	!!! ���� !!!
*	1. L=2�� ���, 3 2 2 3 3 �� �� �� ���� �Ұ����ϴ�. ������ ���� �˰��� ��ζ�� �����ϴ�.
*		-> �������� ���θ� ��ġ�ϰ�, �ߺ����� �������� ���θ� ��ġ������
*		-> ����, ���θ� ��ġ������ visited=1�� ǥ�ø� ���־� �ߺ��� �����Ͽ���. 
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