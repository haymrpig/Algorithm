#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define INF 1000000000
// 10:40
// DFS알고리즘을 이용하였다. 
/*
*   1. 사람의 위치를 DFS로 찾는 queue
*   2. 비의 위치를 DFS로 찾는 queue
*   3. 비의 이동이 먼저 시행되어야함
*   4. 비, 강, 현재 위치를 visited한 노드라고 생각
*/
using namespace std;
int main(int argc, char** argv)
{
    int w = 0, h = 0;
    cin >> h >> w;
    int endx = 0, endy = 0;
    vector<vector<int>> visited(h, vector<int>(w, 0));
    int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
    queue<pair<int, int>> qRain;
    queue<pair<int, int>> qPerson;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char temp;
            cin >> temp;
            if (temp == 'W') {
                qPerson.push({ i,j });
                visited[i][j] = 1;
            }
            else if (temp == 'H') {
                endx = i;
                endy = j;
            }
            else if (temp == '*') {
                qRain.push({ i,j });
                visited[i][j] = 1;
            }
            else if (temp == 'X')
                visited[i][j] = 1;
        }
    }
    int ans = 0;
    while (!qPerson.empty()) {
        int qRainSize = qRain.size();
        while (qRainSize--) {
            int prex = qRain.front().first;
            int prey = qRain.front().second;
            qRain.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = prex + dx[i];
                int nexty = prey + dy[i];
                if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w || visited[nextx][nexty] == 1 || (nextx == endx && nexty == endy)) continue;
                visited[nextx][nexty] = 1;
                qRain.push({ nextx, nexty });
            }
        }
        int qPersonSize = qPerson.size();
        while (qPersonSize--) {
            int prex = qPerson.front().first;
            int prey = qPerson.front().second;
            qPerson.pop();
            if (endx == prex && endy == prey) {
                cout << ans << '\n';
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                int nextx = prex + dx[i];
                int nexty = prey + dy[i];
                if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w || visited[nextx][nexty] == 1) continue;
                visited[nextx][nexty] = 1;
                qPerson.push({ nextx,nexty });
            }
        }
        ans++;
    }
    cout << "FAIL" << '\n';

    return 0;
}