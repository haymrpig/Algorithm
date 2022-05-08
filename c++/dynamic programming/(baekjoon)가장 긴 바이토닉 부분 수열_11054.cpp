#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> numbers(N);
	vector<int> inc(N, 1);
	vector<int> dec(N, 1);

	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	int answer = 0;

	for (int i = 1; i < N; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (numbers[i] > numbers[j]) {
				inc[i] = max(inc[i], inc[j] + 1);
			}
			if (numbers[N - i - 1] > numbers[N - j - 1]) {
				dec[N - i - 1] = max(dec[N - i - 1], dec[N - j - 1] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		answer = max(answer, inc[i] + dec[i]);
	}

	cout << answer - 1;
	
}