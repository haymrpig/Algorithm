#include <iostream>
#include <vector>
#include <algorithm>
//시작 시간 16:35
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) return true;
	else if (a.first == b.first) {
		if (a.second > b.second) return true;
		else return false;
	}
	else return false;
}
int main() {
	int totalWeight = 0, metalKind = 0;
	cin >> totalWeight >> metalKind;
	vector<pair<int, int>> metalInfo;
	while (metalKind--) {
		int metal = 0, cost = 0;
		cin >> metal >> cost;
		metalInfo.push_back({cost,metal });
	}
	sort(metalInfo.begin(), metalInfo.end(), compare);
	int totalCost = 0;
	for (int i = 0; i < metalInfo.size(); i++) {
		if (totalWeight == 0) break;
		if (totalWeight - metalInfo[i].second >= 0) {
			totalCost += (metalInfo[i].first * metalInfo[i].second);
			totalWeight -= metalInfo[i].second;
		}
		else {
			totalCost += totalWeight * metalInfo[i].first;
		}
	}
	cout << totalCost;
}