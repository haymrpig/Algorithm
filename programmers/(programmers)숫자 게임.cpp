#include <string>
#include <vector>
#include <algorithm>
/*
    ���� 11:40
    ���� 11:52
    - Logic
    1. �� �� ��� �������� ����
    2. A�� B�� ������� ��( ���� ���� ���̷� �̱� �� �ִ� �� ���� )
        -> A�� B�� �̱� �� ������ answer++
        -> A�� B�� �̱� �� ������ ���� B�� ��( �ݺ� )
*/
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int compare = 0;
    for (int i = 0; i < B.size(); i++) {
        if (A[compare] < B[i]) {
            answer++;
            compare++;
        }
    }
    return answer;
}