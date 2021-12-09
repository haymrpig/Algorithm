#include <string>
#include <vector>
#include <iostream>
/*
    1. 0���� F������ �̸� string���� ����� ���� �������� index�� ���ڸ� ã�´�.a
*/
using namespace std;
string num_class = "0123456789ABCDEF";
string Change(int n, int number) {
    if (number == 0) return "";
    char temp;
    temp = num_class[number % n];
    return Change(n, number / n) + temp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "0";
    int number = 1;
    while (1) {
        temp += Change(n, number);
        if (temp.size() > p + (t - 1) * m - 1) break;
        number++;
    }
    for (int i = p - 1; i < p + (t - 1) * m; i += m) {
        answer += temp[i];
    }
    return answer;
}