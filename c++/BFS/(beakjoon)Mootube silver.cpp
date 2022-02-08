#include <iostream>
#include <vector>
#include <queue>
#define MAX_NUM 1000000001
using namespace std;
/*
*	- Logic 
*	1. �켱 K�� v�� �Է¹ް�, v���� BFS �˰������� Ž���� �����Ѵ�. 
*	2. ���� ����� ������ ���� K���� ���� ���, ���� ����� �������� ��� K���� ���� ���̱� ������ Ž�� ����
*	3. ���� ����� ������ ���� K���� ū ���, ���������� Ž���ϰ�, ans++
*/
int searchLink(vector<vector<pair<int,int>>> &link, int K, int v, int N) {
   /**
   * Find number of vertexes bigger or equal than reference value
   * 
   * @param	K is the reference value for finding weight
   *				v is the vertex to start finding
   *				N is the total number of vertexes
   * @return	return number of vertexes whose weight is bigger or equal than K
   */
	vector<int> check(N,0);
	check[v] = 1;
	queue<int> q;
	q.push(v);
	int ans = 0;
	while (!q.empty()) {
		int prev = q.front();
		q.pop();
		for (int i = 0; i < link[prev].size(); i++) {
			int nextw = link[prev][i].second;
			int nextv = link[prev][i].first;
			if (check[nextv] == 0 && K <= nextw) {
				check[nextv] = 1;
				q.push(nextv);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<vector<pair<int, int>>> link(5001);
	for (int i = 0; i < N-1; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		link[s-1].push_back({ e-1,w });
		link[e-1].push_back({ s-1,w });
	}

	for (int i = 0; i < Q; i++) {
		int K, v;
		cin >> K >> v;
		cout << searchLink(link, K, v-1, N) << '\n';
	}
}