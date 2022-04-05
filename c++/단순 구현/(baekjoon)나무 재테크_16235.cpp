#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int N, M, K;
map<pair<int, int>, int> m;
int dx[8] = {-1,-1,-1,0,0,1,1,1 }, dy[8] = {-1,0,1,-1,1,-1,0,1};
void Spring(vector<vector<int>>& ground, vector<vector<vector<int>>>& trees) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (trees[i][j].size() == 0) continue;
			sort(trees[i][j].begin(), trees[i][j].end());
			int k;
			for (k = 0; k < trees[i][j].size(); k++) {
				int age = trees[i][j][k];
				if (ground[i][j] >= age) {
					ground[i][j] -= age;
					trees[i][j][k] += 1;
				}
				else break;
			}
			int total_age = 0;
			if (k != trees[i][j].size()) {
				for (int p = k; p < trees[i][j].size(); p++) {
					total_age += trees[i][j][p]/2;
				}
				trees[i][j].erase(trees[i][j].begin()+k, trees[i][j].end());
				m[{i, j}] = total_age;
			}
		}
	}
}

void Summer(vector<vector<int>>& ground) {
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		ground[iter->first.first][iter->first.second] += iter->second;
	}
	m.clear();
}

void Fall(vector<vector<vector<int>>>& trees) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (trees[i][j].size() == 0) continue;
			int k = 0;
			for (k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int p = 0; p < 8; p++) {
						int nx = i + dx[p];
						int ny = j + dy[p];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						trees[nx][ny].push_back(1);
					}
				}
			}	
		}
	}
}

void Winter(vector<vector<int>>& ground, vector<vector<int>>& A) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ground[i][j] += A[i][j];
		}
	}
}

int main() {
	cin >> N >> M >> K;
	vector<vector<int>> ground(N, vector<int>(N, 5));

	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	vector<vector<vector<int>>> trees(N, vector<vector<int>>(N));
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x-1][y-1].push_back(z);
	}
	
	while (K--) {
		Spring(ground, trees);
		Summer(ground);
		Fall(trees);
		Winter(ground, A);
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += trees[i][j].size();
		}
	}
	cout << answer << endl;
}