#include <iostream>
#include <vector>

using namespace std;
int N;
void rev(vector<vector<bool>>& board, int row) {
	for (int i = 0; i < N; i++) board[row][i] = !board[row][i];
	// �ش� row�� ���� ��Ų��. 
}

int main() {
	cin >> N;
	int flip_flag = (1 << N) - 1;
	// �� bit�� ������ row�� �ǹ��ϰ�, 
	// bit�� 1�� ���, flip ���شٴ� �ǹ��̴�. 

	vector<vector<bool>> board_origin(N, vector<bool>(N, false));
	int answer = 0;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			if (temp[j] == 'H') board_origin[i][j] = true;
			else answer += 1;
		}
	}
	// �ո��� true, �޸��� false
	// �ʱ� �޸� ������ answer�� ����
	
	vector<vector<bool>> board(board_origin.begin(), board_origin.end());
	for (int flip = flip_flag;flip>=0 ; flip -= 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = board_origin[i][j];
			}
		}
		// board �ʱ�ȭ �κ�

		int answer_temp = 0;
		for (int i=0; i < N; i++) {
			int check = (1 << i);
			if ((check & flip) == check) rev(board, i);
		}
		// row ������

		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (!board[j][i]) cnt++;
			}
			// column�� �޸� ���� üũ

			if (cnt * 2 > N) {
				// �޸��� ������ �ո麸�� ���� ���
				answer_temp += N - cnt;
			}
			else answer_temp += cnt;
		}

		answer = min(answer, answer_temp);
	}
	cout << answer << endl;
}