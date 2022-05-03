#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 10000
using namespace std;

int main() {
	int n; 
	cin >> n;

	vector<int> dp(n+1, INF);
	dp[1] = 0;
	for (int i = 2; i < n + 1; i++) {
		for (int j = i-1; j > 0; j--) {
			int temp = ceil((i - j) / double(j));
			dp[i] = min(dp[i], dp[j] + temp + (j + j * temp - i));
		}
		dp[i] += 1;
	}
	cout << dp[n];
}