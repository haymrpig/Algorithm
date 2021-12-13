#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second > b.second) return true;
		else return false;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> jewelry;
	vector<int> bag;
	for (int i = 0; i < N; i++) {
		int weight, cost;
		cin >> weight >> cost;
		jewelry.push_back({ weight, cost });
	}
	sort(jewelry.begin(), jewelry.end(), compare);
	
	for (int i = 0; i < K; i++) {
		int bag_weight;
		cin >> bag_weight;
		bag.push_back(bag_weight);
	}
	sort(bag.begin(), bag.end());

	long long answer = 0;
	int cur = 0;
	priority_queue<int> pq;
	for (int i = 0; i < K; i++) {
		while (cur < N && jewelry[cur].first <= bag[i]) {
			pq.push(jewelry[cur].second);
			cur++;
		}
		if (!pq.empty()) {
			answer += (long long) pq.top();
			pq.pop();
		}
	}
	cout << answer;
}
