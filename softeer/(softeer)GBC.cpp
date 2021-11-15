#include<iostream>
#include<queue>
//시작시간 23:25
using namespace std;

int main(int argc, char** argv)
{
    int sector = 0, testSec = 0;
    cin >> sector >> testSec;

    int len = 0, speed = 0;
    vector<pair<int, int>> info;
    while (sector--) {
        cin >> len >> speed;
        info.push_back({ len,speed });
    }
    int maxDiff = 0;
    int index = 0;
    while (testSec--) {

        cin >> len >> speed;
        while (len != 0) {
            maxDiff = max(speed - info[index].second, maxDiff);
            if (info[index].first > len) {
                info[index].first -= len;
                len = 0;
            }
            else {
                len -= info[index].first;
                index++;
            }
        }
    }
    cout << maxDiff << endl;
    return 0;
}