#include <iostream>
#include <vector>
#include <stack>
/*
*	���� 18:21
*	
*	- Logic
*	1. stack�� �̿��Ѵ�. 
*	2. ���� stack�� ���� ���� ���� ���� ������ ���� ���, �� ���� ����� ���� �̷��� ���Ѵ�. -> pop + cnt++ ( pop�ϴ� ���� ��ü�� ���� ���� ���� �� ���� ���� �̷� �� �ִٴ� �ǹ� )
*	3. �� ū ���� ������ ���, �� ������ ���� ������ pop�ϸ鼭 cnt++
*	4. push�ϴ� ���� �ٷ� ���� ���� ���� �̷�� �ǹ� -> cnt++
*	5. ���� ���� ���, ������ ���� ���� + �� ���� ���� ���� �̷� �� ������ ���� ���� ������ count�ؾ��Ѵ�. 
*/
using namespace std;
int main() {
	int num;
	cin >> num;
	stack<pair<int, int>> st;
	long long pairCnt = 0;
	int current;
	for (int i = 0; i < num; i++) {
		cin >> current;
		int sameNum = 1;
		while (!st.empty() && st.top().first < current) {
			pairCnt += st.top().second;
			st.pop();
		}

		if (!st.empty()) {
			if (st.top().first == current) {
				sameNum = st.top().second + 1;
				pairCnt += st.top().second;
				if (st.size() > 1)
					pairCnt++;
				st.pop();
			}
			else {
				pairCnt++;
			}
		}

		st.push({ current, sameNum });
	}
	cout << pairCnt;
	return 0;
}