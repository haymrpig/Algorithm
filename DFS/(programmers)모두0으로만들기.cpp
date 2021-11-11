#include <vector>
#include <cmath>
#include <iostream>
#define MAXNUM 300000
/*
    1. tree 구조 탐색 문제로 DFS알고리즘을 이용하여 leaf노드부터 root노드까지 하나씩 계산해나간다. 
    2. root노드는 아무거나 하나 잡아도 된다. 
*/

using namespace std;

void calSum(int index, vector<bool>& visited, vector<long long>& a_, long long& sum, vector<int> link[MAXNUM]) {
    visited[index] = true;
    for (int i = 0; i < link[index].size(); i++) {
        int linkedNode = link[index][i];
        if (visited[linkedNode]) continue;
        calSum(linkedNode, visited, a_, sum, link);
        a_[index] += a_[linkedNode];
        sum += abs(a_[linkedNode]);
    }
    return;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;

    vector<long long> a_(a.begin(), a.end());
    vector<int> link[MAXNUM];
    for (int i = 0; i < edges.size(); i++) {
        int start = edges[i][0];
        int end = edges[i][1];
        link[start].push_back(end);
        link[end].push_back(start);
    }
    int root = edges[0][0];
    vector<long long> weight(MAXNUM, 0);
    vector<bool> visited(MAXNUM, false);
    long long sum = 0;
    calSum(root, visited, a_, sum, link);
    a_[root] != 0 ? answer = -1 : answer = sum;
    return answer;
}