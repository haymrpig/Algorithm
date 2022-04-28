#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> children(N);

	for (int i = 0; i < N; i++) {
		cin >> children[i];
	}

	vector<int> dp(N, 1);
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (children[i] > children[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << N - answer;
}