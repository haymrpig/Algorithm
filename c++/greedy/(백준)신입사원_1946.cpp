#include <iostream>
#include <vector>
#include <algorithm>

/*
	1. 서류성적을 정렬하고, 면접성적을 비교한다. 
	2. 서류성적을 우수한 순서로 정렬하기 때문에, 앞에 있는 사람보다 면접성적이 떨어질 경우, 채용 X
	3. 시간복잡도 때문에 앞에 매번 앞의 모든 사람과 검사하는 것은 안된다. 
	4. for문을 돌리면서 앞사람들중에서 면접등수가 가장 낮은 사람을 기록하면서 그 등수가 비교한다.
	5. 앞의 사람들 중 면접등수가 가장 낮은 사람보다 등수가 더 낮다면 채용한다. 
*/
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	int numApplicant;
	while (testCase--) {
		cin >> numApplicant;
		vector<pair<int, int>> rank(numApplicant); // 서류성적, 면접성적
		for (int i = 0; i < numApplicant; i++) {
			cin >> rank[i].first >> rank[i].second;
		}
		sort(rank.begin(), rank.end());
		int mintemp = rank[0].second;
		int answer = 1;
		for (int i = 1; i < numApplicant; i++) {
			if (rank[i].second < mintemp) {
				answer++;
			}
			mintemp = min(mintemp, rank[i].second);
		}
		
		cout << answer << '\n';
	}
}