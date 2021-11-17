#include <iostream>
#include <vector>
#include <deque>
/*
*	���� 18:00
*	���� 18:13
* 
*	- Logic
*	1. deque �ڷᱸ���� �̿��Ͽ� ���ڿ��� ���Ѵ�. 
*	2. bomb�̶� ���ڿ��� deque�ȿ� ������ ���ڿ���ŭ pop�ϰ� ���� ���ڿ����� �����Ѵ�. 
*		-> �ݺ��Ͽ� �������� deque�ȿ� �����ִ� ���ڿ��� ����
* 
*	- deque��� ����
*	1. stack�� �̿��Ͽ� Ȯ���ص� ������, stack�� ��� �� ������ ���Ҹ� Ȯ�ΰ����ϱ� ������ ���ڿ��� �񱳽� pop�ϰ� �ٽ� push�ؾ� �Ѵ�. 
*	2. deque�� ��� �߰� ���ڿ� ���ؼ��� Ȯ���� �����ϴ�. 
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