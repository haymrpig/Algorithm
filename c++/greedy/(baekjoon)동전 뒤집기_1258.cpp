#include <iostream>
#include <vector>

using namespace std;
int N;
void rev(vector<vector<bool>>& board, int row) {
	for (int i = 0; i < N; i++) board[row][i] = !board[row][i];
	// 해당 row를 반전 시킨다. 
}

int main() {
	cin >> N;
	int flip_flag = (1 << N) - 1;
	// 각 bit가 각각의 row를 의미하고, 
	// bit가 1일 경우, flip 해준다는 의미이다. 

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
	// 앞면은 true, 뒷면을 false
	// 초기 뒷면 개수를 answer에 저장
	
	vector<vector<bool>> board(board_origin.begin(), board_origin.end());
	for (int flip = flip_flag;flip>=0 ; flip -= 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = board_origin[i][j];
			}
		}
		// board 초기화 부분

		int answer_temp = 0;
		for (int i=0; i < N; i++) {
			int check = (1 << i);
			if ((check & flip) == check) rev(board, i);
		}
		// row 뒤집기

		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (!board[j][i]) cnt++;
			}
			// column의 뒷면 개수 체크

			if (cnt * 2 > N) {
				// 뒷면의 개수가 앞면보다 많을 경우
				answer_temp += N - cnt;
			}
			else answer_temp += cnt;
		}

		answer = min(answer, answer_temp);
	}
	cout << answer << endl;
}