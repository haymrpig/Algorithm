#include <string>
#include <vector>

using namespace std;
// 규칙을 찾아내는 것이 중요!
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    while (left <= right) {
        int i = left / n;
        int j = left % n;
        answer.push_back(max(i, j) + 1);
        left++;
    }
    return answer;
}