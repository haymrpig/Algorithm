#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main(int argc, char** argv)
{
    int height = 0, width = 0;
    cin >> height >> width;
    vector<vector<int>> info(height, vector<int>(width, 0));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int temp;
            cin >> temp;
            info[i][j] = temp;
        }
    }

    queue<pair<int, int>> q;
    int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
    int cnt = 0;

    while (1) {
        map<pair<int, int>, int> m;
        vector<vector<int>> visited(height, vector<int>(width, 0));
        q.push({ 0,0 });
        visited[0][0] = 1;
        while (!q.empty()) {
            int prex = q.front().first;
            int prey = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nextx = prex + dx[k];
                int nexty = prey + dy[k];
                if (nextx < 0 || nextx >= height || nexty < 0 || nexty >= width || visited[nextx][nexty] == 1) continue;

                if (info[nextx][nexty] == 0) {
                    visited[nextx][nexty] = 1;
                    q.push({ nextx,nexty });
                }
                else {
                    if (++m[{nextx, nexty}] == 2) {
                        info[nextx][nexty] = 0;
                        visited[nextx][nexty] = 1;
                    }
                }
            }
        }
        if (m.size() == 0) break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}