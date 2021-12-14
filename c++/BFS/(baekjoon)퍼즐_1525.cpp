#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
/*
*  1. 이 문제는 모든 경우의 수를 다 탐색하는 문제이다. 
*  2. 모든 경우에 대해서 3x3 배열을 만들 경우, 메모리 초과가 나기 때문에 이를 string으로 대체하여 탐색한다.
*  3. BFS를 통해 탐색하되, 이전에 탐색한 적이 있는 string일 경우 재 탐색하지 않기 위해 set 자료구조를 이용하였다. 
*  4. 모든 경우의 수를 탐색하면서 "123456780"과 일치하는 string이 있는 경우 depth를 반환한다. 
*  5. 모든 탐색을 맞췄음에도 일치하는 것이 없다면 -1을 반환한다. 
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