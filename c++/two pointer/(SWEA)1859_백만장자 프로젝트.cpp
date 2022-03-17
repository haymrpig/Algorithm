#include <string>
#include <iostream>
#include <vector>
/*
*  개선사항1.
*	- findMax 함수 개선
*		max 배열을 선언하고, price 배열을 뒤에서부터 검사하면서
*		최대값을 저장하면, 특정 날 이후의 최대값을 한 번의 for문만 돌리면서
*		확인할 수 있다.
*		ex)		1    4   5   10   9    5  11  8  9
*		max 11  11  11  11  11  11  11  9  9 -> 뒤에서부터 저장하면 이런식으로 나옴
*		따라서 max값과 현재 값이 일치하지 않으면 구매, 일치하면 판매!
*		아니면 max에다가 index를 저장하는 방법이 있다.
*	
*	개선사항2.
*	- 아예 뒤에서부터 계산
*		투포인터 개념으로 문제를 해결할 수 있다. (메모리를 더 아낄 수 있다.)
*		1. price 배열을 뒤에서부터 체크한다.
*		2. start는 맨 뒤 숫자, end는 한칸 앞으로
*		3. 만약 start >= end라면 둘의 차익을 저장
*		    만약 start < end라면 start = end로
*			즉, 뒤의 숫자가 크면 앞의 숫자는 사야 이득, 뒤의 숫자가 작으면 앞의 숫자는 팔아야 이득인 것!
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