#include <iostream>
#include <vector>
#include <algorithm>
/*
*	- Logic
*	1. 모든 조합을 모두 구하는 문제이다. 
*	2. N은 15로 모든 가능한 조합의 경우의 수는 2*(15C1 + 15C2 + ... + 15C7)이므로 DFS로 충분히 해결 가능하다.
*	
*/
using namespace std;
int N, L, R, X;
int answer = 0;
void QuizCombi(vector<int>& quiz, int index, vector<int> combi, int sum) {
	for (int i = 0; i < combi.size(); i++) cout << combi[i] << " ";
	cout << endl;
	if (combi.size() >= 2) {
		if (sum >= L && sum <= R) {
			if (combi[combi.size() - 1] - combi[0] >= X) answer++;
		}
		else if (sum > R) return;
	}

	for (int i = index; i < N; i++) {
		combi.push_back(quiz[i]);
		QuizCombi(quiz, i + 1, combi, sum + quiz[i]);
		combi.erase(combi.begin() + combi.size() - 1);
	}
	return;
}
int main(int* argc, char** argv) {
	cin >> N >> L >> R >> X;
	vector<int> quiz;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		quiz.push_back(temp);
	}
	sort(quiz.begin(), quiz.end());
	
	vector<int> combi;
	QuizCombi(quiz, 0, combi, 0);
	cout << answer << endl;
}