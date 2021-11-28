#include<iostream>
#include<stack>
#include<vector>
using namespace std;
// dynamic programming을 사용하는 문제이다. 
// d[k]는 array[k]를 마지막 원소로 갖는 k번째의 최적의 해이다. 
// 3 2 1 4 5 순의 배열에서
// 첫번째 루프 i = 0 에서의 값은 1 1 1 1 1로 채워져 있을 것이다.
// i=1에서는 2가 3보다 작으므로 1 1 1 1 1이 채워져 있을 것이다.
// i=2에서는 1이 2, 3보다 작으므로 1 1 1 1 1로 채워져 있을 것이다.
// i=3에서는 4가 3, 2, 1보다 크므로 d[0]+1, d[1]+1, d[2]+1 중 최대값을 d[3]에 저장한다.
// ...
// 이런식으로 풀면 각 값마다 가능한 최적의 해가 도출되고, 그 중 최대값을 찾아 출력한다.
int main(int argc, char** argv)
{
	int stoneNum = 0;
	cin >> stoneNum;
	stack<int> st;
	vector<int> stone;
	for (int i = 0; i < stoneNum; i++) {
		int height = 0;
		cin >> height;
		stone.push_back(height);
	}
	vector<int> d(stoneNum, 1);

	for (int i = 1; i < stoneNum; i++) {
		for (int j = 0; j < i; j++) {
			if (stone[j] < stone[i]) d[i] = max(d[i], d[j] + 1);
		}
	}
	int maxNum = 0;
	for (auto x : d) {
		if (maxNum < x) maxNum = x;
	}
	cout << maxNum;
	return 0;
}