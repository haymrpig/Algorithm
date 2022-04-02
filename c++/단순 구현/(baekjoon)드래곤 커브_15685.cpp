#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0,-1, 0, 1};
int main() {
	int N;
	cin >> N;
	vector<vector<int>> board(101, vector<int>(101, 0));
	int min_x=101, min_y=101, max_x=0, max_y=0;

	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<int> order;
		int start_x, start_y, dir, len, flag=0;
		start_x = x;
		start_y = y;

		min_x = min(min_x, start_x);
		max_x = max(max_x, start_x);
		min_y = min(min_y, start_y);
		max_y = max(max_y, start_y);

		order.push_back(d);
		board[start_x][start_y] = 1;
		start_x += dx[d];
		start_y += dy[d];
		board[start_x][start_y] = 1;

		min_x = min(min_x, start_x);
		max_x = max(max_x, start_x);
		min_y = min(min_y, start_y);
		max_y = max(max_y, start_y);

		for(int i=0;i<g;i++) {
			len = order.size();
			for (int i = len-1; i >= 0; i--) {
				dir = order[i] == 3 ? 0 : order[i] + 1;
				start_x += dx[dir];
				start_y += dy[dir];
				if (start_x < 0 || start_y < 0 || start_x >= 101 || start_y >= 101) {
					flag = 1;
					break;
				}
				min_x = min(min_x, start_x);
				max_x = max(max_x, start_x);
				min_y = min(min_y, start_y);
				max_y = max(max_y, start_y);
				board[start_x][start_y] = 1;
				order.push_back(dir);
			}
			if (flag) break;
		}
	}
	int answer = 0;
	for (int i = min_x; i <= max_x; i++) {
		for (int j = min_y; j <= max_y; j++) {
			if (i >= 100 || j >= 100) continue;
			if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1) {
				answer++;
			}
		}
	}
	cout << answer << endl;
}