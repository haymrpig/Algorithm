#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second <= b.second) return true;
		else return false;
	}
	else return false;
}

int main() {
	int n;
	cin >> n; // 100이하 자연수

	vector<pair<int, int>> link(n);
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		link[i] = { a,b };
	}

	sort(link.begin(), link.end(), cmp);

	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if(link[i].second >= link[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << n-dp[n-1] << endl;
}