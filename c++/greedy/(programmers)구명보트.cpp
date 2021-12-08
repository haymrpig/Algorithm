#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    1. compare함수 사용시 return true를 먼저 써줘야 한다. return false를 먼저 if문에 걸면 에러 발생
*/
bool compare(int a, int b) {
    if (a > b) return true;
    else return false;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    if (people.size() > 1) {
        sort(people.begin(), people.end(), compare);
    }
    int index = people.size() - 1;
    int start = 0;
    while (1) {
        if (start < index && people[start] + people[index] <= limit) {
            index -= 1;
        }
        answer += 1;
        start += 1;
        if (start > index) break;
    }
    return answer;
}