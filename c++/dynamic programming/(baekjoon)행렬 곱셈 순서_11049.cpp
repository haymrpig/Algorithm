#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 1000000000

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> matrix(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> matrix[i].first >> matrix[i].second;
	}

	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; i + j <= N; j++) {
			dp[j][i + j] = INF;
			for (int k = j;k<i+j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j].first * matrix[k].second * matrix[i + j].second);
			}
		}
	}
	cout << dp[1][N];
}