#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/*
    -Logic
    1. words를 길이 순으로 정렬, 길이가 같은 경우 문자순으로 정렬
    2. rwords는 각 문자열을 뒤집은 것으로 마찬가지로 정렬
    3. 길이를 통한 이진탐색과 길이가 일치할시에는 문자순으로 이진탐색을 진행
        -> 만약 ?를 제외한 문자열이 같은 경우 문자순으로 이진탐색을 다시 진행
        -> 예를 들어 fro??의 경우 froaa, frozz로 이진탐색을 통해 시작과 끝지점을 찾는다.
        -> 이 둘 사이의 문자열들이 가능한 경우이다.
*/

using namespace std;

bool compare(string a, string b) {
    if (a.size() < b.size()) return true;
    else if (a.size() == b.size()) {
        if (a < b) return true;
        else return false;
    }
    else return false;
}
int cntWords(vector<string>& words, int start, int end, string target, int count) {
    int answer = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (words[mid].size() == target.size()) {
            string temp = words[mid].substr(0, count);
            if (temp == target.substr(0, count)) {
                answer = mid;
                if (words[mid] < target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            else if (words[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        else if (words[mid].size() < target.size()) {
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return answer;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> rwords(words.begin(), words.end());
    for (int i = 0; i < rwords.size(); i++)
        reverse(rwords[i].begin(), rwords[i].end());
    sort(words.begin(), words.end(), compare);
    sort(rwords.begin(), rwords.end(), compare);
    for (int i = 0; i < queries.size(); i++) {
        string start = "";
        string end = "";
        int cnt = 0;
        if (queries[i][0] != '?') {
            for (int j = 0; j < queries[i].size(); j++) {
                if (queries[i][j] == '?') {
                    start += 'a';
                    end += 'z';
                }
                else {
                    start += queries[i][j];
                    end += queries[i][j];
                    cnt++;
                }
            }
            int startIndex = cntWords(words, 0, words.size(), end, cnt);
            int endIndex = cntWords(words, 0, words.size(), start, cnt);
            answer.push_back(startIndex != -1 ? startIndex - endIndex + 1 : 0);
        }
        else {
            for (int j = 0; j < queries[i].size(); j++) {
                if (queries[i][j] == '?') {
                    start += 'a';
                    end += 'z';
                }
                else {
                    start += queries[i][j];
                    end += queries[i][j];
                    cnt++;
                }
            }
            reverse(start.begin(), start.end());
            reverse(end.begin(), end.end());
            int startIndex = cntWords(rwords, 0, rwords.size(), end, cnt);
            int endIndex = cntWords(rwords, 0, rwords.size(), start, cnt);
            answer.push_back(startIndex != -1 ? startIndex - endIndex + 1 : 0);
        }
    }
    return answer;
}