#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
*  ���� 21:33 
*  ���� 22:05
*  1. ���� ���ϴµ� ���� ���� �ͺ��� ���ʴ�� ����� �����ؾ� �ϱ⿡ �켱���� ť�� �̿��Ͽ� ���� ���� ī������ ����� �Ͽ���. 
*/
using namespace std;
int main() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> q;

	while (N--) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
	int temp, sum=0;
	while (q.size()>=2) {
		temp = q.top();
		q.pop();
		temp += q.top();
		q.pop();
		q.push(temp);
		sum += temp;
	}
	cout << sum;
}