#include<iostream>
#include<cmath>
#define mod 1000000007
#define ll long long
using namespace std;
// 값의 범위가 매우 크기 때문에 분할정복 문제이다. 
// 처음에 여러번 틀렸는데 그 이유가 16번째 줄에서 a*a를 mod로 나눠주지 않아서였다.

ll calculate(ll ratio, ll time) {
	if (time == 1) return ratio;
	if (time % 2 == 0) {
		ll a = calculate(ratio, time / 2);
		return (a * a) % mod;
	}
	else if (time % 2 == 1) {
		ll a = calculate(ratio, time / 2);
		return ((a * a) % mod * ratio) % mod;
	}
}
int main(int argc, char** argv)
{
	ll virus = 0, ratio = 0, time = 0;
	cin >> virus >> ratio >> time;

	cout << (virus * calculate(ratio, 10 * time)) % mod;
	return 0;
}