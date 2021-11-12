#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    ���� 22:23
    ���� 00:09
    1. Ư���� ��Ģ ���� ��ü Ž���� �ϴ� ����̴�. 
    2. convolution ���� �������� ���� �ɷȴ�. �ڹ����� ������ ��� ������ �����ϱ� ������ �̸� ��ü board�� kernel�� Ž���ϴ� �������� �÷��ش�. 
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
        // key ȸ��
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