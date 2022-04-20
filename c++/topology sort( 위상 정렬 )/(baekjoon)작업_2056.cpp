#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> works(N + 1);
	vector<int> works_time(N + 1);
	vector<int> weight(N + 1, 0);
	vector<int> accu_weight(N + 1, 0);
	int num_preworks = -1, time = -1;
	for (int i = 1; i < N+1; i++) {
		cin >> time >> num_preworks;
		works_time[i] = time;
		for (int j = 0; j < num_preworks; j++) {
			int prework;
			cin >> prework;
			works[prework].push_back(i);
			weight[i]++;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 1; i < N + 1; i++) {
		if (weight[i] == 0) {
			q.push({works_time[i], i});
		}
	}

	int answer = 0;
	while (!q.empty()) {
		int pre_time = q.front().first;
		int pre = q.front().second;
		q.pop();
		answer = max(answer, pre_time);
		for (int i = 0; i < works[pre].size(); i++) {
			int next = works[pre][i];
			int next_time = pre_time + works_time[next];
			accu_weight[next] = max(accu_weight[next], next_time);
			if (--weight[next] == 0) {
				q.push({ accu_weight[next], next });
			}
		}
	}
	cout << answer << endl;
}