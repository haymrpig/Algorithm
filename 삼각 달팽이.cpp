#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> pyramid(1000, vector<int>(1000, 0));
    int dx[3] = { 1,0,-1 }, dy[3] = { 0,1,-1 };
    pyramid[0][0] = 1;
    int x = -1, y = 0, lastNum = 0;
    int temp = n;
    n += 1;
    for (int i = 0; i < temp; i++) {
        n--;
        for (int j = 0; j < n; j++) {
            x += dx[i % 3], y += dy[i % 3];
            lastNum++;
            pyramid[x][y] = lastNum;
        }
    }
    n--;
    for (int i = 0; i < temp; i++) {
        n++;
        for (int j = 0; j < n; j++)
            answer.push_back(pyramid[i][j]);
    }
    return answer;
}