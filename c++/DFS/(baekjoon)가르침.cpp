#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*
*	시작 00:27
*	종료 01:38
* 
*	- Logic
*	1. 가능한 모든 조합을 탐색하는 문제이다. 
*	2. 조합의 경우는 DFS를 이용하여 구하였고, 모든 단어와 비교하면서 읽을 수 있는 단어일 경우 cnt를 증가시켜주었다. 
* 
*	!!! 주의 !!!
*	1. 26개의 알파벳으로 한정이 되어 있기 때문에 조합에 사용되는 경우, true 아닐 경우 false로 놓고 비교하면 된다. 
*		-> 처음에는 anta와 tica를 제외한 문자들을 중복없이 string으로 입력하고, k조합의 경우에도 string형태로 두어 3중 for문을 이용하여 비교를 하였다. -> 시간초과 발생
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