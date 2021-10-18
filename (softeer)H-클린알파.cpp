#include<iostream>
#include<vector>
#define MAX 1000000007
// 시작 시간 17:05

using namespace std;

int main(int argc, char** argv)
{
    int incRate = 0, totTime = 0;
    cin >> incRate >> totTime;
    vector<long long> d(1000001);
    long long temp;
    cin >> temp;
    d[1] = temp;
    for (int i = 2; i <= totTime; i++) {
        cin >> temp;
        d[i] = (d[i - 1] * incRate + temp) % MAX;
    }
    cout << d[totTime];
    return 0;
}