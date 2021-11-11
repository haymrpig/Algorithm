#include <iostream>
#include <vector>
#include <queue>
#include <map>
/*
* 시작 09:52
* 종료 10:39
* 1. 멀티탭이 비어있는 경우, 꽂으면 된다. 
* 2. 멀티탭이 꽉 차 있는 경우, 꽂혀진 전기용품 중 가장 나중에 쓰일 전기용품을 뽑고 새로운 전기용품을 꽂는다. 
*/
using namespace std;

int main() {
	int numHole, numUse;
	cin >> numHole >> numUse;
	vector<int> device(numUse,0);
	for (int i = 0; i < numUse; i++) cin >> device[i];
	map<int, bool> m;
	priority_queue<pair<int, int>> pq;
	int cnt = 0;
	for (int i = 0; i < numUse; i++) {
		int index = 101;
		for (int j = i + 1; j < numUse; j++) {
			if (device[j] == device[i]) {
				index = j;
				break;
			}
		}
		if (m[device[i]] == false) {
			if (pq.size() >= numHole) {
				m[pq.top().second] = false;
				pq.pop();
				cnt++;
			}
			pq.push({ index,device[i] });
			m[device[i]] = true;
		}
		else {
			vector<pair<int, int>> temp;
			while (!pq.empty()) {
				temp.push_back(pq.top());
				pq.pop();
			}
			temp[temp.size() - 1] = { index, device[i] };
			for (int j = 0; j < temp.size(); j++) {
				pq.push(temp[j]);
			}
		}
	}
	cout << cnt;
}