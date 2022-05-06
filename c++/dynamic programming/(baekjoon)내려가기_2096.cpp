#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> board(2, vector<int>(3, -1));
	vector<vector<int>> dp_large(board);
	vector<vector<int>> dp_small(board);

	cin >> board[0][0] >> board[0][1] >> board[0][2];
	
	for(int i = 0; i < 3; i++) {
		dp_large[0][i] = board[0][i];
		dp_small[0][i] = board[0][i];
	}
	int k = 1;

	for (int i = 1; i < N; i++) {
		int j = i%2;
		cin >> board[j][0] >> board[j][1] >> board[j][2];

		dp_large[j][0] = max(dp_large[!j][0], dp_large[!j][1]) + board[j][0];
		dp_large[j][1] = max(dp_large[!j][0], max(dp_large[!j][1], dp_large[!j][2])) + board[j][1];
		dp_large[j][2] = max(dp_large[!j][1], dp_large[!j][2]) + board[j][2];

		dp_small[j][0] = min(dp_small[!j][0], dp_small[!j][1]) + board[j][0];
		dp_small[j][1] = min(dp_small[!j][0], min(dp_small[!j][1], dp_small[!j][2])) + board[j][1];
		dp_small[j][2] = min(dp_small[!j][1], dp_small[!j][2]) + board[j][2];
	}

	N = (N-1)%2;
	int large = max(dp_large[N][0], max(dp_large[N][1], dp_large[N][2]));
	int small = min(dp_small[N][0], min(dp_small[N][1], dp_small[N][2]));
	cout << large << " " << small;
}