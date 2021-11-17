#include <iostream>
#include <vector>
#include <stack>
/*
*	시작 18:21
*	
*	- Logic
*	1. stack을 이용한다. 
*	2. 만약 stack의 제일 위의 값이 넣을 값보다 작은 경우, 그 뒤의 값들과 쌍을 이루지 못한다. -> pop + cnt++ ( pop하는 행위 자체가 현재 넣을 값이 그 값과 쌍을 이룰 수 있다는 의미 )
*	3. 더 큰 값이 들어오는 경우, 그 이전의 작은 값들을 pop하면서 cnt++
*	4. push하는 경우는 바로 앞의 값과 쌍을 이루는 의미 -> cnt++
*	5. 같은 값일 경우, 이전의 같은 값들 + 그 앞의 값과 쌍을 이룰 수 있으니 같은 값의 개수를 count해야한다. 
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