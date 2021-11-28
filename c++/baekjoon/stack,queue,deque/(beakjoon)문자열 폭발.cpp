#include <iostream>
#include <vector>
#include <deque>
/*
*	시작 18:00
*	종료 18:13
* 
*	- Logic
*	1. deque 자료구조를 이용하여 문자열을 비교한다. 
*	2. bomb이란 문자열이 deque안에 있으면 문자열만큼 pop하고 남은 문자열들을 삽입한다. 
*		-> 반복하여 마지막에 deque안에 남아있는 문자열이 정답
* 
*	- deque사용 이유
*	1. stack을 이용하여 확인해도 되지만, stack의 경우 맨 마지막 원소만 확인가능하기 때문에 문자열을 비교시 pop하고 다시 push해야 한다. 
*	2. deque의 경우 중간 문자에 대해서도 확인이 가능하다. 
*/
using namespace std;
int main() {
	deque<char> dq;
	string line;
	cin >> line;
	string bomb;
	cin >> bomb;
	for (int i = 0; i < line.size(); i++) {
		dq.push_back(line[i]);
		if (dq.size() >= bomb.size()) {
			bool isFoundBomb = true;
			int indexDiff = int(dq.size() - bomb.size());
			for (int j = 0; j < bomb.size(); j++) {
				if (dq[indexDiff + j] != bomb[j]) {
					isFoundBomb = false;
					break;
				}
			}
			if (isFoundBomb) {
				for (int i = 0; i < bomb.size(); i++) dq.pop_back();
			}
		}
	}
	if (dq.size() > 0) for (auto x : dq) cout << x;
	else cout << "FRULA";
}