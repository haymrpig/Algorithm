#include <iostream>
#include <vector>
#include <stack>
/*
*	���� 21:10
*	���� 22:02
* 
*  - Logic
*	1. Union-Find����� �̿��ϴ� �����̴�. 
*	2. ������ ���ڿ� ���� parent�� �Է����־�, root�� ã�� ������� �����Ͽ���. 
*	3. root�� ���� ���� �ϳ��� �����̴�. 
* 
*	!!! ���� !!!
*	1. ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
*		-> ù��° ���忧�� false�� ture�� ��� c�� stdio�� c++�� iostream�� ����ȭ�����־� �� ���۸� ��� ����Ͽ� �����̰� �߻��Ѵ�. 
*		-> ���� �����忡���� false�� �ξ ũ�� ������ ������ �ʴ´�. 
*		-> ��,����° ������ ��� cin�� cout�� ���� �����ִ�. InOut�۾� ���� �ڵ����� ���۸� ������� �����Ѵ�. 
*		-> �������� cin�� cout�� �̿��� ��� �ڵ����� ���۸� ���� ���� ���� �ɸ��⿡ tie�� �������ִ� ���� ����. 
*	2. ���� ������ ��쵵 endl�� �ٹٲް� ��¹��۸� ���� ���� ���ÿ� �����ϱ⿡ �����ɸ���. 
*	3. ó���� �ݺ������� root�� ã�� ����� �̿��Ͽ��µ�, ��� �Լ��� ���� ã�� root�� ������ �θ�� �־������ν� ���Ŀ� Ž���� ��, �ð��� ��ҽ�ų �� �־���. 
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