#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int date2day(int m, int d) {
	int tf_day = d;
	for (int i = 0; i < m-1; i++) {
		tf_day += day[i];
	}
	return tf_day;
}
bool compare(pair<int,int> a, pair<int,int> b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		if (a.second < b.second) {
			return true;
		}
		else return false;
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	
	vector<pair<int,int>> v; //start, end
	for (int i = 0; i < N; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		int start_day = date2day(sm, sd);
		int end_day = date2day(em, ed);
		v.push_back({ start_day, end_day });
	}
	sort(v.begin(), v.end(), compare);
	int sbirth, ebirth;
	sbirth = date2day(3, 1);
	ebirth = date2day(11, 30);
	int check_day = sbirth;
	int index = 0;
	int answer = 0;
	priority_queue<int> pq;
	while (index<v.size() && check_day <= ebirth) {
		while (index<v.size() && v[index].first <= check_day) {
			pq.push(v[index].second);
			index++;
		}
		if (!pq.empty()) {
			answer += 1;
			check_day = pq.top();
		}
		else {
			cout << 0;
			return 0;
		}
		while (!pq.empty()) pq.pop();
	}
	if (check_day <= ebirth) {
		cout << 0;
	}
	else cout << answer;
	return 0;
}