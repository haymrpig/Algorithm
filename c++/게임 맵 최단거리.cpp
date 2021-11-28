#include<vector>
#include<queue>
#include<iostream>
#define INF 10001
using namespace std;
// 시작시간 20:57
// 종료시간 22:15
// 처음에 BFS, DFS 두 종류로 풀었다가 DFS는 시간초과로 인해 BFS로 풀게 되었다.

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int h = maps.size() - 1;
    int w = maps[0].size() - 1;
    queue<pair<int, int>> q; // (x,y)
    vector<vector<int>> check(h + 1, vector<int>(w + 1, 0));
    vector<vector<int>> dist(h + 1, vector<int>(w + 1, INF));

    int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
    dist[0][0] = 1;
    check[0][0] = 1;
    q.push({ 0,0 });
    while (!q.empty()) {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();
        if (px == h && py == w) return dist[px][py];
        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (nx<0 || ny<0 || nx>h || ny>w || check[nx][ny] == 1 || maps[nx][ny] == 0) continue;
            q.push({ nx,ny });
            dist[nx][ny] = dist[px][py] + 1;
            check[nx][ny] = 1;
        }
    }

    return -1;
}