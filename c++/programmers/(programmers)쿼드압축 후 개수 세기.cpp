#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    1. python numpy�� �̿��ϴ� ��� slicing�� ������ c++�� �׷��� ���ϱ� ������ index�� ���� �Ѱ��־� �迭�� �ɰ��� ��ó��
    ����Ѵ�.
*/
int ones = 0;
int zeros = 0;
void Slicing(vector<vector<int>>& arr, int x, int y, int size) {
    int number = arr[x][y];
    int flag = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != number) {
                flag = false;
                break;
            }
        }
    }
    if (flag == false) {
        Slicing(arr, x, y, size / 2);
        Slicing(arr, x + size / 2, y, size / 2);
        Slicing(arr, x, y + size / 2, size / 2);
        Slicing(arr, x + size / 2, y + size / 2, size / 2);
    }
    else {
        if (number == 1) ones++;
        else zeros++;
    }

}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    Slicing(arr, 0, 0, arr.size());
    answer.push_back(zeros);
    answer.push_back(ones);

    return answer;
}