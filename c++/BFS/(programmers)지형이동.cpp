#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1000000000
using namespace std;

/*
    -Logic
    1. 우선순위 큐를 이용하여 블록 사이 거리를 기준으로 큐 내부에서 오름차순으로 정렬되게 한다. ( 사다리가 필요없는 경우가 가장 먼저 나온다. )
    2. 만약 사다리가 필요없는 경우는 모두 탐색했다면, 하나의 영역이 생겼을 것이고, 다른 영역과의 연결점 중 사다리값이 가장 작은 블록이 queue에 들어있을 것이다. -> 1번 반복
    3. pop()하면서 나온 weight를 모두 더하면 정답이다. ( 이전 블록에서 pop()한 블록 사이 차이이니깐 )
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