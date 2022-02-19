#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	long long N;
	cin >> N;

	char alphabet[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	map<char, int> dice;

	long long min_one_sum = 99999999;
	long long min_three_sum = 99999999;
	long long min_two_sum = 99999999;
	long long max_one_sum = 0;
	long long dice_total_sum = 0;
	for (int i = 0; i < 6; i++) {
		long long num;
		cin >> num;
		dice[alphabet[i]] = num;
		dice_total_sum += num;
		min_one_sum = min(min_one_sum, num);
		max_one_sum = max(max_one_sum, num);
	}

	string three_plane[8] = { "FBD", "FDE", "FEC", "FCB", "ABD", "ADE", "AEC", "ACB" };
	
	for (int i = 0; i < size(three_plane); i++) {
		long long sum = 0;
		for (int j = 0; j < three_plane[0].length(); j++) {
			sum += dice[three_plane[i][j]];
		}
		min_three_sum = min(min_three_sum, sum);
	}

	string two_plane[12];
	int idx = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i+1; j < 6; j++) {
			if ( (alphabet[i] == 'A' && alphabet[j] == 'F') || (alphabet[i] == 'C' && alphabet[j] == 'D') || (alphabet[i] == 'B' && alphabet[j] == 'E')) continue;
			string temp = "";
			two_plane[idx] = temp + alphabet[i] + alphabet[j];
			idx++;
		}
	}

	for (int i = 0; i < size(two_plane); i++) {
		long long sum = 0;
		for (int j = 0; j < two_plane[0].length(); j++) {
			sum += dice[two_plane[i][j]];
		}
		min_two_sum = min(sum, min_two_sum);
	}
	
	long long answer = 0;
	if (N == 1) {
		answer = dice_total_sum - max_one_sum;
	}
	else if (N == 2) {
		answer += min_three_sum * 4;
		answer += min_two_sum * 4;
	}
	else {
		answer += min_three_sum * 4;
		answer += (4 * (N - 1) + 4 * (N - 2)) * min_two_sum;
		answer += ((N - 1)* (N - 2) * 4 + (N - 2) * (N - 2) )* min_one_sum;
	}
	cout << min_three_sum;
	cout << answer;
}