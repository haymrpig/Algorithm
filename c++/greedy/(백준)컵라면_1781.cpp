#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
* ���� 12:48
* ���� 13:48
* 1. ó������ �ܼ��ϰ� �� 1���� �����Ͽ� deadline�� ��ġ�ϴ� �͵� �� �ִ밪�� ���Ͽ���.
*		-> deadline�� 3�� ������ 3���̰� �� ���� ��� ���� ���� ���� ���, 1,2,3��� �� ���� ���� �Ѵ�. 
* 2. deadline�� ���� ������ �����ϰ�, ����� ���� �������� �켱���� ť�� �ִ´�. ( �� ��, queue�� ũ��� �ԷµǴ� deadline�� �Ѿ�� �ȵȴ�. )
* 3. ���� ���� ���� ����� ���� ���� ���� ���� pop�Ѵ�. 
*/
using namespace std;
bool compare(pair<int, long long> a, pair<int, long long> b) {
	if (a.first < b.first) return true;
	else return false;
}
int main() {
	int numTask;
	cin >> numTask;
	vector<pair<int, long long>> info(numTask);;
	for(int i=0;i<numTask;i++) {
		cin >> info[i].first >> info[i].second;
	}
	sort(info.begin(), info.end(), compare);

	priority_queue<pair<int, long long>, vector<pair<int,long long>>, greater<pair<int,long long>>> pq;
	for (int i = 0; i < numTask; i++) {
		int deadline = info[i].first;
		pq.push({ info[i].second, info[i].first });
		if ( pq.size() > deadline) {
			pq.pop();
		}
	}
	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top().first;
		pq.pop();
	}
	cout << sum;

}