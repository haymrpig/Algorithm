#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//시작시간 17:00
using namespace std;
int maxNum = 0;

int main() {
	int lineLen = 0, distance = 0;
	cin >> lineLen >> distance;
	vector<char> line;
	string temp;
	cin >> temp;
	for (int i = 0; i < temp.size(); i++) {
		line.push_back(temp[i]);
	}
	int cnt = 0;
	vector<int> checked(line.size(), 0);
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 'P') {
			for (int j = 0; j < line.size(); j++) {
				if (line[j] == 'H' && checked[j] == 0 && abs(i-j) <= distance) {
					checked[j] = 1;
					cnt++;
					break;
				}
			}
		}
	}

	cout << cnt  << endl;
}