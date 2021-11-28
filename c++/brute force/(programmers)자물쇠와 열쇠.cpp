#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    시작 22:23
    종료 00:09
    1. 특별한 규칙 없이 전체 탐색을 하는 경우이다. 
    2. convolution 구현 과정에서 오래 걸렸다. 자물쇠의 영역을 벗어난 구간이 존재하기 때문에 미리 전체 board를 kernel이 탐색하는 범위까지 늘려준다. 
*/

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int keySize = key.size();
    int lockSize = lock.size();
    vector<vector<int>> board(lockSize + 2 * keySize - 2, vector<int>(lockSize + 2 * keySize - 2, -1));

    int holeNum = 0;
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (lock[i][j] == 0) {
                holeNum++;
            }
            board[i + keySize - 1][j + keySize - 1] = lock[i][j];
        }
    }


    vector<vector<int>> rotated(keySize, vector<int>(keySize, 0));
    for (int i = 0; i < 4; i++) {
        // key 회전
        for (int j = 0; j < keySize; j++) {
            for (int k = 0; k < keySize; k++) {
                rotated[k][keySize - j - 1] = key[j][k];
            }
        }
        key = rotated;

        for (int j = 0; j < keySize + lockSize - 1; j++) {
            for (int k = 0; k < keySize + lockSize - 1; k++) {
                int cnt = 0, flag = 0;
                for (int p = 0; p < keySize; p++) {
                    for (int q = 0; q < keySize; q++) {
                        if (board[p + j][q + k] == -1 || key[p][q] == 0) continue;
                        if (board[p + j][q + k] == 1 && key[p][q] == 1) {
                            flag = 1;
                            break;
                        }
                        else {
                            cnt++;
                        }
                    }
                    if (flag) break;
                }
                if (cnt == holeNum) return true;
            }
        }
    }


    return answer;
}