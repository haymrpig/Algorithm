#include<iostream>
#include<stack>
#include<vector>
using namespace std;
// dynamic programming�� ����ϴ� �����̴�. 
// d[k]�� array[k]�� ������ ���ҷ� ���� k��°�� ������ ���̴�. 
// 3 2 1 4 5 ���� �迭����
// ù��° ���� i = 0 ������ ���� 1 1 1 1 1�� ä���� ���� ���̴�.
// i=1������ 2�� 3���� �����Ƿ� 1 1 1 1 1�� ä���� ���� ���̴�.
// i=2������ 1�� 2, 3���� �����Ƿ� 1 1 1 1 1�� ä���� ���� ���̴�.
// i=3������ 4�� 3, 2, 1���� ũ�Ƿ� d[0]+1, d[1]+1, d[2]+1 �� �ִ밪�� d[3]�� �����Ѵ�.
// ...
// �̷������� Ǯ�� �� ������ ������ ������ �ذ� ����ǰ�, �� �� �ִ밪�� ã�� ����Ѵ�.
int main(int argc, char** argv)
{
	int stoneNum = 0;
	cin >> stoneNum;
	stack<int> st;
	vector<int> stone;
	for (int i = 0; i < stoneNum; i++) {
		int height = 0;
		cin >> height;
		stone.push_back(height);
	}
	vector<int> d(stoneNum, 1);

	for (int i = 1; i < stoneNum; i++) {
		for (int j = 0; j < i; j++) {
			if (stone[j] < stone[i]) d[i] = max(d[i], d[j] + 1);
		}
	}
	int maxNum = 0;
	for (auto x : d) {
		if (maxNum < x) maxNum = x;
	}
	cout << maxNum;
	return 0;
}