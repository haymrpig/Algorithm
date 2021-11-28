#include <string>
#include <vector>
#include <queue>
/*
    ���� 16:55
    ���� 17:09
    1. ���� �յ��Ҽ��� ������ ���� �۴�.
    2. �켱���� ť�� �̿��Ͽ� ���� ū �Ϳ��� 1�� ���ִ� ���� n�� �ݺ��Ѵ�.
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