//시작 시간 16:18

#include <iostream>
#include <vector>

using namespace std;
int main() {
	int student = 0, range = 0, score = 0;
	vector<int> scores;
	cin >> student >> range;
	while (student--) {
		cin >> score;
		scores.push_back(score);
	}
	vector<double> average;
	while (range--) {
		int start = 0, end = 0;
		cin >> start >> end;
		int num = end - start+1;
		int sum = 0;
		long double averageTemp = 0;
		for (int i = start - 1; i < end; i++) sum += scores[i];
		averageTemp = round(sum *100 / num) / 100;
		average.push_back(averageTemp);
	}
	cout << fixed;
	cout.precision(2);
	for (auto x : average) cout << x << '\n';
}