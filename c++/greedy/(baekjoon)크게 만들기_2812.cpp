#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	string number;
	cin >> number;
	string s="";

	for (int i = 0; i < N; i++) {
		if (s.size()==0 || s[s.size() - 1] >= number[i]) {
			s+=number[i];
		}
		else {
			int j = s.size() - 1;
			while(j>=0){
				if (K > 0 && s[j] < number[i]) {
					s.erase(s.begin() + j);
					K--;
					j--;
				}
				else break;
			}
			s += number[i];
		}
	}
	while (K--) {
		s.erase(s.end() - 1);
	 }
	cout << s << endl;
}