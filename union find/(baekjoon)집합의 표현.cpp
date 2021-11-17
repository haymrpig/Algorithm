#include <iostream>
#include <vector>
#include <stack>
/*
*	시작 21:10
*	종료 22:02
* 
*  - Logic
*	1. Union-Find방식을 이용하는 문제이다. 
*	2. 각각의 숫자에 대한 parent를 입력해주어, root를 찾는 방식으로 진행하였다. 
*	3. root가 같은 경우는 하나의 집합이다. 
* 
*	!!! 주의 !!!
*	1. ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
*		-> 첫번째 문장엣서 false가 ture인 경우 c의 stdio와 c++의 iostream을 동기화시켜주어 두 버퍼를 모두 사용하여 딜레이가 발생한다. 
*		-> 단일 스레드에서는 false로 두어도 크게 문제가 생기지 않는다. 
*		-> 두,세번째 문장의 경우 cin과 cout은 원래 묶여있다. InOut작업 전에 자동으로 버퍼를 비워줌을 보장한다. 
*		-> 여러번의 cin과 cout을 이용할 경우 자동으로 버퍼를 비우는 것은 오래 걸리기에 tie를 해제해주는 것이 좋다. 
*	2. 개행 문자의 경우도 endl은 줄바꿈과 출력버퍼를 비우는 것을 동시에 수행하기에 오래걸린다. 
*	3. 처음에 반복문으로 root를 찾는 방식을 이용하였는데, 재귀 함수를 통해 찾은 root를 각각의 부모로 넣어줌으로써 이후에 탐색할 때, 시간을 축소시킬 수 있었다. 
*/
using namespace std;

int findRoot(vector<int>& set, int num) {
	if (set[num] == num) return num;
	return set[num] = findRoot(set, set[num]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n=0, m=0;
	cin >> n >> m;
	vector<int> set(n + 1);
	for (int i = 0; i < n + 1; i++) {
		set[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int oper, num1, num2;
		cin >> oper >> num1 >> num2;
		if (oper == 0) {
			int root = findRoot(set, num1);
			int root1 = findRoot(set, num2);
			if (root == root1) continue;
			set[root] = root1;
		}
		else {
			int root1 = findRoot(set, num1);
			int root2 = findRoot(set, num2);
			root1 == root2 ? cout << "YES" : cout << "NO";
			cout << '\n';
		}
	}
}