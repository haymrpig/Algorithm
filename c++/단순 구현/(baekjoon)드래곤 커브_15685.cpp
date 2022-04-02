#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0,-1, 0, 1};
int main() {
	int N;
	cin >> N;
	vector<vector<int>> board(101, vector<int>(101, 0));
	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		
		vector<int> order;
		int start_x, start_y, dir, len, flag=0;
		start_x = x;
		start_y = y;
		order.push_back(d);
		board[start_x][start_y] = 1;
		start_x += dx[d];
		start_y += dy[d];
		board[start_x][start_y] = 1;
		for(int i=0;i<g;i++) {
			len = order.size();
			for (int i = len-1; i >= 0; i--) {
				dir = order[i] == 3 ? 0 : order[i] + 1;
				start_x += dx[dir];
				start_y += dy[dir];
				if (start_x < 0 || start_y < 0 || start_x >= 100 || start_y >= 100) {
					flag = 1;
					break;
				}
				board[start_x][start_y] = 1;
				order.push_back(dir);
			}
			if (flag) break;
		}
	}
	

}