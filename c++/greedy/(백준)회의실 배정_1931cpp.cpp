#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/* 1�� �õ� = > ����
	
	���� ���� : 
	������ �ð��� ���� ���� ���� ������ �� ���־���. 
	���� ��� (8,8) (7,8)�� ���� ���, (7,8)���� ȸ�Ǹ� �����ϰ� (8,8)�� �����ϸ� 2���� ī��Ʈ������
	(8,8)�� ���� �����ϸ� 1���� ī��Ʈ�� �ȴ�.
	
	�ذ���:
	compare�Լ��� ������ �ð��� ���� ���, ���۽ð��� ���� ������ ������ �Ͽ���. 
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