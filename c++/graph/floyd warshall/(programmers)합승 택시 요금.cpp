#include <string>
#include <vector>
#include <iostream>
#define INF 100000000
using namespace std;

/*
    -Logic
    1. 모든 노드 사이 최단 거리를 플로이드 워샬 알고리즘을 통해 구한다.
    2. 먼저 따로 가는 경우를 최소 거리로 삽입
    3. 모든 노드를 검사하면서 시작점부터 해당 노드까지를 같이 이동한다 가정하고, 해당 노드부터 a,b로 가는 최단 거리를 더한다.
    4. 만약 3번에서 구한 값이 최소이면 update

    또다른 풀이로는 a,b를 시작점으로해서 모든 노드를 dijkstra알고리즘으로 최단 거리를 구한다.
    3번 반복
    -> 이 풀이의 경우 시간복잡도가 플로이드 워샬에 비해 적은 장점이 있다.
*/
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < fares.size(); i++) {
        int start = fares[i][0];
        int end = fares[i][1];
        int weight = fares[i][2];
        map[start][end] = weight;
        map[end][start] = weight;
    }
    vector<vector<int>> dist(map.begin(), map.end());
    for (int i = 0; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    answer = dist[s][a] + dist[s][b];
    answer = answer == 2 * INF ? -1 : answer;
    for (int i = 1; i <= n; i++) {
        if (dist[s][i] != INF && dist[i][a] != INF && dist[i][b] != INF) {
            if (answer > dist[s][i] + dist[i][a] + dist[i][b]) {
                answer = dist[s][i] + dist[i][a] + dist[i][b];
            }
        }
    }
    return answer;
}