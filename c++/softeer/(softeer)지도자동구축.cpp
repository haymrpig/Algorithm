#include<iostream>

//시작시간 23:15
//종료시간 23:20
using namespace std;

int main(int argc, char** argv)
{
    int step = 0;
    cin >> step;
    int d[15];
    d[0] = 2;
    for (int i = 1; i <= step; i++) {
        d[i] = 2 * d[i - 1] - 1;
    }
    cout << d[step] * d[step] << '\n';
    return 0;
}