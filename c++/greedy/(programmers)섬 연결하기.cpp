#include <string>
#include <vector>
#include <algorithm>
#include <queue>
/*
    -Logic
    1. ũ�罺Į �˰����� �̿��Ѵ�.
    2. ���⼭ �θ� ����� ���� �׻� �ֻ��� �θ� ����ؾ��Ѵ�.

    !!! ���� !!!
    - ó������ �ֻ��� �θ� �ƴ� �� ���� ���� ���� �θ�� �־��µ�, �̷��� �ϴ� ���, ������ ����� �θ� �Ҿ���� ���� �ֱ� ������ �ֻ��� �θ� �־���� �Ѵ�.
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