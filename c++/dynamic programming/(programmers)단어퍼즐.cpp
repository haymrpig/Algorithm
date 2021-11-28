#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
/*
    -Logic
    1. dynamic programming을 이용한다.
    2. 찾아야하는 문자열을 처음부터 마지막까지 검사한다.
    3. d[i]는 i번째 문자까지의 최소 개수이다.
    4. 단어조각들 중 끝 문자가 i번째 문자와 일치하는 경우, 문자열을 구성하는 후보가 될 수 있다.
        -> 해당 문자 조각이 문자열의 일부와 일치한다?
            -> 그 문자열의 바로 이전 d가 INF가 아니다 -> min(d[i],d[바로이전문자의 index]+1)
            -> 그 문자열의 바로 이전 d가 INF이다 -> 후보 탈락
    5. 이런 방식으로 문자열을 모두 탐색하면 답은 d[문자열의 사이즈-1]이다.
        -> 만약 INF인 경우, 문자열을 만들 수 없다. -> return -1
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