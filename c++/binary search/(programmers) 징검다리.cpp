#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000000000
/*
    - Logic
    1. n의 범위가 50000이므로 DFS같은 탐색방법으로는 시간초과가 발생한다.
    2. 거리를 기준으로 이분탐색을 진행
        -> 기준 거리보다 간격이 작은 경우, 돌 삭제 + 돌 삭제 개수 Cnt+1
        -> 삭제한 돌의 개수가 n보다 작을 경우, 기준 거리 증가
        -> 삭제한 돌의 개수가 n보다 클 경우, 기준 거리 감소 + 정답에 기준거리 저장

    !!! 탐색할 값의 범위가 큰 경우 이분 탐색 이용 !!!
    !!! 거리를 기준으로 개수를 이용하여 이분 탐색을 적용할 수 있다 !!!
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