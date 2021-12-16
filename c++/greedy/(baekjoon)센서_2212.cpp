#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool compare(int a, int b) {
	if (a > b) return true;
	else return false;
}
int main() {
	int N, K;
	cin >> N >> K;
	map<int,int> m;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (m[temp] > 0) continue;
		m[temp] = 1;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	vector<int> diff;
	for (int i = 1; i < v.size(); i++) {
		diff.push_back(v[i] - v[i - 1]);
	}
	sort(diff.begin(), diff.end(), compare);
	int answer = 0;
	if (K >= N) {
		cout << 0;
	}
	else {
		for (int i = K - 1; i < diff.size(); i++) {
			answer += diff[i];
		}
		cout << answer;
	}
	return 0;
}