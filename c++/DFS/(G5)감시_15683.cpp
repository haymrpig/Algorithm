#include <iostream>
#include <vector>

/*
*   이 문제는 오류를 찾는데 특히나 오래 걸렸던 것 같다...
*   
*   간과한 오류들
*   1. cctv가 감시할 수 있는 영역을 체크할 때, cctv로부터 뻗어나가야 벽에 막힐 때 break되는데,
*       이 점을 생각 못하고, 바깥쪽에서 cctv로 들어가는 코드를 작성했다. 
*       -> cctv로부터 뻗어나가도록 수정하여 해결
* 
*   2. cctv가 한대도 없는 경우를 생각을 안하고, answer에 최대값인 NxM을 넣어줬다.
*       -> 처음 사무실을 입력받을 때, 빈공간을 세어 answer에 넣어 해결
* 
*   3. 작은 실수지만, NxM 배열을 만들어야 되는데, 습관처럼 NxN 배열을 만듬 ㅠ
*   
*   4. cctv를 입력받을 땐, 1,2,3,4,5로 받았는데, 정작 cctv 배열을 0,1,2,3,4로 만듬
*       -> cctv배열을 6칸으로 만들어서 해결
* 
*   !!!!! 반복되는 코드를 복사할 때는 주의하자 !!!!!
*   
*/
using namespace std;
int N, M;
int answer=0;

void rotate(vector<bool>& cctv) {
    bool temp = cctv[0];
    for (int i = 1; i < 4; i++) {
        cctv[i - 1] = cctv[i];
    }
    cctv[3] = temp;
    return;
}

void update(vector<vector<int>>& room, vector<bool>& cctv, pair<int, int>& pos) {
    int x = pos.first;
    int y = pos.second;
    for (int i = 0; i < 4; i++) {
        if (cctv[i] == true) {
            if (i == 0) {
                for (int j = x-1; j >= 0; j--) {
                    if (room[j][y] == 6) break;
                    if (room[j][y] != 0) continue;
                    room[j][y] = 7;
                }
            }
            else if (i == 1) {
                for (int j = y + 1; j < M; j++) {
                    if (room[x][j] == 6) break;
                    if (room[x][j] != 0) continue;
                    room[x][j] = 7;
                }
            }
            else if (i == 2) {
                for (int j = x + 1; j < N; j++) {
                    if (room[j][y] == 6) break;
                    if (room[j][y] != 0) continue;
                    room[j][y] = 7;
                }
            }
            else {
                for (int j = y-1; j >= 0; j--) {
                    if (room[x][j] == 6) break;
                    if (room[x][j] != 0) continue;
                    room[x][j] = 7;
                }
            }
        }
    }
}


int count(vector<vector<int>>& room) {
    int vacant=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (room[i][j] == 0) vacant++;
        }
    }

    return vacant;
}

void check(vector<vector<int>>& room, vector<vector<bool>>& cctv, vector<pair<int, pair<int, int>>>& pos, int idx, int depth) {
    if (depth == pos.size()) {
        answer = min(answer, count(room));
        return;
    }
    for (int i = idx; i < pos.size(); i++) {
        for (int j = 0; j < 4; j++) {
            vector<vector<int>> temp(room.begin(), room.end());
            rotate(cctv[pos[i].first]);
            update(temp, cctv[pos[i].first], pos[i].second);
            check(temp, cctv, pos, i + 1, depth+1);
        }
    }
    return;
}


int main() {
    cin >> N >> M;
    vector<vector<int>> room(N, vector<int>(M));
    vector < pair<int,pair<int, int>>> pos;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
            if (room[i][j] != 0 && room[i][j] != 6) {
                pos.push_back({ room[i][j],{ i,j } });
            }
            if (room[i][j] == 0) answer++;
        }
    }
    vector<vector<bool>> cctv(6, vector<bool>(4, false));
    cctv[1][1] = true;
    cctv[2][1] = true; cctv[2][3] = true;
    cctv[3][0] = true; cctv[3][1] = true;
    cctv[4][0] = true; cctv[4][1] = true; cctv[4][3] = true;
    cctv[5][0] = true; cctv[5][1] = true; cctv[5][2] = true; cctv[5][3] = true;

    check(room, cctv, pos, 0, 0);

    cout << answer;
}
