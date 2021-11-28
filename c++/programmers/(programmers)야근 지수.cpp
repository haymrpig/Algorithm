#include <string>
#include <vector>
#include <queue>
/*
    시작 16:55
    종료 17:09
    1. 값이 균등할수록 제곱의 합이 작다.
    2. 우선순위 큐를 이용하여 값이 큰 것에서 1씩 빼주는 것을 n번 반복한다.
*/
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < works.size(); i++) pq.push(works[i]);

    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp = pq.top();
        if (temp == 0) return 0;
        pq.pop();
        pq.push(temp - 1);
    }
    while (!pq.empty()) {
        temp = pq.top();
        answer += (temp * temp);
        pq.pop();
    }
    return answer;
}