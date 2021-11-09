#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
/*
	처음 실패한 이유
	1. DFS를 이용하여 모든 경우의 수를 탐색하여 그 중 최솟값을 구했다 -> 시간초과
	2. 이 문제의 경우 모든 경우의 수를 탐색하기 보단 규칙을 찾는 것이 중요하다. 
	규칙-> '-'가 한번이라도 나오면 그 뒤의 숫자들은 괄호를 이용하여 모두 '-'로 만들어줄 수 있다. 
*/
int main() {
	string line;
	cin >> line;
	stringstream lineTemp;
	lineTemp.str(line);
	int index = 0;
	vector<int> num;
	vector<char> denom;
	int minNum=0;
	int flag = 0;
	int numTemp;
	char denomTemp;
	while (!lineTemp.eof()) {
		if (index % 2 == 0) {
			lineTemp >> numTemp;
			if (flag == 1) {
				minNum -= numTemp;
			}
			else minNum += numTemp;
		}
		else {
			lineTemp >> denomTemp;
			if (denomTemp == '-') {
				flag = 1;
			}
		}
		index++;
	}
	cout << minNum;
}