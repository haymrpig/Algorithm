#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;
int main() {
	int village=0, road=0;
	cin >> village >> road;
	vector<vector<int>> dist(401, vector<int>(401, INF));
	for (int i = 1; i < 401; i++) dist[i][i] = 0;
	while (road--) {
		int start = 0, dest = 0, length = 0;
		cin >> start >> dest >> length;
		dist[start][dest] = length;
	}
	for (int i = 1; i <= village; i++) {
		// 거쳐가는 마을
		for (int j = 1; j <= village; j++) {
			// 시작 마을
			for (int k = 1; k <= village; k++) {
				// 끝 마을
				if (dist[j][k] > dist[j][i] + dist[i][k]) dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}
	/*
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= village; i++) {
		for (int j = 1; j <= village; j++) {
			if (i != j && dist[i][j] != INF && dist[j][i] != INF)
				pq.push(dist[i][j] + dist[j][i]);
		}
	}
	if (!pq.empty()) cout << pq.top() << '\n';
	else cout << -1 << '\n';
	*/
	int ans = INF;
	for (int i = 1; i <= village; i++) {
		for (int j = 1; j <= village; j++) {
			if (i == j) continue;
			ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}
	ans = ans == INF ? ans = -1 : ans;
	cout << ans << '\n';
	return 0;
}