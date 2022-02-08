#include <iostream>
#include <vector>
#include <queue>
#define MAX_NUM 1000000001
using namespace std;
/*
*	- Logic 
*	1. 우선 K와 v를 입력받고, v부터 BFS 알고리즘으로 탐색을 시작한다. 
*	2. 만약 연결된 간선의 값이 K보다 작은 경우, 이후 연결될 간선들은 모두 K보다 작을 것이기 때문에 탐색 중지
*	3. 만약 연결된 간선의 값이 K보다 큰 경우, 지속적으로 탐색하고, ans++
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