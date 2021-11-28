#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;
/*
int money, airport;
void findRoute(int index, vector<pair<int, pair<int, int>>> info[101], vector<int>& visited, int& totalCost, int& totaltime, priority_queue<int>& pq) {
	if (totalCost <= money && index == airport) {
		pq.push(totaltime);
		return;
	}
	else if (totalCost > money) return;
	else {
		for (int i = 0; i < info[index].size(); i++) {
			int nextIndex = info[index][i].first;
			int cost = info[index][i].second.first;
			int time = info[index][i].second.second;
			if (visited[nextIndex] == 0) {
				visited[nextIndex] = 1;
				totalCost += cost;
				totaltime += time;
				findRoute(nextIndex, info, visited, totalCost, totaltime, pq);
				visited[index] = 0;
			}
		}
	}
}
int main() {
	int testCase;
	cin >> testCase;

	while (testCase--) {
		int ticket = 0;
		cin >> airport >> money >> ticket;
		vector<pair<int, pair<int, int>>> info[101];
		while (ticket--) {
			int start = 0, dest = 0, value = 0, time = 0;
			cin >> start >> dest >> value >> time;
			info[start].push_back({ dest, {value, time} });
		}
		vector<pair<int, int>> d(airport + 1);
		vector<int> visited(airport + 1, 0);
		visited[1] = 1;
		priority_queue<int> pq;
		int totalTime = 0;
		int totalCost = 0;
		findRoute(1, info, visited, totalCost, totalTime, pq);
		if (!pq.empty()) cout << pq.top()<< '\n'; 
		else cout << "Poor KCM"<< '\n';
	}
}
*/
int main() {
	int testCase;
	cin >> testCase;

	while (testCase--) {
		int airport=0, money=0, ticket = 0;
		cin >> airport >> money >> ticket;
		vector<pair<int, pair<int, int>>> info[101];
		while (ticket--) {
			int start = 0, dest = 0, value = 0, time = 0;
			cin >> start >> dest >> value >> time;
			info[start].push_back({ dest, {value, time} });
		}
		
		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		vector<vector<int>> d(101, vector<int>(10001, INF));
		d[1][0] = 0;
		pq.push({ 0, {1, 0} }); // time, dest, value
		while (!pq.empty()) {
			int preTime = pq.top().first;
			int preAirport = pq.top().second.first;
			int preValue = pq.top().second.second;
			pq.pop();
			for (int i = 0; i < info[preAirport].size(); i++) {
				int nextAirport = info[preAirport][i].first;
				int nextTime = info[preAirport][i].second.second;
				int nextValue = info[preAirport][i].second.first;
				int sumValue = preValue + nextValue;
				if ( sumValue > money ) continue;
				if (d[nextAirport][sumValue] > d[preAirport][preValue] + nextTime) {
					d[nextAirport][sumValue] = d[preAirport][preValue] + nextTime;
					pq.push({ d[nextAirport][sumValue], {nextAirport, sumValue} });
				}
			}
		}
		int min = INF;
		for (int i = 0; i < d[airport].size(); i++) {
			if (d[airport][i] == INF) continue;
			if (min > d[airport][i]) min = d[airport][i];
		}
		if (min == INF) cout << "Poor KCM" << '\n';
		else cout << min << '\n';
	}
}