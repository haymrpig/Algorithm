#include <string>
#include <vector>
#include <stack>
using namespace std;


bool Check(string u) {
    stack<char> st;
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(') {
            st.push(u[i]);
        }
        else {
            if (st.empty()) return false;
            else if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            else return false;
        }
    }
    if (st.empty()) return true;
    else return false;
}


string seperate(string p) {
    if (p == "") return "";
    string u, v;
    int index = -1;
    int left_cnt = 0, right_cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            left_cnt += 1;
        }
        else {
            right_cnt += 1;
        }
        index = i;
        if (left_cnt == right_cnt) break;
    }
    u = p.substr(0, index + 1);
    v = p.substr(index + 1, p.size() - index - 1);

    if (Check(u)) return u + seperate(v);
    else {
        string temp = "(";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        return temp + seperate(v) + ')' + u;
    }
}


string solution(string p) {
    string answer = "";

    answer = seperate(p);
    return answer;
}