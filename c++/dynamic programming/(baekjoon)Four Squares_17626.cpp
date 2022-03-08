#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	
	vector<int> dp(50001, INF);

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		if (i == int(sqrt(i)) * int(sqrt(i))) {
			dp[i] = 1;
			continue;
		}
		dp[i] = dp[i - 1] + 1;	
		for (int j = 1; j<=sqrt(i); j++) {
			dp[i] = min(dp[i], dp[j*j] + dp[i - j*j]);
		}
	}
	cout << dp[N];
}