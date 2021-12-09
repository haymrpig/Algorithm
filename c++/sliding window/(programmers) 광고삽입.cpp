#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

/*
    1. 시간의 총 길이가 360000초인 것을 기억하여 초 단위로 검사한다.
    2. 각각의 시간마다 동영상 재생의 횟수를 체크한다.
    3. sliding window처럼 광고시간은 일정하게 정해져있으니 0부터 검사할때 처음에 값을 더하고, 그 다음부터는 앞에것을 빼고 뒤에것을 저장하는 방식으로 시간복잡도를 줄일 수 있다.
    -> 매 시간마다 새로 다 더해줄 필요가 없다!!
*/
string sec2time(int answer_temp) {
    string answer = "";
    int hour = answer_temp / 3600;
    int temp = (answer_temp % 3600);
    int min = temp / 60;
    temp = temp % 60;
    int sec = temp;
    if (hour < 10) answer += "0";
    answer += to_string(hour);
    answer += ":";
    if (min < 10) answer += "0";
    answer += to_string(min);
    answer += ":";
    if (sec < 10) answer += "0";
    answer += to_string(sec);

    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int hour, min, sec;
    sscanf(adv_time.c_str(), "%d:%d:%d", &hour, &min, &sec);
    int ad_time = hour * 3600 + min * 60 + sec;
    sscanf(play_time.c_str(), "%d:%d:%d", &hour, &min, &sec);
    int ply_time = hour * 3600 + min * 60 + sec;
    vector<int> time_count(360000, 0);
    for (int i = 0; i < logs.size(); i++) {
        int start_hour, start_min, start_sec, end_hour, end_min, end_sec;
        sscanf(logs[i].c_str(), "%d:%d:%d-%d:%d:%d", &start_hour, &start_min, &start_sec, &end_hour, &end_min, &end_sec);
        int start_time = start_hour * 3600 + start_min * 60 + start_sec;
        int end_time = end_hour * 3600 + end_min * 60 + end_sec;
        for (int j = start_time; j < end_time; j++) time_count[j]++;
    }

    long long current_count = 0;
    long long max_count = 0;
    for (int i = 0; i < ad_time; i++) {
        current_count += time_count[i];
        max_count += time_count[i];
    }
    int Time = 0;
    for (int i = 1; i < ply_time - ad_time + 1; i++) {
        current_count += (long long)(time_count[ad_time + i - 1] - time_count[i - 1]);
        if (max_count < current_count) {
            max_count = current_count;
            Time = i;
        }
    }
    answer = sec2time(Time);
    return answer;
}