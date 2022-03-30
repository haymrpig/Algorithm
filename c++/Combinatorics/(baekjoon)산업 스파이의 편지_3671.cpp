#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<int, int> m;
int answer = 0;
bool IsPrimeNum(int N) {
	if (N == 1) return false;
	if (N == 2) return true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) return false;
	}
	return true;
}

void makeNum(vector<int>& numbers, string num) {
	int len = num.size();
	
	if (len > 0){
		int num_int = stoi(num);
		if (num_int != 0 && IsPrimeNum(num_int) && !m[num_int]) {
			m[num_int] = 1;
			answer++;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (numbers[i] == 0) continue;
		numbers[i]--;
		num += (i + '0');
		makeNum(numbers, num);
		num.erase(num.end() - 1);
		numbers[i]++;
	}
}

int main() {
	int test_case, num_len;
	string num;
	vector<int> numbers(10);
	
	cin >> test_case;
	while (test_case--) {
		for (int i = 0; i < 10; i++) numbers[i] = 0;
		answer = 0;
		m.clear();

		cin >> num;
		num_len = num.size();

		for (int i = 0; i < num_len; i++) {
			int number = num[i] - '0';
			numbers[number]++;
		}

		makeNum(numbers, "");
		cout << answer << endl;
	}
}