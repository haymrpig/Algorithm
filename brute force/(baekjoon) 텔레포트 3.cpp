#include <iostream>
#include <vector>
#include <algorithm>
#define MAXNUM 1000000001
/*
*	시작 16:00
*	종료 
*/
using namespace std;

int calTime(int x, int y, int x1, int y1) {
	int time = abs(x - x1) + abs(y - y1);
	return time;
}
int main() {
	int xs, ys, xe, ye;
	cin >> xs >> ys;
	cin >> xe >> ye;
	int x, y, x1, y1;
	vector <vector<int>> teleport;
	for (int i = 0; i < 3; i++) {
		cin >> x >> y >> x1 >> y1;
		if (abs(y1 - y) +abs( x1 - x) <= 10) continue;
		teleport.push_back({ x,y,x1,y1 });
		teleport.push_back({ x1,y1,x,y });
	}
	teleport.push_back({ xe,ye,xe,ye });
	vector<int> v;
	for (int i = 0; i < teleport.size(); i++) {
		v.push_back(i);
	}
	int minTime = MAXNUM;
	do {
		int px = xs;
		int py = ys;
		int time=0;
		for (int i = 0; i < v.size(); i++) {
			time += calTime(px, py, teleport[v[i]][0], teleport[v[i]][1]);
			if (teleport[v[i]][0] == xe && teleport[v[i]][1] == ye) {
				minTime = min(minTime, time);
			}
			time += 10;
			px = teleport[v[i]][2];
			py = teleport[v[i]][3];
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << minTime;

	return 0;
}