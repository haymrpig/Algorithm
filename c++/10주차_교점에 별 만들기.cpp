#include <string>
#include <vector>
#include <iostream>
#include <climits>
#define INF 100000000
using namespace std;
// LONG LONG type의 최대 최소값을 climits 라이브러리를 통해 표현가능

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> v;
    long long a, b, c, a1, b1, c1, x, y;
    long long minX = LLONG_MAX, maxX = LLONG_MIN, minY = LLONG_MAX, maxY = LLONG_MIN;
    for (int i = 0; i < line.size(); i++) {
        a = line[i][0];
        b = line[i][1];
        c = line[i][2];
        for (int j = i + 1; j < line.size(); j++) {
            a1 = line[j][0];
            b1 = line[j][1];
            c1 = line[j][2];
            long long mod = a * b1 - a1 * b;
            x = b * c1 - b1 * c;
            y = a1 * c - a * c1;
            if (mod == 0) continue;
            if (x % mod || y % mod) continue;
            x /= mod;
            y /= mod;
            maxX = max(maxX, x);
            minX = min(minX, x);
            maxY = max(maxY, y);
            minY = min(minY, y);
            v.push_back({ y,x });
        }
    }
    string row = string(maxX - minX + 1, '.');
    vector<string> answer(maxY - minY + 1, row);
    for (int i = 0; i < v.size(); i++) {
        long long tempY = v[i].first;
        long long tempX = v[i].second;
        answer[maxY - tempY][tempX - minX] = '*';
    }
    return answer;
}