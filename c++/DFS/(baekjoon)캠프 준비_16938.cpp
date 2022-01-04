#include <iostream>
#include <vector>
#include <algorithm>
/*
*	- Logic
*	1. ��� ������ ��� ���ϴ� �����̴�. 
*	2. N�� 15�� ��� ������ ������ ����� ���� 2*(15C1 + 15C2 + ... + 15C7)�̹Ƿ� DFS�� ����� �ذ� �����ϴ�.
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