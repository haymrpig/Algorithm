#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
/*
*  1. �� ������ ��� ����� ���� �� Ž���ϴ� �����̴�. 
*  2. ��� ��쿡 ���ؼ� 3x3 �迭�� ���� ���, �޸� �ʰ��� ���� ������ �̸� string���� ��ü�Ͽ� Ž���Ѵ�.
*  3. BFS�� ���� Ž���ϵ�, ������ Ž���� ���� �ִ� string�� ��� �� Ž������ �ʱ� ���� set �ڷᱸ���� �̿��Ͽ���. 
*  4. ��� ����� ���� Ž���ϸ鼭 "123456780"�� ��ġ�ϴ� string�� �ִ� ��� depth�� ��ȯ�Ѵ�. 
*  5. ��� Ž���� ���������� ��ġ�ϴ� ���� ���ٸ� -1�� ��ȯ�Ѵ�. 
*/
int main() {
	string line;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			line += to_string(temp);
		}
	}
	set<string> s;
	queue<pair<string, int>> q;
	q.push({ line, 0 });
	s.insert(line);
	int index;
	int dx[4] = { 3,-3, 1,-1 };
	while (!q.empty()) {
		string pre = q.front().first;
		int pre_depth = q.front().second;
		index = pre.find('0');
		q.pop();
		if (pre == "123456780") {
			cout << pre_depth;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			if ((i == 2 && index % 3 == 2) ||( i == 3 && index % 3 == 0)) continue;
			int next_index = index + dx[i];
			if (next_index >= 0 && next_index < 9) {
				string temp = pre;
				swap(temp[index], temp[next_index]);
				if ( s.find(temp) == s.end() ) {
					s.insert(temp);
					q.push({ temp, pre_depth + 1 });
				}
			}
		}
	}
	cout << -1;
	return 0;
}