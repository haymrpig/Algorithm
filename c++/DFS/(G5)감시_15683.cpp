#include <iostream>
#include <vector>

/*
*   �� ������ ������ ã�µ� Ư���� ���� �ɷȴ� �� ����...
*   
*   ������ ������
*   1. cctv�� ������ �� �ִ� ������ üũ�� ��, cctv�κ��� ������� ���� ���� �� break�Ǵµ�,
*       �� ���� ���� ���ϰ�, �ٱ��ʿ��� cctv�� ���� �ڵ带 �ۼ��ߴ�. 
*       -> cctv�κ��� ��������� �����Ͽ� �ذ�
* 
*   2. cctv�� �Ѵ뵵 ���� ��츦 ������ ���ϰ�, answer�� �ִ밪�� NxM�� �־����.
*       -> ó�� �繫���� �Է¹��� ��, ������� ���� answer�� �־� �ذ�
* 
*   3. ���� �Ǽ�����, NxM �迭�� ������ �Ǵµ�, ����ó�� NxN �迭�� ���� ��
*   
*   4. cctv�� �Է¹��� ��, 1,2,3,4,5�� �޾Ҵµ�, ���� cctv �迭�� 0,1,2,3,4�� ����
*       -> cctv�迭�� 6ĭ���� ���� �ذ�
* 
*   !!!!! �ݺ��Ǵ� �ڵ带 ������ ���� �������� !!!!!
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
