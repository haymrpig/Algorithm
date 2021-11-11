#include <iostream>
#include <vector>
#include <algorithm>
/*
* 시작 09:24
* 종료 09:50
* 규칙을 찾는 문제였다. 음수끼리 곱하고, 양수끼리 곱했을 때 최대가 나온다. 
* -> 음수가 홀수개인 경우, 0이 있으면 더해주지 않는다. 
* -> 1은 어떤수와 곱해도 손해이다. 1일경우는 그냥 더해주어야 한다.
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