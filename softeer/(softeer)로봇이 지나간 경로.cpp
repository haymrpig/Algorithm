#include<iostream>
#include<vector>
#include<queue>
//시작시간 15:30
using namespace std;
// 두가지 가능성
// 1. cycle이 존재 -> 동서남북으로 두개 만나는 어떤 점이든 상관없이 시작하면 된다.
// 2. cycle이 존재 x -> 동서남북으로 한개 만나는 점부터 시작
vector<pair<int, int>> findFirstPoint(int dx[4], int dy[4], int H, int W, vector<vector<char>> map) {
    int first = 1;
    vector<pair<int, int>> temp(1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '#') {
                int cnt = 0, preIndex = 0;
                for (int k = 0; k < 4; k++) {
                    int x = dx[k] + i, y = dy[k] + j;
                    if (x < 0 || y < 0 || x >= H || y >= W) continue;
                    if ( map[x][y] == '#') {
                        cnt++;
                    }
                    if (cnt == 1) preIndex = k;
                    else if (cnt > 1) {
                        if ((preIndex == 0 && k == 1) || (preIndex == 2 && k == 3)) continue;
                        else {
                            temp[0] = { i,j };
                        }
                    }
                }

                if (cnt == 1) {
                    temp[0] = { i,j };
                    return temp;
                }
            }
        }
    }
    return temp;

}

int main(int argc, char** argv)
{
    int H = 0, W = 0;
    cin >> H >> W;
    vector<vector<char>> map(H, vector<char>(W, 0));
    vector<vector<char>> visited(H, vector<char>(W, 0));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    
    int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
    char direction[4] = { 'v','^','>','<' };
    vector<pair<int, int>> startPoint = findFirstPoint(dx, dy, H, W, map);
    string ans = "";
    queue<pair<int, int>> q;
    
    q.push(startPoint[0]);
    visited[startPoint[0].first][startPoint[0].second] = 1;
    int flag = 1;
    char predirection;
    
    while (!q.empty()) {
        int prex = q.front().first;
        int prey = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextx = dx[i] + prex, nexty = dy[i] + prey;
           
            if (nextx<0 || nexty<0 || nextx>=H || nexty>=W) continue;
            if (map[nextx][nexty] == '#' && visited[nextx][nexty] == 0) {
                if (flag) {
                    ans += direction[i];
                    predirection = i;
                    flag=0;
                }
                if (predirection != i) {
                    if (predirection == 0 || predirection == 1)
                        if (i == predirection + 2) ans += 'L';
                        else ans += 'R';
                    else {
                        if (i == (predirection + 2) % 4) ans += 'R';
                        else ans += 'L';
                    }
                    predirection = i;
                }
                visited[nextx][nexty] = 1;
                ans += 'A';
                nextx += dx[i];
                nexty += dy[i];
                visited[nextx][nexty] = 1;
                q.push({ nextx, nexty });
            }
        }
    }
    cout << startPoint[0].first << " " << startPoint[0].second << '\n';
    cout << ans[0] << '\n';
    ans.erase(0, 1);
    cout << ans << '\n';
    

    return 0;
}