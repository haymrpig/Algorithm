#include <iostream>
#include <vector>
#include <string>
#define LIMIT 1000000

using namespace std;
int main() {
	string numbers;
	cin >> numbers;
	if (numbers[0] == '0') {
		cout << 0;
		return 0;
	}
	numbers = " " + numbers;
	int N = numbers.size();
	
	vector<long long> dp(N, 0);
	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i < N; i++) {
		string temp = "";
		temp += numbers[i - 1];
		temp += numbers[i];
		if (temp[1] == '0') {
			if (temp[0] == '0' || temp[0] > '2') {
				cout << 0;
				return 0;
			}
			else {
				dp[i] = dp[i - 2];
			}
		}
		else {
			if (temp[0] == '0' || stoi(temp) >26) {
				dp[i] = dp[i - 1];
			}
			else{
				dp[i] = dp[i - 2]%LIMIT + dp[i - 1]%LIMIT;
			}
		}
	}
	cout << dp[N-1]%LIMIT;
	return 0;
}