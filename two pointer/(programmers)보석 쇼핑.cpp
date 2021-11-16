#include <string>
#include <vector>
#include <unordered_map>
#include <set>
/*
    - Logic
    1. 투포인터를 이용하여 처음에 모든 보석을 포함하도록 end를 정한다. -> answer에 start와 end 저장
    2. 시작 index의 보석을 제외하면서 모든 보석이 포함되지 않을 때까지 start를 증가시킨다.
    3. 마지막으로 뺀 보석으로 인해 모든 보석이 포함되지 않으므로, 마지막 보석이 나올때까지 end를 증가시킨다.
    4. 2번과 3번을 end가 전체 배열 사이즈가 될때까지 반복한다.

    - 풀이 1
    1. 처음에는 보석 개수~전체 gems크기로 sliding window방식으로 풀이하였다. -> 시간초과

    - 풀이 2
    1. 투포인터 방식으로 해결한 결과 시간초과 X
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