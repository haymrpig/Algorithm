#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
/*
*	1. 가능한 치킨집의 조합을 구하는 문제이다. 
*  2. 이 경우 DFS를 통해 조합을 구하는 것이 next_permutation보다 빠르게 동작한다. 
*		-> next_permutation의 경우 중복이 여러번 발생하여 시간복잡도가 크게 증가한다. 
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