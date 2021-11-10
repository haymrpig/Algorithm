#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
/*
	시작 22:26
	종료 23:41
	1. 규칙을 찾는데 오래걸렸다. 만약 1,2,3,4,5가 있고, 그 다음 숫자로 5가 들어오는 경우 1~10까지 만들 수 있다. 
*/
using namespace std;

int main() {
	int num;
	cin >> num;
	long long temp;
	vector<long long> weight;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		weight.push_back(temp);
	}
	sort(weight.begin(), weight.end());
	long long minNum = 1;
	for (int i = 0; i < weight.size(); i++) {
		if (weight[i] > minNum) {
			break;
		}
		minNum += weight[i];
	}
	cout << minNum;
}