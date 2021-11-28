#include <string>
#include <vector>
#include <set>
using namespace std;

// DFS�� �̿��Ͽ� ����� node ���� count
void countNum(set<int> nodes[101], vector<int>& visited, int index, int& num) {
    visited[index] = 1;
    for (int x : nodes[index]) {
        if (visited[x] == 0) {
            index = x;
            num++;
            countNum(nodes, visited, index, num);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    set<int> nodes[101];

    //linked list ����
    for (int i = 0; i < wires.size(); i++) {
        int x = wires[i][0];
        int y = wires[i][1];
        nodes[x].insert(y);
        nodes[y].insert(x);
    }

    //������� edge ����
    int min = 100;
    for (int i = 0; i < wires.size(); i++) {
        vector<int> visited(wires.size() + 2, 0);
        int num = 1;
        nodes[wires[i][0]].erase(wires[i][1]);
        nodes[wires[i][1]].erase(wires[i][0]);
        countNum(nodes, visited, 1, num);
        nodes[wires[i][0]].insert(wires[i][1]);
        nodes[wires[i][1]].insert(wires[i][0]);
        int diff = wires.size() + 1 - 2 * num;
        if (min > abs(diff)) min = abs(diff);
    }
    answer = min;
    return answer;
}