#include <iostream>
#include <vector>
#include <algorithm>
/*
* ���� 09:24
* ���� 09:50
* ��Ģ�� ã�� ��������. �������� ���ϰ�, ������� ������ �� �ִ밡 ���´�. 
* -> ������ Ȧ������ ���, 0�� ������ �������� �ʴ´�. 
* -> 1�� ����� ���ص� �����̴�. 1�ϰ��� �׳� �����־�� �Ѵ�.
*/
using namespace std;

bool compare(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main() {
	int num;
	cin >> num;
	vector<int> number(num, 0);
	int minus = 0, plus = 0, zero = 0, one=0;
	for(int i=0;i<num;i++) {
		cin >> number[i];
		if (number[i] > 1) plus++;
		else if (number[i] < 0) minus++;
		else if (number[i] == 1)one++;
		else zero++;
	}
	sort(number.begin(), number.end(), compare);
	int sum = 0;
	for (int i = 0; i < plus; i+=2) {
		if (i + 1 >= plus) {
			sum += number[i];
			break;
		}
		sum += number[i] * number[i + 1];
	}
	sum += one;
	for (int i = 0; i <minus; i += 2) {
		if (i + 1 >= minus) {
			if (zero == 0) {
				sum += number[num - i-1];
			}
			break;
		}
		sum += number[num-i-1] * number[num-i-2];
	}

	cout << sum;
}