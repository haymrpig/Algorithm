#include <string>
#include <vector>
#define INF 1000000000000000000
using namespace std;
// 값의 범위가 매우 크므로 이진 탐색으로 답을 구해야 한다. 
// 시간에 대해 최대 가능한 시간과 최소 시간을 이진 탐색으로, 각 시간마다의 심사되는 사람의 수를 기준으로
// 낮은 쪽을 탐색할지, 높은 쪽을 탐색할지 결정하게 된다.
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start = 1;
    long long end = INF;
    long long num = 0;
    long long mid = 0;

    while (start <= end) {
        num = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < times.size(); i++) {
            num += (mid / times[i]);
        }
        if (num < n) {
            start = mid + 1;
        }
        else {
            answer = mid;
            end = mid - 1;
        }
    }
    return answer;
}