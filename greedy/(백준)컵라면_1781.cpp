#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
* 시작 12:48
* 종료 13:48
* 1. 처음에는 단순하게 각 1부터 시작하여 deadline이 일치하는 것들 중 최대값을 더하였다.
*		-> deadline이 3인 문제가 3개이고 이 셋의 라면 수가 제일 많은 경우, 1,2,3모두 이 셋을 골라야 한다. 
* 2. deadline이 낮은 순으로 정렬하고, 라면의 수를 기준으로 우선순위 큐에 넣는다. ( 이 때, queue의 크기는 입력되는 deadline을 넘어서는 안된다. )
* 3. 만약 넘은 경우는 라면의 수가 제일 적은 값을 pop한다. 
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