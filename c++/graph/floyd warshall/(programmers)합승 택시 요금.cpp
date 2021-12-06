#include <string>
#include <vector>
#include <iostream>
#define INF 100000000
using namespace std;

/*
    -Logic
    1. ��� ��� ���� �ִ� �Ÿ��� �÷��̵� ���� �˰����� ���� ���Ѵ�.
    2. ���� ���� ���� ��츦 �ּ� �Ÿ��� ����
    3. ��� ��带 �˻��ϸ鼭 ���������� �ش� �������� ���� �̵��Ѵ� �����ϰ�, �ش� ������ a,b�� ���� �ִ� �Ÿ��� ���Ѵ�.
    4. ���� 3������ ���� ���� �ּ��̸� update

    �Ǵٸ� Ǯ�̷δ� a,b�� �����������ؼ� ��� ��带 dijkstra�˰������� �ִ� �Ÿ��� ���Ѵ�.
    3�� �ݺ�
    -> �� Ǯ���� ��� �ð����⵵�� �÷��̵� ������ ���� ���� ������ �ִ�.
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