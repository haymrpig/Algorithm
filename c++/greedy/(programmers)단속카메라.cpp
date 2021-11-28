#include <string>
#include <vector>
#include <algorithm>
#include <stack>
/*
    ���� 11:20
    ���� 11:30
    - Logic
    1. ���� �����ϴ� ������ ������������ �����Ѵ�.
    2. ���� ���� ���� ���� >= ���� ������ ���� ���� -> ī�޶� �ϳ�
       ���� ���� ���� ���� < ���� ���� ���� ���� -> ���� ���� ���� ���� = ���� ���� ���� ����, ī�޶� �ϳ� �߰�

    - ������
    1. stack�� �̿��Ͽ� ���� Logic��� �����Ͽ�����, �ܼ��� ���� ������ ���� ������ ����ϴ� ���� �ϳ� + ī�޶��� ���� ��Ÿ���� ���� �ϳ��� ����ϱ� ������ ������ ������ �ִ�.
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
        - ������ �κ�
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