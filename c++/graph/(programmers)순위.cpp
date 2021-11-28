#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    ���� 21:28
    ���� 21:58
    Ǯ�� 1 ( ���� Ǭ �� )
    - ��� ��尡 �ٸ� ��� ������ �̱�� ���� ���谡 ��Ȯ�ؾ� �Ѵ�. 
    - ���� �迭�� �̱�� ��� 2, ���� ��� 1, ���谡 ���� ��� 0���� �ʱ� setting�� �Ѵ�. 
    - 1�� ������ ���谡 �ִ� ��带 Ž���Ѵ�. 
        -> ���� 1���� �� ��带 �̰�ٸ�( 2��� ) �� ��尡 �̱� ������ 1������ ���谡 ��Ȯ������. ( 1���� ��θ� �̱� )
        -> ���� 1���� �� ��忡�� ���ٸ�( 1�̶�� ) �� ��尡 �� ������ 1������ ���谡 ��Ȯ������. ( 1���� ��ο��� �� )
    - �̷��� ������� 1������ n������ Ž���ϰ�, �� ������ n-1�� �ݺ��ϸ� ��� ������ ���谡 �����ȴ�. 
    - 4�� for�������� n�� ������ 100�����̹Ƿ� O(n^4)���� �ð��ȿ� �ذ��� �����ϴ�.

    ****�� Ǯ�̺��� ���� Ǯ�̰� �־� �Ʒ� ������ ���Ҵ�.****
 */

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> output(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < results.size(); i++) {
        int win = results[i][0];
        int lose = results[i][1];
        output[win][lose] = 2;
        output[lose][win] = 1;
    }

    for (int p = 0; p < n-1; p++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (output[i][j] != 0) {
                    int winLose = output[i][j];
                    for (int k = 1; k < n + 1; k++) {
                        if (k == j || k == i) continue;
                        if (output[j][k] == winLose) output[i][k] = winLose;
                    }
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        int sum = 0;
        for (int j = 1; j < n + 1; j++) {
            if (output[i][j] == 0) sum++;
        }
        if (sum > 1) continue;
        answer++;
    }

    return answer;
}

/*
    Ǯ�� 2
    - �÷��̵� ���� �˰����� ������ Ǯ���̴�. 
    - Ǯ��1������ �̱�� ���� ���踦 ����������, ���⼭�� �̱�� ���踸 �����Ѵ�. 
        -> �÷��̵� ���������� ���İ� �� �ִ� ��� ��带 Ž���Ͽ� ����ġ�� ����������, �� ��쿡�� �̱�� ���θ� ��带 Ž���Ѵ�. 
        -> ��, ���� ��尡 Ȯ���ϰ� �̱�� ��忡 ���ؼ��� ���踦 ������ ���̴�. 
    - Ž�� ����� output ���߹迭�� �����Ѵ�. 
    - i��° �����  j��° ������ ���� output[i][j] + output[j][i]�� ��� ���� �ڱ��ڽ��� ������ n-1�̶�� ������ �ű� �� �ִ�. 
        -> output[i][j]�� i�� �̱�� ���
        -> output[j][i]�� i�� ���� ���
        -> i�� ���� �̱���� ���谡 ��Ȯ�ϸ� ������ �ű� �� �ִ�. 
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> output(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < results.size(); i++) {
        int win = results[i][0];
        int lose = results[i][1];
        output[win][lose] = 1;
    }

    for (int k = 1; k < n + 1; k++) {
        // ���İ��� ��� 
        for (int i = 1; i < n + 1; i++) {
            // ��� ���
            for (int j = 1; j < n + 1; j++) {
                // �� ��� 
                if (output[i][k] && output[k][j]) output[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        int sum = 0;
        for (int j = 1; j < n + 1; j++) {
            sum += (output[i][j] + output[j][i]);
        }
        if (sum == n - 1) answer++;
    }

    return answer;
}