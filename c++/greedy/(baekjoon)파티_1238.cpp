#include <iostream>
#include <vector>
#define INF 100000000
/*
*  1. dijkstra �˰��� �̿��Ͽ� ��� ���� �ִ� �Ÿ��� ���
*  2. ��� �л� ���� ��ġ���� X���� + X���� ��� �л��� ���� ��ġ �� ���� ū �� ���
*/
using namespace std;

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<int>> info(N+1, vector<int> (N+1,INF));
	for (int i = 0; i < N + 1; i++) {
		info[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		info[start][end] = weight;
	}

	for (int k = 1; k < N + 1; k++) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1;j++) {
				if (info[i][j] > info[i][k] + info[k][j]) info[i][j] = info[i][k] + info[k][j];
			}
		}
	}
	int max_time = 0;
	for (int i = 1; i < N + 1; i++) {
		max_time = max(max_time, info[i][X] + info[X][i]);
	}
	cout << max_time;
}