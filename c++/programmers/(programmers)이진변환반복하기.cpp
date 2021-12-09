#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool IsZeroExist(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') return true;
    }
    return false;
}

string ToBinary(string a) {
    int number = a.size();
    string answer = "";
    stack<string> s;
    while (number != 0) {
        s.push(to_string(number % 2));
        number /= 2;
    }
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    return answer;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0, transform = 0;
    while (s != "1") {
        transform++;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt++;
            }
            else {
                temp += '1';
            }
        }
        s = ToBinary(temp);
    }
    answer.push_back(transform);
    answer.push_back(cnt);

    return answer;
}