#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
*	-Logic
*	1. 간단하게 조합을 이용하여 풀 수 있는 문제였다. 
*	2. DFS를 이용하여 가능한 조합을 구하고, 조건에 맞게 모음 1개, 자음 2개에 대해 검사를 하였다. 
* 
*/
string check = "aeiou";
void Compose(int index, vector<char>& v, int length, string temp, int mo, int za, vector<string>& hubo) {
	if (temp.size() == length) {
		if (mo >= 1 && za >= 2) {
			hubo.push_back(temp);
		}
		return;
	}
	for (int i = index; i < v.size(); i++) {
		int j;
		for (j = 0; j < check.size(); j++) {
			if (check[j] == v[i]) break;
		}
		if( j==check.size() ) Compose(i + 1, v, length, temp + v[i], mo, za+1, hubo);
		else 	Compose(i + 1, v, length, temp + v[i], mo+1, za, hubo);
	}
	return;
}

int main() {
	int L, C;
	cin >> L >> C;
	vector<char> alphabet;
	string vowel_ = "aeiou";

	for (int i = 0; i < C; i++) {
		char temp;
		cin >> temp;
		alphabet.push_back(temp);
	}
	sort(alphabet.begin(), alphabet.end());
	vector<string> hubo;
	Compose(0, alphabet, L, "", 0, 0, hubo);
	sort(hubo.begin(), hubo.end());
	for (int i = 0; i < hubo.size(); i++) {
		cout << hubo[i];
		if (i == hubo.size() - 1) break;
		cout << '\n';
	}
	return 0;
}