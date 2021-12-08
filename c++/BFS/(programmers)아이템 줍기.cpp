#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 1000000000;
    int N = 51;
    vector<vector<int>> map(N * 2, vector<int>(N * 2, 0));
    vector<vector<int>> visited(map.begin(), map.end());
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                map[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        for (int i = x1 + 1; i < x2; i++) {
            for (int j = y1 + 1; j < y2; j++) {
                map[i][j] = 0;
            }
        }
    }
    int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, {2 * characterX, 2 * characterY} });
    visited[2 * characterX][2 * characterY] = 1;
    while (!q.empty()) {
        int dist = q.front().first;
        int px = q.front().second.first;
        int py = q.front().second.second;
        q.pop();
        if (px == 2 * itemX && py == 2 * itemY) {
            answer = dist / 2;
        }
        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (nx < 0 || nx >= 2 * N || ny < 0 || ny >= 2 * N || visited[nx][ny] == 1 || map[nx][ny] == 0) continue;
            visited[nx][ny] = 1;
            q.push({ dist + 1,{nx,ny} });
        }
    }
    return answer;
}