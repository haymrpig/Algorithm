#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
int main() {
	int V;
	int E;
	int start;
	cin >> V >> E;
	cin >> start;
	vector<pair<int, int>> info[20001];
	vector<int> dist(20001,INF);
	while (E--) {
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		info[node1].push_back({ node2,weight });
		//info[node2].push_back({ node1,weight });
	}
	dist[start] = 0;
	
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

	pq.push({ 0,start });
	while (!pq.empty()) {
		int index = pq.top().second;
		int weightTemp = pq.top().first;
		pq.pop();
		for (int i = 0; i < info[index].size(); i++) {
			int indexNext = info[index][i].first;
			int weightNext = info[index][i].second;
			int weightSum = weightNext + weightTemp;
			if (dist[indexNext] > weightSum) {
				pq.push({ weightSum, indexNext});
				dist[indexNext] = weightSum;
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) cout << dist[i] << "\n";
		else cout << "INF" << "\n";
	}
}