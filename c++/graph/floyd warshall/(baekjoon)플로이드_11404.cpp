#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> costs(n + 1, vector<int>(n + 1, INF));
	int a, b, c; 
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		costs[a][b] = min(costs[a][b], c);
	}

	for (int i = 1; i < n + 1; i++) {
		costs[i][i] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			for (int k = 1; k < n + 1; k++) {
				if (costs[j][i] + costs[i][k] < costs[j][k]) costs[j][k] = costs[j][i] + costs[i][k];
			}
		}
	}


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << (costs[i][j] == INF ? 0 : costs[i][j]) << " ";
		}
		cout << endl;
	}

}