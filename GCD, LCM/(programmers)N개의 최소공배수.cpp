#include <string>
#include <vector>
#include <algorithm>
/*
    ���� 15:36
    ���� 15:50
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

    // �ּҰ���� ���ϱ� ���� �������� ����
    sort(arr.begin(), arr.end(), compare);

    answer = arr[0];
    // �� ������ �ּҰ������ ���� ��, ���� �ּҰ������ �� ���� ������ �ּҰ���� ��� 
    for (int i = 1; i < arr.size(); i++) {
        answer = LCM(answer, arr[i]);
    }

    return answer;
}