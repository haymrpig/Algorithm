#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
/*
    -Logic
    1. dynamic programming�� �̿��Ѵ�.
    2. ã�ƾ��ϴ� ���ڿ��� ó������ ���������� �˻��Ѵ�.
    3. d[i]�� i��° ���ڱ����� �ּ� �����̴�.
    4. �ܾ������� �� �� ���ڰ� i��° ���ڿ� ��ġ�ϴ� ���, ���ڿ��� �����ϴ� �ĺ��� �� �� �ִ�.
        -> �ش� ���� ������ ���ڿ��� �Ϻο� ��ġ�Ѵ�?
            -> �� ���ڿ��� �ٷ� ���� d�� INF�� �ƴϴ� -> min(d[i],d[�ٷ����������� index]+1)
            -> �� ���ڿ��� �ٷ� ���� d�� INF�̴� -> �ĺ� Ż��
    5. �̷� ������� ���ڿ��� ��� Ž���ϸ� ���� d[���ڿ��� ������-1]�̴�.
        -> ���� INF�� ���, ���ڿ��� ���� �� ����. -> return -1
*/

bool compare(string a, string b) {
    if (a[0] < b[0]) return true;
    else if (a[0] == b[0]) {
        if (a.size() > b.size()) return true;
        else return false;
    }
    else return false;

}

int solution(vector<string> strs, string t)
{
    int answer = 0;
    int num = 0;
    sort(strs.begin(), strs.end(), compare);
    vector<int> d(20001, INF);
    for (int i = 0; i < t.size(); i++) {
        char temp = t[i];
        int minNum = INF;
        for (int j = 0; j < strs.size(); j++) {
            if (strs[j][strs[j].size() - 1] != temp) continue;
            int length = strs[j].size();
            if (i - length < 0) {
                if (strs[j] == t.substr(0, i + 1)) d[i] = 1;
            }
            else if (d[i - length] != INF && strs[j] == t.substr(i - length + 1, length)) {
                d[i] = min(d[i], d[i - length] + 1);
            }
        }
    }

    answer = d[t.size() - 1] == INF ? -1 : d[t.size() - 1];
    return answer;
}