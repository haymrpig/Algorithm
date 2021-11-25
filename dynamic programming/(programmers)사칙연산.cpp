#include <vector>
#include <string>
#include <cstring>
#define INF 1000000000
using namespace std;
/*
    -Logic
    1. 모든 경우의 수를 확인하되, dp를 사용하여 시간복잡도를 낮춘다.
    2. 연산자의 범위를 정하여 그 안에서 우선 계산하는 연산자를 순서대로 지정한다.
    3. 지정한 연산자대로 계산을 한 후, 최대값 또는 최소값을 dp에 저장한다.
    4. 최대값을 구해야 하며 +인 경우 왼쪽 : 최대, 오른쪽 : 최대
                         -인 경우 왼쪽 : 최대, 오른쪽 : 최소
       최소값을 구해야 하며 +인 경우 왼쪽 : 최소, 오른쪽 : 최소
                         -인 경우 왼쪽 : 최소, 오른쪽 : 최대
    5. 만약 dp에 갱신된 값이 존재하면 다시 계산할 필요가 없으므로 return
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