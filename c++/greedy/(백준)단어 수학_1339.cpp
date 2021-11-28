#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
/*
	���� 20:21
	���� 20:22

	ó������ ��� ����� ���� Ž���Ϸ� ������, �ð��� �����ɷ� �ٸ� ����� ã�Ҵ�.
	1. ���ĺ��� ���� ��ġ�� �ڸ����� ��� ���Ͽ� ���Ѱ��� ū ������ 9���� �������ش�. 
	ex ) ABCDE, CDE�� ���� ��� A:10000 B:1000 C:100+100 D:10+10 E:1+1�� �ǹǷ�
	A���� ���ʷ� 9���� �������ش�. 
*/
using namespace std;

int main() {
	int num;
	cin >> num;
	string s;
	unordered_map<char, int> m;

	while (num--) {
		cin >> s;
		int lenNum = s.size();
		for (int i = 0; i < s.size(); i++) {
			m[s[i]] += pow(10, lenNum - i - 1);
		}
	}
	priority_queue<int> q;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		q.push(iter->second);
	}
	int numMax = 9;
	int sum = 0;
	while (!q.empty()) {
		sum += q.top() * numMax;
		q.pop();
		numMax--;
	}
	cout << sum;

}