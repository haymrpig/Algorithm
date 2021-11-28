#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
/*
	���� 22:26
	���� 23:41
	1. ��Ģ�� ã�µ� �����ɷȴ�. ���� 1,2,3,4,5�� �ְ�, �� ���� ���ڷ� 5�� ������ ��� 1~10���� ���� �� �ִ�. 
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