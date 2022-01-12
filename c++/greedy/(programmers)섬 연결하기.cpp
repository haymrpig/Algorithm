#include <string>
#include <vector>
#include <algorithm>
#include <queue>
/*
    -Logic
    1. 크루스칼 알고리즘을 이용한다.
    2. 여기서 부모를 기록할 때는 항상 최상위 부모를 기록해야한다.

    !!! 주의 !!!
    - 처음에는 최상위 부모가 아닌 두 값중 작은 값을 부모로 넣었는데, 이렇게 하는 경우, 이전에 연결된 부모를 잃어버릴 수가 있기 때문에 최상위 부모를 넣어줘야 한다.
*/
using namespace std;
bool compare(vector<int> a, vector<int> b) {
    if (a[2] < b[2]) return true;
    else return false;
}

int FindParent(vector<int>& parent, int a) {
    if (parent[a] == a) return a;
    return FindParent(parent, parent[a]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    stable_sort(costs.begin(), costs.end(), compare);

    vector<int> parent(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < costs.size(); i++) {
        int s = FindParent(parent, costs[i][0]);
        int e = FindParent(parent, costs[i][1]);
        if (s != e) {
            answer += costs[i][2];
            if (s < e) parent[e] = s;
            else parent[s] = e;
        }
    }

    return answer;
}