#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	else return false;
}
void Rcal(vector<vector<int>>& board, int& row, int& col) {
	int temp_col = 0;
	for (int i = 0; i < row; i++) {
		unordered_map<int, int> m;
		for (int j = 0; j < col; j++) {
			if (board[i][j] == 0) continue;
			m[board[i][j]]++;
			board[i][j] = 0;
		}
		vector<pair<int, int>> r;
		int cnt = 0;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			r.push_back({ iter->first, iter->second });
			cnt++;
		}
		sort(r.begin(), r.end(), compare);
		for (int j = 0; j < cnt; j++) {
			if (j >= 100) break;
			board[i][2*j] = r[j].first;
			board[i][2*j + 1] = r[j].second;
		}
		temp_col = max(2*cnt, temp_col);
	}
	col = temp_col;
	return;
}

void Ccal(vector<vector<int>>& board, int& row, int& col) {
	int temp_row = 0;
	for (int i = 0; i < col; i++) {
		unordered_map<int, int> m;
		for (int j = 0; j < row; j++) {
			if (board[j][i] == 0) continue;
			m[board[j][i]]++;
			board[j][i] = 0;
		}
		vector<pair<int, int>> r;
		int cnt = 0;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			r.push_back({ iter->first, iter->second });
			cnt++;
		}
		sort(r.begin(), r.end(), compare);
		for (int j = 0; j < cnt; j++) {
			if (j >= 100) break;
			board[2*j][i] = r[j].first;
			board[2*j+1][i] = r[j].second;
		}
		temp_row = max(2*cnt, temp_row);
	}
	row = temp_row;
	return;
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;

	vector<vector<int>> board(100, vector<int> (100,0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];
		}
	}

	int num_row = 3;
	int num_col = 3;

	int time = 0;
	while (time < 101) {


		if (board[r - 1][c - 1] == k) break;
		if (num_row >= num_col) {
			Rcal(board, num_row, num_col);
		}
		else {
			Ccal(board, num_row, num_col);
		}
		time++;
	}
	if (time == 101) cout << -1;
	else cout << time;

}