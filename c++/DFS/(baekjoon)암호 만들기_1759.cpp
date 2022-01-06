#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
*	-Logic
*	1. �����ϰ� ������ �̿��Ͽ� Ǯ �� �ִ� ��������. 
*	2. DFS�� �̿��Ͽ� ������ ������ ���ϰ�, ���ǿ� �°� ���� 1��, ���� 2���� ���� �˻縦 �Ͽ���. 
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