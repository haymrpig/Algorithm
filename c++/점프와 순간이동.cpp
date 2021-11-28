#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else {
            n = (n - 1) / 2;
            ans++;
        }
    }
    ans++;
    return ans;
}