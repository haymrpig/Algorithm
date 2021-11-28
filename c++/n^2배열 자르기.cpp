#include <string>
#include <vector>

using namespace std;
// ��Ģ�� ã�Ƴ��� ���� �߿�!
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