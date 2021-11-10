#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
/*
	시작 20:21
	종료 20:22

	처음에는 모든 경우의 수를 탐색하려 했지만, 시간이 오래걸려 다른 방법을 찾았다.
	1. 알파벳이 현재 위치한 자릿수를 모두 더하여 더한값이 큰 값부터 9부터 배정해준다. 
	ex ) ABCDE, CDE가 있을 경우 A:10000 B:1000 C:100+100 D:10+10 E:1+1이 되므로
	A부터 차례로 9부터 배정해준다. 
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