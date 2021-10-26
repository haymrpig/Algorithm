#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int maxNum = -1;
bool compare(char a, char b) {
	if (a < b) return true;
	else return false;
}
int main() {
	int A = 0, B = 0;
	cin >> A >> B;
	string Atemp = to_string(A);
	sort(Atemp.begin(), Atemp.end(), compare);
	do {
		if (Atemp[0] == '0') continue;
		A = stoi(Atemp);
		if (A < B && maxNum < A) maxNum = A;
	} while (next_permutation(Atemp.begin(), Atemp.end()));
	cout << maxNum;
}