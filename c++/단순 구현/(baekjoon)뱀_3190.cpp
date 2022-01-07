#include <iostream>
#include <vector>
#include <queue>

/*
*	- Logic
*	1. 단순 구현 문제이다. 
*	2. N의 사이즈가 작으므로 실제 2차원 배열을 선언하고 뱀의 동선을 기록한다. 
*	3. queue를 이용하여 뱀의 꼬리 다음부터 머리까지 기록하고, 매시간마다 꼬리와 머리를 update한다.
*/

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> map(N, vector<int>(N, 0));
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x-1][y-1] = 1; // 사과
	}

	int num_change;
	cin >> num_change;
	vector<pair<int, int>> change_dir;
	for (int i = 0; i < num_change; i++) {
		int t;
		char c;
		cin >> t >> c;
		if (c == 'D') {
			change_dir.push_back({ t+1, 1 }); 
		}
		else {
			change_dir.push_back({ t+1, -1 });
		}
	}

	int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0}; // 우,하,좌,상
	int cur_dir = 0; // 우 : 0, 하 : 1, 좌 : 2, 상 : 3
	int timer = 0;
	queue<pair<int, int>> q;
	pair<int, int> pre_head = { 0,0 };
	pair<int, int> next_head;
	pair<int, int> pre_tail = { 0,0 };
	map[pre_tail.first][pre_tail.second] = 2;
	int cur = 0;
	while (1) {
		timer++;
		if (cur < change_dir.size() && timer == change_dir[cur].first) {
			cur_dir += change_dir[cur].second;
			if (cur_dir < 0) cur_dir = 3;
			else {
				cur_dir %= 4;
			}
			cur++;
		}
		// 이동
		next_head.first = pre_head.first + dx[cur_dir];
		next_head.second = pre_head.second + dy[cur_dir];
		q.push(next_head);

		// check if wall / body / apple
		if (next_head.first >= N || next_head.first < 0 || next_head.second >= N || next_head.second < 0) break;
		else if (map[next_head.first][next_head.second] == 2) break;
		else if(map[next_head.first][next_head.second] == 0){
			map[pre_tail.first][pre_tail.second] = 0;
			pre_tail.first = q.front().first;
			pre_tail.second = q.front().second;
			q.pop();
		}
		map[next_head.first][next_head.second] = 2;
		pre_head.first = next_head.first;
		pre_head.second = next_head.second;

	}
	cout << timer;
}

