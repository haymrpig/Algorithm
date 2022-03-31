#include <vector>
#include <iostream>
#include <cmath>
#define ClockWise 1
#define CClockWise -1
using namespace std;

vector<string> gears(4);
vector<int> check(4);
void checkState(int  gear_number, int direction) {
	for (int i = 0; i < 4; i++) {
		if (check[i]==0 && abs(gear_number - i) == 1) {
			if (gear_number > i) {
				if (gears[gear_number][6] != gears[i][2]) check[i] = -direction;
				else check[i] = 2; // stay
			}
			else {
				if (gears[gear_number][2] != gears[i][6]) check[i] = -direction;
				else check[i] = 2; // stay
			}
			checkState(i, check[i]);
		}
	}
	return;
}

void rotate() {
	for (int i = 0; i < 4; i++) {
		if (check[i] == 1) {
			char temp = gears[i][gears[i].size() - 1];
			gears[i].erase(gears[i].end() - 1);
			gears[i] = temp + gears[i];
		}
		else if(check[i] == -1){
			char temp = gears[i][0];
			gears[i].erase(gears[i].begin());
			gears[i] = gears[i] + temp;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> gears[i];
	}
	
	int K, gear_number, direction;
	
	cin >> K;
	while (K--) {
		for (int i = 0; i < 4; i++) check[i] = 0;
		cin >> gear_number >> direction;
		gear_number -= 1;
		check[gear_number] = direction;
		checkState(gear_number, direction);
		rotate();
	}

	int score = 0;
	for (int i = 0; i < 4; i++) {
		score += (pow(2, i) * (gears[i][0]-'0'));
	}
	cout << score << endl;
}