#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int num=0;
    cin >> num;
    vector<int> time;
    int timeTemp = 0;
    for(int i=0;i<num;i++) {
        cin >> timeTemp;
        time.push_back(timeTemp);
    }
    sort(time.begin(), time.end());
    vector<int> timeSum(num, 0);
    timeSum[0] = time[0];
    int totalTime = timeSum[0];
    for (int i = 1; i < num; i++) {
        timeSum[i] = timeSum[i - 1] + time[i];
        totalTime += timeSum[i];
    }
    cout << totalTime;
}
