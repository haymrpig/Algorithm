#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
/*
*  1. Ʈ���� ������ ���ϴ� ������ �����Ѵ�.
*		-> ���� ������ ������ ���� �� ���� ã�´�.
*		-> �� ������ ���� �� ���� ã���� �� �� �� ���� �Ÿ��� Ʈ���� ������ �ȴ�. 
*/
int answer = 0;
using namespace std;
int Dijkstra(int start, int N, vector<vector<pair<int, int>>>& info) {
	vector<int> dist(N + 1, INF);
	int next = 0;
	dist[start] = 0;
	queue<pair<int, int>> q;
	q.push({ 0, start });
	while (!q.empty()) {
		int pw = q.front().first;
		int pn = q.front().second;
		q.pop();
		for (int i = 0; i < info[pn].size(); i++) {
			int nn = info[pn][i].first;
			int nw = info[pn][i].second + pw;
			if (dist[nn] > nw) {
				q.push({ nw, nn });
				dist[nn] = nw;
				if (answer < nw) {
					answer = nw;
					next = nn;
				}
			}
		}
	}
	return next;
}
int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> info(N + 1);
	vector<int> one_link;
	for (int i = 0; i < N; i++) {
		int start, end, weight;
		cin >> start;
		while (1) {
			cin >> end;
			if (end == -1) break;
			cin >> weight;
			info[start].push_back({ end,weight });
		}
	}
	int next = 1;
	for(int i=0;i<2;i++)
		next = Dijkstra(next, N, info);
	
	cout << answer;
}