#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
/*
*	1. ������ ġŲ���� ������ ���ϴ� �����̴�. 
*  2. �� ��� DFS�� ���� ������ ���ϴ� ���� next_permutation���� ������ �����Ѵ�. 
*		-> next_permutation�� ��� �ߺ��� ������ �߻��Ͽ� �ð����⵵�� ũ�� �����Ѵ�. 
*/
using namespace std;
int M;
int answer = 1000000000;
void DFS(int index, int depth, vector<pair<int, int>>& chicken, vector<pair<int, int>>& home, vector<int> visited) {
	if (depth == M) {
		int sum_dist = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = 100000000;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j] == 1) {
					int dist_temp = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
					dist = min(dist, dist_temp);
				}
			}
			sum_dist += dist;
		}
		answer = min(answer, sum_dist);
		return;
	}
	for (int i = index; i < chicken.size(); i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			DFS(i + 1, depth + 1, chicken, home, visited);
			visited[i] = 0;
		}
	}
}

int main() {
	int N;
	cin >> N >> M;
	vector<pair<int, int>> chicken;
	vector<pair<int, int>> home;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 2) {
				chicken.push_back({ i,j });
			}
			else if (temp == 1) {
				home.push_back({ i,j });
			}
		}
	}
	vector<int> visited(int(chicken.size()), 0);

	DFS(0, 0, chicken, home, visited);


	cout << answer << endl;
}