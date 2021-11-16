#include <string>
#include <vector>
#include <algorithm>
/*
    시작 11:40
    종료 11:52
    - Logic
    1. 두 팀 모두 오름차순 정렬
    2. A와 B를 순서대로 비교( 제일 적은 차이로 이길 수 있는 수 선택 )
        -> A를 B가 이길 수 있으면 answer++
        -> A를 B가 이길 수 없으면 다음 B와 비교( 반복 )
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