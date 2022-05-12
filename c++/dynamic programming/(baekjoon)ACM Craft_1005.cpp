#include <iostream>
#include <vector>
#define INF 10000000001
typedef long long ll;

using namespace std;

ll CalTime(vector<vector<int>>& building, vector<ll>& min_time, vector<int>& construct_time, int num) {
	if (min_time[num] != INF) return min_time[num];

	ll whole_time = 0;
	ll time;
	for (int i = 0; i < building[num].size(); i++) {
		time = CalTime(building, min_time, construct_time, building[num][i]);
		whole_time = max(time + (ll)construct_time[num], whole_time);
	}

	min_time[num] = whole_time;
	return whole_time;
}
int main() {
	int T, N, K, W;
	cin >> T;
	while (T--) {
		cin >> N >> K;

		vector<int> construct_time(N + 1, 0);
		for (int i = 1; i < N + 1; i++) {
			cin >> construct_time[i];
		}

		vector<vector<int>> building(N + 1);
		int pre, next;
		for (int i = 0; i < K; i++) {
			cin >> pre >> next;
			building[next].push_back(pre);
		}

		cin >> W;

		vector<ll> min_time(N + 1, INF);
		
		for (int i = 1; i < N + 1; i++) {
			if (building[i].size() == 0) {
				min_time[i] = construct_time[i];
			}
		}
		
		cout << CalTime(building, min_time, construct_time, W) << '\n';

	}
}