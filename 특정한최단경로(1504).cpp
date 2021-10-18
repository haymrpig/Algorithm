#include <iostream>
#include <vector>
#define MAX 801
#define INF 100000000
using namespace std;
int V, E;
// �÷��̵� ���� �˰����� �̿� ( ��� ���� ���� �ִܰŸ� ���� )
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

	// k�� ���İ��� ����
	for (int k = 1; k <= V; k++) {
		// i�� ��� ����
		for (int i = 1; i <= V; i++) {
			// j�� ������ ����
			for (int j = 1; j <= V; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	// �߰��� �ݵ�� ���ľ� �ϴ� ��忡�� �ΰ��� ���ɼ��� �����Ѵ�.
	// 1->ù��°->�ι�°->N
	// or 1->�ι�°->ù��°->N
	// ��ΰ� �������� ������ -1 ���, �����ϸ� �� ���� ���� ���
	int answer1 = dist[1][mustPass1] + dist[mustPass1][mustPass2] + dist[mustPass2][V];
	int answer2 = dist[1][mustPass2] + dist[mustPass2][mustPass1] + dist[mustPass1][V];
	if (answer1 >= answer2 && answer2 < INF) cout << answer2 << endl;
	else if (answer1 < answer2 && answer1 < INF) cout << answer1 << endl;
	else cout << -1 << endl;
}