#include<iostream>
#include<cmath>
#define mod 1000000007
#define ll long long
using namespace std;
// ���� ������ �ſ� ũ�� ������ �������� �����̴�. 
// ó���� ������ Ʋ�ȴµ� �� ������ 16��° �ٿ��� a*a�� mod�� �������� �ʾƼ�����.

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