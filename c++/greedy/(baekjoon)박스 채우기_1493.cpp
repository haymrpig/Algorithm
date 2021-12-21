#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int answer = 0;

bool Search(vector<pair<int,int>>& cube, int length, int width, int height) {
	if (length == 0 || width == 0 || height == 0) {
		return true;
	}

	for (int i = cube.size() - 1; i >= 0; i--) {
		if (cube[i].second > 0) {
			int len_cube = cube[i].first;
			if (len_cube <= length && len_cube <= width && len_cube <= height) {
				answer++;
				cube[i].second--;
				return Search(cube, length - len_cube, width, height) && Search(cube, len_cube, width - len_cube, height) && Search(cube, len_cube, len_cube, height - len_cube);
			}
		}
	}
	return false;
}

int main(int* argc, char** argv) {
	int length, width, height;
	cin >> length >> width >> height;
	int kind;
	cin >> kind;
	int total = 0;
	vector<pair<int, int>> cube;
	for (int i = 0; i < kind; i++) {
		int len, num;
		cin >> len >> num;
		total += num;
		cube.push_back({ pow(2,len), num });
	}

	if (!Search(cube, length, width, height)) cout << -1;
	else {
		cout << answer;
	}
	return 0;
}