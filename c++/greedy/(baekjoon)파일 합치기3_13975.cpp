#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	typedef long long ll;
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;

		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < K; i++) {
			ll cost_temp;
			cin >> cost_temp;
			pq.push(cost_temp);
		}

		ll answer = 0;
		while (pq.size()!=1) {
			ll sum_cost = 0;
			for (int i = 0; i < 2; i++) {
				sum_cost += pq.top();
				pq.pop();
			}
			pq.push(sum_cost);
			answer += sum_cost;
		}
		cout << answer << endl;
	}
}
