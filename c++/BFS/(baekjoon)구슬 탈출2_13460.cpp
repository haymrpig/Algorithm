#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

struct Ball {
	int b_x, b_y;
	int r_x, r_y;
	Ball(int bx,int by,int rx,int ry) {
		b_x = bx;
		b_y = by;
		r_x = rx;
		r_y = ry;
	}
};

bool Move(vector<vector<char>>& origin, int &x, int &y, int dir, int& moved) {
	queue<pair<int, int>> q;

	q.push({x,y});
	int final_nx=x, final_ny=y;
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		final_nx = px;
		final_ny = py;
		q.pop();

		int nx = px + dx[dir];
		int ny = py + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || origin[nx][ny] == '#') continue;
		if (origin[nx][ny] == 'O') return true;
		
		q.push({ nx, ny });
	}

	moved = max(abs(final_nx - x), abs(final_ny - y));
	x = final_nx;
	y = final_ny;
	return false;
}

int main() {

	cin >> N >> M;

	vector<vector<char>> origin(N, vector<char>(M));
	int b_x, b_y;
	int r_x, r_y;
	int h_x, h_y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> origin[i][j];
			if (origin[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
			else if (origin[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (origin[i][j] == 'O') {
				h_x = i;
				h_y = j;
			}
		}
	}

	Ball* temp = new Ball(b_x, b_y, r_x, r_y);
	queue<pair<int,Ball*>> q;
	q.push({ 0,temp });
	while (!q.empty()) {
		int pre_trial = q.front().first;
		Ball* pre_state = q.front().second;
		if (pre_trial >= 10) {
			cout << -1;
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nb_x = pre_state->b_x;
			int nb_y = pre_state->b_y;
			int nr_x = pre_state->r_x;
			int nr_y = pre_state->r_y;
			int b_moved, r_moved;
			if (Move(origin,nb_x, nb_y, i, b_moved)) {
				continue;
			}
			if (Move(origin, nr_x, nr_y, i, r_moved)) {
				cout << pre_trial + 1;
				return 0;
			}
			if (b_moved == 0 && r_moved == 0) {
				continue;
			}

			if (nb_x == nr_x && nb_y == nr_y) {
				if (b_moved > r_moved) {
					nb_x -= dx[i];
					nb_y -= dy[i];
				}
				else {
					nr_x -= dx[i];
					nr_y -= dy[i];
				}
			}
			Ball* next = new Ball(nb_x, nb_y, nr_x, nr_y);
			q.push({ pre_trial + 1, next });
		}
	}
}