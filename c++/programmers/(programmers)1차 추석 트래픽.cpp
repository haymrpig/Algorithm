#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
/*
    ���۽ð� 19:30
    ����ð� 20:30

    -Logic
    1. ��, ��, ��, m�ʷ� �Ǿ��ִ� ���� ��� �� ������ �ٲپ� ����Ѵ�.
    2. ������ �ð��� �������� ���۽ð��� ������ �ð� �ȿ� ������ count+1

    !!�߰�!!
    - sscanf(<string>, "%s", &<string>)�� ���� �����ϰ� �ð��� �о�� �� �ִ�.
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