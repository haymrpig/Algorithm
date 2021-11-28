#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000000000
/*
    - Logic
    1. n�� ������ 50000�̹Ƿ� DFS���� Ž��������δ� �ð��ʰ��� �߻��Ѵ�.
    2. �Ÿ��� �������� �̺�Ž���� ����
        -> ���� �Ÿ����� ������ ���� ���, �� ���� + �� ���� ���� Cnt+1
        -> ������ ���� ������ n���� ���� ���, ���� �Ÿ� ����
        -> ������ ���� ������ n���� Ŭ ���, ���� �Ÿ� ���� + ���信 ���ذŸ� ����

    !!! Ž���� ���� ������ ū ��� �̺� Ž�� �̿� !!!
    !!! �Ÿ��� �������� ������ �̿��Ͽ� �̺� Ž���� ������ �� �ִ� !!!
*/
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());

    int eraseCnt = 0;
    int mid = 0;
    int start = 0;
    int end = MAX;
    int preIndex = -1;
    int dist = 0;

    while (start <= end) {
        eraseCnt = 0;
        preIndex = -1;
        mid = (start + end) / 2;
        for (int i = 0; i <= rocks.size(); i++) {
            if (i == 0) dist = rocks[i];
            else {
                if (i == rocks.size()) dist = distance - rocks[i - 1];
                else dist = rocks[i] - rocks[preIndex];
            }
            if (dist < mid) eraseCnt++;
            else preIndex = i;
        }
        if (eraseCnt > n) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
            answer = mid;
        }
    }
    return answer;
}