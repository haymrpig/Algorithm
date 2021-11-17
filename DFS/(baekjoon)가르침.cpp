#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*
*	���� 00:27
*	���� 01:38
* 
*	- Logic
*	1. ������ ��� ������ Ž���ϴ� �����̴�. 
*	2. ������ ���� DFS�� �̿��Ͽ� ���Ͽ���, ��� �ܾ�� ���ϸ鼭 ���� �� �ִ� �ܾ��� ��� cnt�� ���������־���. 
* 
*	!!! ���� !!!
*	1. 26���� ���ĺ����� ������ �Ǿ� �ֱ� ������ ���տ� ���Ǵ� ���, true �ƴ� ��� false�� ���� ���ϸ� �ȴ�. 
*		-> ó������ anta�� tica�� ������ ���ڵ��� �ߺ����� string���� �Է��ϰ�, k������ ��쿡�� string���·� �ξ� 3�� for���� �̿��Ͽ� �񱳸� �Ͽ���. -> �ð��ʰ� �߻�
*	
* 
*/
using namespace std;
int maxNum = 0;
void countWord(vector<bool>& alphabet, vector<string>& newWord, int index, int depth, int num) {
	if (depth == num) {
		int cnt = 0;
		for (int i = 0; i < newWord.size(); i++) {
			if (newWord[i].size() == 8) {
				cnt++;
				continue;
			}
			int j = 0;
			for (; j < newWord[i].size(); j++) {
				if (!alphabet[newWord[i][j] - 'a']) break;
			}
			if (j == newWord[i].size()) cnt++;
		}
		maxNum = max(maxNum, cnt);
		return;
	}
	for (int i = index; i < alphabet.size(); i++) {
		if (alphabet[i] ) continue;
		alphabet[i] = true;
		countWord(alphabet, newWord, i, depth + 1, num);
		alphabet[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N = 0, K = 0;
	cin >> N >> K;
	vector<bool> alphabet(26, false);
	string must = "antci";
	for (int i = 0; i < must.size(); i++) {
		alphabet[must[i] - 'a'] = true;
	}

	vector<string> newWord;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		temp = temp.substr(4, temp.size() - 8);
		newWord.push_back(temp);
	}

	if (K < 5) {
		cout << 0;
		return 0;
	}
	countWord(alphabet, newWord, 0, 0, K - 5);
	
	cout << maxNum;
}