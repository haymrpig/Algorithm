#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long factorial(int num) {
    if (num == 1) return (long long)num;
    return (long long)num * factorial(num - 1);
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    for (int i = 1; i <= n; i++) people.push_back(i);

    for (int i = n - 1; i >= 1; i--) {
        if (k == 0) {
            break;
        }
        long long fact = factorial(i);
        long long num = (k - 1) / fact;
        k %= fact;
        answer.push_back(people[num]);
        people.erase(people.begin() + num, people.begin() + num + 1);
    }
    for (int i = people.size() - 1; i >= 0; i--) {
        answer.push_back(people[i]);
    }
    return answer;
}