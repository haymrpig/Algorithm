#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 100000000
using namespace std;
int node;
/*
	1. 첫 시도로 플로이드 워샬 알고리즘을 통해 모든 노드 사이의 최단거리를 구하였다. -> 시간 초과
	2. 두 번째 시도로 다익스트라 알고리즘을 시작 노드, 거쳐야 하는 두 노드 총 세번 계산하여 진행하였다. -> 성공
*/
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int edge=0, dest=0;
		cin >> node >> edge >> dest;
		int startNode = 0, gothrough1 = 0, gothrough2 = 0;
		cin >> startNode >> gothrough1 >> gothrough2;

		vector<pair<int, int>> info[2001];
		vector<int> dist(node + 1, INF);
		vector<int> dist1(node + 1, INF);
		vector<int> dist2(node + 1, INF);
		dist[startNode] = 0;
		dist1[gothrough1] = 0;
		dist2[gothrough2] = 0;
		while (edge--) {
			int v1 = 0, v2 = 0, weight = 0;
			cin >> v1 >> v2 >> weight;
			info[v1].push_back({ v2,weight });
			info[v2].push_back({ v1,weight });
		}

		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

		pq.push({ 0,startNode });
		while (!pq.empty()) {
			int preWeight = pq.top().first;
			int preIndex = pq.top().second;
			pq.pop();
			for (int i = 0; i < info[preIndex].size(); i++) {
				int nextIndex = info[preIndex][i].first;
				int weightSum = preWeight + info[preIndex][i].second;
				if (dist[nextIndex] > weightSum) {
					dist[nextIndex] = weightSum;
					pq.push({ weightSum, nextIndex });
				}
			}
		}
		while (!pq.empty()) pq.pop();
		pq.push({ 0,gothrough1 });
		while (!pq.empty()) {
			int preWeight = pq.top().first;
			int preIndex = pq.top().second;
			pq.pop();
			for (int i = 0; i < info[preIndex].size(); i++) {
				int nextIndex = info[preIndex][i].first;
				int weightSum = preWeight + info[preIndex][i].second;
				if (dist1[nextIndex] > weightSum) {
					dist1[nextIndex] = weightSum;
					pq.push({ weightSum, nextIndex });
				}
			}
		}
		while (!pq.empty()) pq.pop();
		pq.push({ 0,gothrough2 });
		while (!pq.empty()) {
			int preWeight = pq.top().first;
			int preIndex = pq.top().second;
			pq.pop();
			for (int i = 0; i < info[preIndex].size(); i++) {
				int nextIndex = info[preIndex][i].first;
				int weightSum = preWeight + info[preIndex][i].second;
				if (dist2[nextIndex] > weightSum) {
					dist2[nextIndex] = weightSum;
					pq.push({ weightSum, nextIndex });
				}
			}
		}


		/*
		vector<vector<int>> dist(node+1, vector<int>(node + 1, INF));
		for (int i = 1; i <= node; i++) dist[i][i] = 0;
		while (edge--) {
			int v1 = 0, v2 = 0, weight = 0;
			cin >> v1 >> v2 >> weight;
			dist[v1][v2] = weight;
			dist[v2][v1] = weight;
		}
		
		for (int k = 1; k <= node; k++) {
			for(int i=1;i<=node;i++){
				for (int j = 1; j <= node; j++) {
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		*/

		vector<int> answer;
		while (dest--) {
			int temp;
			cin >> temp;
			/*
			if (dist[startNode][temp] == dist[startNode][gothrough1] + dist[gothrough1][gothrough2] + dist[gothrough2][temp]  
				|| dist[startNode][temp] == dist[startNode][gothrough2] + dist[gothrough2][gothrough1] + dist[gothrough1][temp])
				answer.push_back(temp);
			*/
			if (dist[temp] == dist[gothrough1] + dist1[gothrough2]+ dist2[temp]
				|| dist[temp] == dist[gothrough2] +dist2[gothrough1]+ dist1[temp])
				answer.push_back(temp);
		}
		sort(answer.begin(), answer.end());
		for (auto x : answer) cout << x << ' ';
		cout << "\n";

	}
}