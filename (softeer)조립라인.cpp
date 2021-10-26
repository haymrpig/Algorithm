#include<iostream>
#include<vector>
#define INF 1000000000
using namespace std;
// 작업장의 범위가 10^3이하로 주어졌으므로 dynamic programming( O(N) )으로 해결이 가능하였다.
// 각 Ai, Bi까지의 최적의 합을 구해가면 문제를 해결하였다. 
int main(int argc, char** argv)
{
	int numPlace = 0;
	cin >> numPlace;
	int a, b, a2b, b2a;
	vector<pair<int, int>> d(numPlace, { INF,INF });
	vector<int> timeA(numPlace + 1), timeB(numPlace + 1), timeA2B(numPlace + 1), timeB2A(numPlace + 1);

	for (int i = 1; i < numPlace; i++) {
		cin >> a >> b >> a2b >> b2a;
		timeA[i] = a;
		timeB[i] = b;
		timeA2B[i] = a2b;
		timeB2A[i] = b2a;
	}
	cin >> a >> b;
	timeA[numPlace] = a;
	timeB[numPlace] = b;

	d[1].first = timeA[1]; // d[i].first = Ai까지의 최적의 해
	d[1].second = timeB[1]; // d[i].second = Bi까지의 최적의 해
	for (int i = 2; i <= numPlace; i++) {
		d[i].first = min(d[i - 1].first, d[i - 1].second + timeB2A[i - 1]) + timeA[i];
		d[i].second = min(d[i - 1].first + timeA2B[i - 1], d[i - 1].second) + timeB[i];
	}
	cout << min(d[numPlace].first, d[numPlace].second);
	return 0;
}