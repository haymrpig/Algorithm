#include <string>
#include <vector>
#define INF 1000000000000000000
using namespace std;
// ���� ������ �ſ� ũ�Ƿ� ���� Ž������ ���� ���ؾ� �Ѵ�. 
// �ð��� ���� �ִ� ������ �ð��� �ּ� �ð��� ���� Ž������, �� �ð������� �ɻ�Ǵ� ����� ���� ��������
// ���� ���� Ž������, ���� ���� Ž������ �����ϰ� �ȴ�.
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