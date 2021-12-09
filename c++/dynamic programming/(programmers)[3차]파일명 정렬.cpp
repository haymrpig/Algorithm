#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/*
    1. ���� ���� ��쿡 ���ؼ��� sort�� �� ���, ���������� ������ �ʴ´�.
        -> stable_sort�� �̿��ϸ� ���������� ���� ���� ��� ���� ������� ������ �ȴ�.
*/
using namespace std;
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
    if (a.first < b.first)return true;
    else if (a.first == b.first) {
        if (a.second.first < b.second.first) {
            return true;
        }
        else return false;
    }
    else return false;
}



vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<int> index(files.size());
    vector<string> files_copy(files.begin(), files.end());
    vector<pair<string, pair<int, int>>> all(files.size());

    for (int i = 0; i < files.size(); i++) {
        string temp = "";
        int j;
        for (j = 0; j < files[i].size(); j++) {
            char c = tolower(files[i][j]);
            if (!('0' <= c && c <= '9')) {
                temp += c;
                continue;
            }

            break;
        }
        files_copy[i] = files[i].substr(j);
        all[i].first = temp;
        all[i].second.second = i;
    }
    for (int i = 0; i < files_copy.size(); i++) {
        string temp = "";
        int j;
        for (j = 0; j < files_copy[i].size(); j++) {
            char c = files_copy[i][j];
            if ('0' <= c && c <= '9') {
                temp += c;
                if (temp.size() >= 5) break;
                continue;
            }

            break;
        }
        all[i].second.first = stoi(temp);
    }
    stable_sort(all.begin(), all.end(), compare);

    for (int i = 0; i < all.size(); i++) {
        answer.push_back(files[all[i].second.second]);
    }


    return answer;
}