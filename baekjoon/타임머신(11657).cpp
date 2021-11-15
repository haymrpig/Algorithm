#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;
int city, line;

int main() {
	cin >> city >> line;
	vector<pair<int, pair<int,int>>> info;
	while (line--) {
		int city1, city2, weight;
		cin >> city1 >> city2 >> weight;
		info.push_back(make_pair(weight, make_pair(city1, city2)));
	}
	vector<long long> dist(city+1, INF);
	dist[1] = 0;
	for (int i = 0; i < city - 1; i++) {
		for (int j = 0; j < info.size(); j++) {
			int weightTemp = info[j].first;
			int start = info[j].second.first;
			int dest = info[j].second.second;
			if (dist[start] != INF && dist[dest] > dist[start] + weightTemp)
				dist[dest] = dist[start] + weightTemp;
		}
	}
	for (int j = 0; j < info.size(); j++) {
		int weightTemp = info[j].first;
		int start = info[j].second.first;
		int dest = info[j].second.second;
		if (dist[start] != INF && dist[dest] > dist[start] + weightTemp) {
			cout << "-1" << endl;
			return 0;
		}
	}
	for (int i = 2; i < dist.size(); i++) {
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}

	return 0;
	/*
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	vector<int> dist(501, INF);
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int preweight = pq.top().first;
		int precity = pq.top().second;
		pq.pop();
		for (int i = 0; i < info[precity].size(); i++) {
			int weightSum = preweight + info[precity][i].second;
			int nextcity = info[precity][i].first;
			if (dist[nextcity] > weightSum) {
				pq.push({ weightSum, nextcity });
			}
		}
	}
	*/


}