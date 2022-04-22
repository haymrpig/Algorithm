#include <iostream>
#include <vector>
#include <queue>
#define INF 100000001
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int,int>>> info(N+1);
	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		info[start].push_back({ end,cost });
	}

	cin >> start >> end;

	vector<int> min_cost(N+1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, start });
	while (!pq.empty()) {
		int pc = pq.top().first;
		int pn = pq.top().second;
		if (pn == end) {
			cout << pc;
			return 0;
		}
		pq.pop();
		for (int i = 0; i < info[pn].size(); i++) {
			int nc = pc + info[pn][i].second;
			int nn = info[pn][i].first;
			if (min_cost[nn] > nc) {
				min_cost[nn] = nc;
				pq.push({ nc, nn });
			}
		}
	}
	cout << "impossible";
	return 0;

}