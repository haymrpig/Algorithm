#include <string>
#include <vector>
#include <algorithm>
/*
    시작 15:36
    종료 15:50
*/
using namespace std;
bool compare(int a, int b) {
    if (a > b) return true;
    else return false;
}

int LCM(int a, int b) {
    int m = 0, preA = a, preB = b;
    while (b) {
        m = a % b;
        a = b;
        b = m;
    }
    return preA * preB / a;
}
int solution(vector<int> arr) {
    int answer = 0;

    // 최소공배수 구하기 위해 내림차순 정렬
    sort(arr.begin(), arr.end(), compare);

    answer = arr[0];
    // 두 숫자의 최소공배수를 구한 후, 구한 최소공배수와 그 뒤의 숫자의 최소공배수 계산 
    for (int i = 1; i < arr.size(); i++) {
        answer = LCM(answer, arr[i]);
    }

    return answer;
}