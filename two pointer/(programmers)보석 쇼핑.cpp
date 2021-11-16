#include <string>
#include <vector>
#include <unordered_map>
#include <set>
/*
    - Logic
    1. �������͸� �̿��Ͽ� ó���� ��� ������ �����ϵ��� end�� ���Ѵ�. -> answer�� start�� end ����
    2. ���� index�� ������ �����ϸ鼭 ��� ������ ���Ե��� ���� ������ start�� ������Ų��.
    3. ���������� �� �������� ���� ��� ������ ���Ե��� �����Ƿ�, ������ ������ ���ö����� end�� ������Ų��.
    4. 2���� 3���� end�� ��ü �迭 ����� �ɶ����� �ݺ��Ѵ�.

    - Ǯ�� 1
    1. ó������ ���� ����~��ü gemsũ��� sliding window������� Ǯ���Ͽ���. -> �ð��ʰ�

    - Ǯ�� 2
    1. �������� ������� �ذ��� ��� �ð��ʰ� X
*/

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> m;
    set<string> num(gems.begin(), gems.end());

    int start = 0, end = 0, minNum;
    for (auto x : gems) {
        m[x]++;
        if (m.size() == num.size()) break;
        end++;
    }
    minNum = end - start;
    answer = { start + 1, end + 1 };
    while (end < gems.size()) {
        string current = gems[start++];
        m[current]--;

        if (m[current] == 0) {
            end++;
            for (; end < gems.size(); end++) {
                m[gems[end]]++;
                if (current == gems[end])
                    break;
            }
            if (end == gems.size()) break;
        }
        if (minNum > end - start) {
            answer = { start + 1, end + 1 };
            minNum = end - start;
        }

    }
    return answer;
}