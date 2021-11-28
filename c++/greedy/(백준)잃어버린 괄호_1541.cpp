#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
/*
	ó�� ������ ����
	1. DFS�� �̿��Ͽ� ��� ����� ���� Ž���Ͽ� �� �� �ּڰ��� ���ߴ� -> �ð��ʰ�
	2. �� ������ ��� ��� ����� ���� Ž���ϱ� ���� ��Ģ�� ã�� ���� �߿��ϴ�. 
	��Ģ-> '-'�� �ѹ��̶� ������ �� ���� ���ڵ��� ��ȣ�� �̿��Ͽ� ��� '-'�� ������� �� �ִ�. 
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