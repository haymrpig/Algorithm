#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/* 1차 시도 = > 실패
	
	실패 이유 : 
	끝나는 시간이 같은 경우는 따로 정렬을 안 해주었다. 
	예를 들어 (8,8) (7,8)이 있을 경우, (7,8)먼저 회의를 배정하고 (8,8)을 배정하면 2개가 카운트되지만
	(8,8)을 먼저 배정하면 1개만 카운트가 된다.
	
	해결방법:
	compare함수에 끝나는 시간이 같을 경우, 시작시간이 빠른 순으로 정렬을 하였다. 
 */
bool compare(pair<long long, long long>a, pair<long long, long long>b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	else return false;
}
int main()
{
	int numConf = 0;
	cin >> numConf;
	vector<pair<long long, long long>> confInfo(numConf, { 0,0 });
	for (int i = 0; i < numConf; i++) {
		cin >> confInfo[i].first >> confInfo[i].second;
	}
	sort(confInfo.begin(), confInfo.end(), compare);

	int maxConf = 1;
	int preEndTime=confInfo[0].second;
	for (int i = 1; i < numConf; i++) {
		if (confInfo[i].first >= preEndTime) {
			maxConf++;
			preEndTime = confInfo[i].second;
		}
	}
	cout << maxConf;

}