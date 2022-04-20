#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> problems(N+1);
	vector<int> weight(N + 1);
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		problems[A].push_back(B);
		weight[B]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < N+1; i++) {
		if (weight[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int pre = pq.top();
		cout << pre << " ";
		pq.pop();
		for (int i = 0; i < problems[pre].size(); i++) {
			int next = problems[pre][i];
			if (--weight[next] == 0) {
				pq.push(next);
			}
		}
	}
}