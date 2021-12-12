#include <vector>
#include <iostream>
#include <queue>
/*
*  - Logic
*  1. ���� ���� �����̴�. ( � �۾����� ������ �� ������ ������ �ִ� ��� )
*		-> �ܹ���, ����Ŭ�� �������� �ʴ� ��� ��� ����
*		-> ���� �������� ������ �� �ִ�. 
*	����
*	1. ���� �ڽ� ���� ������ ������ �����ϴ� ��� ���� ������ +1
*	2. ��� ����� ���� ����
	3. q�� ���� 0�� ��带 ����
*	4. q���� pop�� ���� ����� ����� �� -1, pop�� ��带 ���� �迭�� ����
*		-> ���� ����� ����� ���� 0�� �� ��� 3�� ����
*	5. ���� ��� ��带 �湮�ϱ� ���� queue�� ����ְ� �ȴٸ� ����Ŭ�� �����ϴ� �����̹Ƿ� return -1
*  6. ���� �迭�� ������� ���
*		
*/
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> answer;
	vector<vector<int>> link(N + 1);
	vector<int> weight(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		link[A].push_back(B);
		weight[B] += 1;
	}
	queue<int> q;
	for (int i = 1; i < N+1; i++) {
		if (weight[i] == 0) q.push(i);
	}
	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			cout << "impossible" << endl;
			return -1;
		}

		int pn = q.front();
		q.pop();
		answer.push_back(pn);
		for (auto nn : link[pn]) {
			if (--weight[nn] == 0) {
				q.push(nn);
			}
		}
	}

	for (auto x : answer) cout << x << " ";
	


}