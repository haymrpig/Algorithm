#include <string>
#include <vector>
#include <algorithm>
#include <stack>
/*
    시작 11:20
    종료 11:30
    - Logic
    1. 차가 진출하는 지점을 오름차순으로 정렬한다.
    2. 이전 차량 진출 지점 >= 다음 차량의 진입 지점 -> 카메라 하나
       이전 차량 진출 지점 < 다음 차량 진입 지점 -> 이전 차량 진출 지점 = 다음 차량 진입 지점, 카메라 하나 추가

    - 개선점
    1. stack을 이용하여 위의 Logic대로 구현하였지만, 단순히 이전 차량의 진출 지점을 기록하는 변수 하나 + 카메라의 수를 나타내는 변수 하나로 충분하기 때문에 개선의 여지가 있다.
*/
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[1] < b[1]) return true;
    else if (a[1] == b[1]) {
        if (a[0] < b[0]) return true;
        else return false;
    }
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), compare);
    stack<int> st;
    for (int i = 0; i < routes.size(); i++) {
        if (st.empty() || routes[i][0] > st.top()) st.push(routes[i][1]);
    }
    answer = st.size();
    /*
        - 개선한 부분
        int limit = routes[0][1];
        answer = 1;
        for(int i=1;i<routes.size();i++){
            if( limit < routes[i][0] ){
                answer++;
                limit = routes[i][1];
            }
        }
    */
    return answer;
}