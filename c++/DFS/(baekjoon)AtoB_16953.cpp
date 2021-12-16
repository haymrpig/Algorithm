#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
/*
*  1. 가능한 수의 범위 확인이 중요하다. 
*/
using namespace std;
long long B, answer = INF;
void Search(long long number, long long depth) {
	if (depth > answer) return;
	if (number >= B) {
		if (number == B) {
			answer = min(answer, depth);
		}
		return;
	}

	Search(number * 2, depth + 1);
	Search(number * 10 + 1, depth + 1);
}

int main() {
	int A;
	cin >> A >> B;
	Search(A, 0);
	answer = answer == INF ? -1 : answer+1;
	cout << answer;
}