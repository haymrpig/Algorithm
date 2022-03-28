#include <vector>
#include <iostream>
#include <string>

using namespace std;

int N, answer = 1000000000;
void makeCombi(vector<vector<int>>& power, vector<int>& check, int depth, int idx) {
	if (depth == N/2) {
		int team1 = 0;
		int team2 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i] == 1 && check[j] == 1) {
					team1 += power[i][j];
				}
				else if(check[i]==0 && check[j]==0){
					team2 += power[i][j];
				}
			}
		}
		answer = min(answer, abs(team1 - team2));
		return;
	}

	for (int i = idx; i < N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			makeCombi(power, check, depth+1, i);
			check[i] = 0;
		}
	}
}
int main() {
	cin >> N;
	vector<vector<int>> power(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power[i][j];
		}
	}
	vector<int> check(N, 0);
	makeCombi(power, check, 0, 0);
	cout << answer;
}