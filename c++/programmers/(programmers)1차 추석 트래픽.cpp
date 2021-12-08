#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
/*
    시작시간 19:30
    종료시간 20:30

    -Logic
    1. 시, 분, 초, m초로 되어있는 값을 모두 초 단위로 바꾸어 계산한다.
    2. 끝나는 시간을 기준으로 시작시간이 끝나는 시간 안에 있으면 count+1

    !!추가!!
    - sscanf(<string>, "%s", &<string>)을 통해 간단하게 시간을 읽어올 수 있다.
    example)
        ssanf(lines[i].c_str, "%d-%d-%d %d:%d:%lf %lf", &year,&month, &day, &s, &m, &sec, &duration);
*/
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;

    vector<pair<long double, long double>> end_time;
    for (int i = 0; i < lines.size(); i++) {
        string temp = lines[i].substr(11, 12);
        long double time = 0.0;
        string time_temp = "";
        int index = 2;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == ':' || temp[j] == '.') {
                time += stod(time_temp) * pow(60, index);
                index--;
                time_temp = "";
                continue;
            }
            time_temp += temp[j];
        }
        time += stod(time_temp) * 0.001;
        long double time1 = 0.0;
        string time_temp1 = "";
        for (int j = 24; j < lines[i].size(); j++) {
            if (lines[i][j] == 's') {
                time1 = stod(time_temp1);
                break;
            }
            time_temp1 += lines[i][j];
        }
        end_time.push_back({ time - time1 + 0.001, time });
    }

    long double start = 0;
    for (int i = 0; i < lines.size(); i++) {
        start = end_time[i].second;
        int cnt = 0;
        for (int j = i; j < lines.size(); j++) {
            if (end_time[j].first < start + 1) {
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }
    return answer;
}