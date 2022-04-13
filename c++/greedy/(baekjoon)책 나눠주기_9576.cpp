#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>> student;
		for (int i = 0; i < M; i++) {
			int s, e;
			cin >> s >> e;
			student.push_back({ s,e });
		}
		sort(student.begin(), student.end(), compare);
		vector<bool> check(N+1, false);

		int answer = 0;
		for (int idx = 0; idx < student.size(); idx++) {
			for (int i = student[idx].first; i <= student[idx].second; i++) {
				if (!check[i]) {
					check[i] = true;
					break;
				}
			}
		}
		for (int i = 1; i < check.size(); i++) {
			if (check[i]) answer++;
		}
		cout << answer << '\n';
	}
}