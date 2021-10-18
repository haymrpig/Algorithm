#include <iostream>
#include <vector>
#define MAX 801
#define INF 100000000
using namespace std;
int V, E;
// 플로이드 워샬 알고리즘을 이용 ( 모든 정점 사이 최단거리 구함 )
int main() {
	cin >> V >> E;
	vector<vector<int>> dist(V+1, vector<int>(V+1, INF));
	
	for (int i = 1; i <= V; i++) dist[i][i] = 0;
	while (E--) {
		int v1, v2, weight;
		cin >> v1 >> v2 >> weight;
		dist[v1][v2] = weight;
		dist[v2][v1] = weight;
	}

	int mustPass1, mustPass2;
	cin >> mustPass1 >> mustPass2;

	// k는 거쳐가는 점점
	for (int k = 1; k <= V; k++) {
		// i는 출발 정점
		for (int i = 1; i <= V; i++) {
			// j는 목적지 정점
			for (int j = 1; j <= V; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	// 중간에 반드시 거쳐야 하는 노드에는 두가지 가능성이 존재한다.
	// 1->첫번째->두번째->N
	// or 1->두번째->첫번째->N
	// 경로가 존재하지 않으면 -1 출력, 존재하면 더 작은 값을 출력
	int answer1 = dist[1][mustPass1] + dist[mustPass1][mustPass2] + dist[mustPass2][V];
	int answer2 = dist[1][mustPass2] + dist[mustPass2][mustPass1] + dist[mustPass1][V];
	if (answer1 >= answer2 && answer2 < INF) cout << answer2 << endl;
	else if (answer1 < answer2 && answer1 < INF) cout << answer1 << endl;
	else cout << -1 << endl;
}