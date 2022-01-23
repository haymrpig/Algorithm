#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000

/*
*	- Logic
*	1. ���ͽ�Ʈ�� �˰������� Ǯ �� �ִ�. 
* 
*	!!! ���� !!!
*	1. ���ͽ�Ʈ��� �ذ�ÿ� dp[nx][ny] <= pw + map[nx][ny] �� �κ��� �ִ� �Ÿ��� ������ ��Ʈ���� �Է��ϴ� �κ��̴�.
*		=> �� �κп��� ��ȣ�� ���� ���� �ÿ� queue�� ����� Ŀ�� �޸� �ʰ��� ����. (�޸� ������ �ſ� Ÿ��Ʈ�� ������ �� ����.)
*		=> ��ȣ�� �߰������ν� �߰����� �޸𸮸� ������� �ʵ��� �ؾ��Ѵ�. 
*/

using namespace std;

int main() {
	int idx = 0;
	while (1) {
		if (idx != 0) {
			cout << '\n';
		}
		idx++;
		int N;
		cin >> N;
		if (N == 0) break;
		vector<vector<int>> map(N, vector<int>(N, 0));
		vector<vector<int>> dp(N, vector<int>(N, INF));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		dp[0][0] = map[0][0];
		int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int,int>>>> pq;
		pq.push({ map[0][0],{ 0,0 } });
		while (!pq.empty()) {
			int px = pq.top().second.first;
			int py = pq.top().second.second;
			int pw = pq.top().first;
			pq.pop();
			if (px == N - 1 && py == N - 1) break;
			for (int i = 0; i < 4; i++) {
				int nx = px + dx[i];
				int ny = py + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || dp[nx][ny] <= pw + map[nx][ny]) continue;
				dp[nx][ny] = pw + map[nx][ny];
				pq.push({dp[nx][ny],{ nx, ny } });
			}
		}
		while (!pq.empty()) pq.pop();
		cout << "Problem " << idx << ": " << dp[N - 1][N - 1];
	}
}