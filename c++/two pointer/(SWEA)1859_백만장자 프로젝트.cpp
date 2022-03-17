#include <string>
#include <iostream>
#include <vector>
/*
*  ��������1.
*	- findMax �Լ� ����
*		max �迭�� �����ϰ�, price �迭�� �ڿ������� �˻��ϸ鼭
*		�ִ밪�� �����ϸ�, Ư�� �� ������ �ִ밪�� �� ���� for���� �����鼭
*		Ȯ���� �� �ִ�.
*		ex)		1    4   5   10   9    5  11  8  9
*		max 11  11  11  11  11  11  11  9  9 -> �ڿ������� �����ϸ� �̷������� ����
*		���� max���� ���� ���� ��ġ���� ������ ����, ��ġ�ϸ� �Ǹ�!
*		�ƴϸ� max���ٰ� index�� �����ϴ� ����� �ִ�.
*	
*	��������2.
*	- �ƿ� �ڿ������� ���
*		�������� �������� ������ �ذ��� �� �ִ�. (�޸𸮸� �� �Ƴ� �� �ִ�.)
*		1. price �迭�� �ڿ������� üũ�Ѵ�.
*		2. start�� �� �� ����, end�� ��ĭ ������
*		3. ���� start >= end��� ���� ������ ����
*		    ���� start < end��� start = end��
*			��, ���� ���ڰ� ũ�� ���� ���ڴ� ��� �̵�, ���� ���ڰ� ������ ���� ���ڴ� �Ⱦƾ� �̵��� ��!
*
*/
using namespace std;


pair<int,int> findMax(vector<int> price, int start){
	pair<int, int> answer;
	answer.first = -1;
	for (int i = start; i < price.size(); i++) {
		if (answer.first < price[i]) {
			answer.first = price[i];
			answer.second = i;
		}
	}
	return answer;
}


int main() {
	int T, N;
	pair<int, int> check;
	int start = 0;
	long long gain=0, buy = 0, num = 0;
	
	cin >> T;
	int index = 1;
	while (index <= T) {
		gain = 0, start = 0;
		vector<int> price;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			price.push_back(temp);
		}
		while (start < N) {
			buy = 0, num = 0;
			check = findMax(price, start);

			for (int i = start; i < check.second; i++) {
				buy += price[i];
			}
			num = check.second - start;
			gain = gain + num * (long long)price[check.second] - buy;
			start = check.second + 1;
		}
		cout << '#' << index << ' ' << gain <<'\n';
		index++;
	}
}