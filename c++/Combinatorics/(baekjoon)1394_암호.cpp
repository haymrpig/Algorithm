#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
	typedef long long ll;
	string s;
	cin >> s;
	
	unordered_map<char, int> m;
	int len_s = s.size();
	int cnt = 0;
	for (int i = 0; i < len_s; i++) {
		m[s[i]] = ++cnt;
	}

	string target;
	cin >> target;
	int len_target = target.size();
	int g = 1;
	ll answer = 0;
	for (int i = len_target - 1; i >= 0; i--) {
		answer =(answer + (g * m[target[i]])) % 900528;
		g = (g * len_s) % 900528;
	}
	cout << answer;

}