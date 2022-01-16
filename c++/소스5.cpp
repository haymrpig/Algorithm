#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void CtrlMove(int direction, int x, int y, int& nx, int& ny, vector<vector<int>>& board) {
    if (direction == 0) {
        //down
        int i;
        for (i = x + 1; i < 4; i++) {
            if (board[i][y] == '0') continue;
            else break;
        }
        i = i == 4 ? 3 : i;
        nx = i;
        ny = y;
    }
    else if (direction == 1) {
        //up
        int i;
        for (i = x - 1; i >= 0; i--) {
            if (board[i][y] == '0') continue;
            else break;
        }
        i = i == -1 ? 0 : i;
        nx = i;
        ny = y;
    }
    else if (direction == 2) {
        // left
        int i;
        for (i = x - 1; i >= 0; i--) {
            if (board[x][i] == '0') continue;
            else break;
        }
        i = i == -1 ? 0 : i;
        nx = x;
        ny = i;
    }
    else if (direction == 3) {
        // right
        int i;
        for (i = x + 1; i < 4; i++) {
            if (board[x][i] == '0') continue;
            else break;
        }
        i = i == 4 ? 3 : i;
        nx = x;
        ny = i;
    }
    return;
}
void CalMinMove(vector<vector<int>>& board, vector<vector<int>>& dist, int& min_dist, int cur_x, int cur_y, int target_x, int target_y) {
    int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0,{cur_x, cur_y} });
    dist[cur_x][cur_y] = 0;
    while (!q.empty()) {
        int pre_x = q.front().second.first;
        int pre_y = q.front().second.second;
        int pre_depth = q.front().first;
        q.pop();
        if (target_x != -1) {
            if (pre_x == target_x && pre_y == target_y) {
                min_dist = pre_depth;
                return;
            }
        }
        for (int i = 0; i < 4; i++) {
            int next_x, next_y;
            CtrlMove(i, pre_x, pre_y, next_x, next_y, board);
            if (dist[next_x][next_y] > pre_depth + 1) {
                dist[next_x][next_y] = pre_depth + 1;
                q.push({ pre_depth + 1, {next_x, next_y} });
            }

            int nx = pre_x + dx[i];
            int ny = pre_y + dy[i];
            if (nx >= 0 && nx < 4 && ny >= 0 && ny<4 && dist[nx][ny]>pre_depth + 1) {
                dist[nx][ny] = pre_depth + 1;
                q.push({ pre_depth + 1, {nx,ny} });
            }
        }
    }
    min_dist = 1000000;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != target_y) continue;
            if (min_dist > dist[i][j]) {
                min_dist = dist[i][j];
                target_x = i;
                target_y = j;
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    vector<vector<int>> dist(4, vector<int>(4, 1000000));
    vector<vector<pair<int, int>>> answers(7);
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                count++;
                int num = board[i][j];
                answers[num].push_back({ i,j });
            }
        }
    }
    vector<int> order(count / 2);
    for (int i = 1; i <= count / 2; i++) {
        order.push_back(i);
    }

    do {
        vector<vector<int>> board_temp(board.begin(), board.end());
        for (int i = 0; i < order.size(); i++) {
            int number = order[i];
            int j, min_dist;
            vector<vector<int>> dist(4, vector<int>(4, 1000000));
            for (j = 0; j < 2; j++) {
                if (r == answers[number][j].first && c == answers[number][j].second) {
                    CalMinMove(board_temp, dist, min_dist, r, c, answers[number][1 - j].first, answers[number][1 - j].second);
                    board_temp[r][c] = 0;
                    board_temp[answers[number][1 - j].first][answers[number][1 - j].second] = 0;
                }
            }
            if (j > 2) {
                int r_temp = -1, c_temp = number;
                CalMinMove(board_temp, dist, min_dist, r, c, r_temp, c_temp);
                r = r_temp;
                c = c_temp;
                answer += min_dist;
                for (int p = 0; p < 4; p++) {
                    for (int q = 0; q < 4; q++) {
                        dist[i][j] = 1000000;
                    }
                }
                for (int k = 0; k < 2; k++) {
                    if (r == answers[number][k].first && c == answers[number][k].second) {
                        CalMinMove(board_temp, dist, min_dist, r, c, answers[number][1 - k].first, answers[number][1 - k].second);
                        board_temp[r][c] = 0;
                        board_temp[answers[number][1 - k].first][answers[number][1 - k].second] = 0;
                    }
                }
            }
            answer += min_dist;
        }
        cout << answer << endl;
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}