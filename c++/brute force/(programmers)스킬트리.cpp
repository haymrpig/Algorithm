#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    set<char> s;
    for (int i = 0; i < skill.size(); i++) {
        s.insert(skill[i]);
    }
    for (int i = 0; i < skill_trees.size(); i++) {
        string temp = "";
        for (int j = 0; j < skill_trees[i].size(); j++) {
            char c = skill_trees[i][j];
            if (s.find(c) != s.end()) temp += c;
        }
        skill_trees[i] = temp;
    }
    for (int i = 0; i < skill_trees.size(); i++) {
        int j;
        for (j = 0; j < skill_trees[i].size(); j++) {
            if (skill[j] != skill_trees[i][j]) break;
        }
        if (j == skill_trees[i].size()) answer++;
    }
    return answer;
}