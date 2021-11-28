#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1000000000
using namespace std;

/*
    -Logic
    1. �켱���� ť�� �̿��Ͽ� ��� ���� �Ÿ��� �������� ť ���ο��� ������������ ���ĵǰ� �Ѵ�. ( ��ٸ��� �ʿ���� ��찡 ���� ���� ���´�. )
    2. ���� ��ٸ��� �ʿ���� ���� ��� Ž���ߴٸ�, �ϳ��� ������ ������ ���̰�, �ٸ� �������� ������ �� ��ٸ����� ���� ���� ����� queue�� ������� ���̴�. -> 1�� �ݺ�
    3. pop()�ϸ鼭 ���� weight�� ��� ���ϸ� �����̴�. ( ���� ��Ͽ��� pop()�� ��� ���� �����̴ϱ� )
*/
int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int N = land.size();
    vector<vector<int>> d(N, vector<int>(N, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0,{0,0} });
    int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
    while (!pq.empty()) {
        int prew = pq.top().first;
        int px = pq.top().second.first;
        int py = pq.top().second.second;
        pq.pop();
        if (visited[px][py]) continue;
        visited[px][py] = true;
        d[px][py] = prew;
        answer += prew;
        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (nx >= N || nx < 0 || ny >= N || ny < 0 || visited[nx][ny]) continue;
            int diff = abs(land[px][py] - land[nx][ny]);
            diff = diff > height ? diff : 0;
            pq.push({ diff, {nx, ny} });
        }
    }

    return answer;
}