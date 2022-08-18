#include <iostream>
#include <algorithm>
#include <vector>

/*
이 문제는 인접한 두 수의 차이를 구하고, 그 값들의 최대공약수를 구한 다음
최대공약수의 약수를 구하는 문제이다.  
*/
using namespace std;

bool cmp(int a, int b) {
	if (a > b) return true;
	else return false;
}

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	int nums;
	cin >> nums;
	
	vector<int> numbers(nums);

	for (int i = 0; i < nums;i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end(), cmp);
	
	int cur_gcd = numbers[0] - numbers[1];
	for (int i = 1; i < nums-1; i++) {
		cur_gcd = gcd(cur_gcd, numbers[i] - numbers[i+1]);
	}
	
	vector<int> ans;
	vector<int> reverse_ans;

	for (int i = 1; i*i<= cur_gcd; i++) {
		if (cur_gcd % i == 0) {
			if (i != cur_gcd / i) {
				ans.push_back(i);
				reverse_ans.push_back(cur_gcd / i);
			}
			else ans.push_back(i);
		}
	}

	for (int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
	for (int i = reverse_ans.size()-1; i >=0; i--) cout << reverse_ans[i] << " ";
}