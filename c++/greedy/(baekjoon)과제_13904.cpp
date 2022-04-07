#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<vector<int>> info(1001);
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		info[d].push_back(w);
	}
	priority_queue<int> pq;
	int answer = 0;
	for (int i = 1000; i >= 1; i--) {
		for (int j = 0; j < info[i].size(); j++) {
			pq.push(info[i][j]);
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer << endl;
}