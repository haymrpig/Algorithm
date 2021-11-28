#include <vector>
#include <string>
#include <cstring>
#define INF 1000000000
using namespace std;
/*
    -Logic
    1. ��� ����� ���� Ȯ���ϵ�, dp�� ����Ͽ� �ð����⵵�� �����.
    2. �������� ������ ���Ͽ� �� �ȿ��� �켱 ����ϴ� �����ڸ� ������� �����Ѵ�.
    3. ������ �����ڴ�� ����� �� ��, �ִ밪 �Ǵ� �ּҰ��� dp�� �����Ѵ�.
    4. �ִ밪�� ���ؾ� �ϸ� +�� ��� ���� : �ִ�, ������ : �ִ�
                         -�� ��� ���� : �ִ�, ������ : �ּ�
       �ּҰ��� ���ؾ� �ϸ� +�� ��� ���� : �ּ�, ������ : �ּ�
                         -�� ��� ���� : �ּ�, ������ : �ִ�
    5. ���� dp�� ���ŵ� ���� �����ϸ� �ٽ� ����� �ʿ䰡 �����Ƿ� return
*/
int dp[100][100][2];
int calculateMax(vector<string>& arr, int start, int end, bool findMax) {
    int ret = dp[start][end][findMax];
    if (ret != -1) return ret;
    int left = 0, right = 0;
    ret = findMax == true ? -INF : INF;
    for (int i = start; i <= end; i++) {
        if (findMax == true) {
            left = i == start ? stoi(arr[2 * start]) : calculateMax(arr, start, i - 1, true);

            if (arr[2 * i + 1] == "+") {
                right = i == end ? stoi(arr[2 * (end + 1)]) : calculateMax(arr, i + 1, end, true);
                ret = max(ret, left + right);
            }
            else {
                right = i == end ? stoi(arr[2 * (end + 1)]) : calculateMax(arr, i + 1, end, false);
                ret = max(ret, left - right);
            }
        }
        else {
            left = i == start ? stoi(arr[2 * start]) : calculateMax(arr, start, i - 1, false);

            if (arr[2 * i + 1] == "+") {
                right = i == end ? stoi(arr[2 * (end + 1)]) : calculateMax(arr, i + 1, end, false);
                ret = min(ret, left + right);
            }
            else {
                right = i == end ? stoi(arr[2 * (end + 1)]) : calculateMax(arr, i + 1, end, true);
                ret = min(ret, left - right);
            }
        }
    }
    dp[start][end][findMax] = ret;
    return ret;
}
int solution(vector<string> arr)
{
    int answer = -1;
    memset(dp, -1, sizeof(dp));
    answer = calculateMax(arr, 0, arr.size() / 2 - 1, true);

    return answer;
}