#include <iostream>
#include <vector>
#include <algorithm>

/*
	1. ���������� �����ϰ�, ���������� ���Ѵ�. 
	2. ���������� ����� ������ �����ϱ� ������, �տ� �ִ� ������� ���������� ������ ���, ä�� X
	3. �ð����⵵ ������ �տ� �Ź� ���� ��� ����� �˻��ϴ� ���� �ȵȴ�. 
	4. for���� �����鼭 �ջ�����߿��� ��������� ���� ���� ����� ����ϸ鼭 �� ����� ���Ѵ�.
	5. ���� ����� �� ��������� ���� ���� ������� ����� �� ���ٸ� ä���Ѵ�. 
*/
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	int numApplicant;
	while (testCase--) {
		cin >> numApplicant;
		vector<pair<int, int>> rank(numApplicant); // ��������, ��������
		for (int i = 0; i < numApplicant; i++) {
			cin >> rank[i].first >> rank[i].second;
		}
		sort(rank.begin(), rank.end());
		int mintemp = rank[0].second;
		int answer = 1;
		for (int i = 1; i < numApplicant; i++) {
			if (rank[i].second < mintemp) {
				answer++;
			}
			mintemp = min(mintemp, rank[i].second);
		}
		
		cout << answer << '\n';
	}
}