#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
*  시작 21:33 
*  종료 22:05
*  1. 합을 구하는데 합이 적은 것부터 차례대로 계산을 진행해야 하기에 우선순위 큐를 이용하여 값이 작은 카드들부터 계산을 하였다. 
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