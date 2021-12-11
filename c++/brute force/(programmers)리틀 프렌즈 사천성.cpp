#include <string>
#include <vector>
#include <map>
using namespace std;

// 가능한 경로는 4가지
// x나 y가 같은 경우 : 일직선 ( 세로, 가로 )
// x와 y 둘 다 다른 경우 : 하나의 타일의 x/y, 다른 타일의 y/x 경로
// 탐색할 때 여러가지 삭제하는 순서가 있을 때는 알파벳 순으로 삭제해야 하므로
// 알파벳 개수만큼 loop를 돌리고, 삭제되는 돌이 있을 때마다 break를 걸어 다시 처음 알파벳부터 검색하도록 하였다. 

bool check(vector<string>& board, vector<pair<int, int>> s) {
    int x1 = s[0].first, y1 = s[0].second;
    int x2 = s[1].first, y2 = s[1].second;

    if (x1 == x2) {
        for (int i = y1 + 1; i < y2; i++) {
            if (board[x1][i] != '.') return false;
        }
        board[x1][y1] = '.';
        board[x2][y2] = '.';
        return true;
    }
    else if (y1 == y2) {
        for (int i = x1 + 1; i < x2; i++) {
            if (board[i][y1] != '.') return false;
        }
        board[x1][y1] = '.';
        board[x2][y2] = '.';
        return true;
    }
    else {
        string possible = "1111";
        if (y1 < y2) {
            for (int i = y1 + 1; i <= y2; i++) {
                if (board[x1][i] != '.') {
                    possible[0] = 0;
                    break;
                }
            }
            for (int i = x1; i < x2; i++) {
                if (board[i][y2] != '.') {
                    possible[1] = 0;
                    break;
                }
            }
            for (int i = y1; i < y2; i++) {
                if (board[x2][i] != '.') {
                    possible[2] = 0;
                    break;
                }
            }
            for (int i = x1 + 1; i <= x2; i++) {
                if (board[i][y1] != '.') {
                    possible[3] = 0;
                    break;
                }
            }
            if ((possible[0] && possible[1]) || (possible[2] && possible[3])) {
                board[x1][y1] = '.';
                board[x2][y2] = '.';
                return true;
            }
            return false;
        }
        else {
            for (int i = y2; i < y1; i++) {
                if (board[x1][i] != '.') {
                    possible[0] = 0;
                    break;
                }
            }
            for (int i = x1; i < x2; i++) {
                if (board[i][y2] != '.') {
                    possible[1] = 0;
                    break;
                }
            }
            for (int i = y2 + 1; i <= y1; i++) {
                if (board[x2][i] != '.') {
                    possible[2] = 0;
                    break;
                }
            }
            for (int i = x1 + 1; i <= x2; i++) {
                if (board[i][y1] != '.') {
                    possible[3] = 0;
                    break;
                }
            }
            if ((possible[0] && possible[1]) || (possible[2] && possible[3])) {
                board[x1][y1] = '.';
                board[x2][y2] = '.';
                return true;
            }
            return false;
        }
    }
}
string solution(int m, int n, vector<string> board) {
    string answer = "";
    int cnt = 0;
    vector<string> board_copy(board.begin(), board.end());
    vector<vector<pair<int, int>>> s(26);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            char c = board[i][j];
            if ('A' <= c && c <= 'Z')
            {
                s[c - 'A'].push_back({ i,j });
                cnt++;
            }
        }
    }
    for (int k = 0; k < s.size() + 1; k++) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i].size() > 0) {
                if (board[s[i][0].first][s[i][0].second] == '.') continue;
                if (check(board, s[i])) {
                    answer += board_copy[s[i][0].first][s[i][0].second];
                    break;
                }
            }
        }
    }
    if (answer.size() != cnt / 2) return "IMPOSSIBLE";
    return answer;
}