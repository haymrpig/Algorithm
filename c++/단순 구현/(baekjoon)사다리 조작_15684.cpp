#include <iostream>
#include <vector>
/*
*	-Logic
*	1. 단순 구현 문제로 완전탐색을 통해 해결한다. 
*	2. 사다리를 놓는 경우 이차원 ladder변수에 1로 표시, 사다리를 놓을 수 없는 경우를 2로 표시, 나머지는 0으로 표시하였다. 
*	3. DFS를 통해 사다리를 0개~3개까지 놓는 모든 조합을 탐색하여 답을 구한다. 
* 
*	!!! 개선점 !!!
*	- 나는 사다리를 놓지 못하는 경우를 2로 표시하였는데, 그 때문에 코드의 가독성이 떨어지는 경향을 보였다. 
*		-> 2를 넣는 대신, 선택한 조합에서 사다리를 놓을 경우, 양쪽을 확인하는 코드면 가독성이 개선될 것 같다. 
*	- DFS에서 조합을 구할 때 중복없이 조합을 구하기 위해서 이전 index는 검사하지 않기 위해 start_i, start_j 변수를 인자로 넣어주었다. 
*		-> 조건문을 확인해보면 
*		-> if ((i!=1 && j!=1) && i == start_i && j <= start_j) continue; 이 부분에서 오류가 발생했었다. 
*		-> (i!=1 && j!=1) 이 부분을 생각하지 못하여 1,1 위치에 사다리를 놓지 않게 되어 처음 풀이 때 예외가 발생하엿다. 
*/
using namespace std;
int N, H;
bool check(vector<vector<int>>& ladder) {
	for (int i = 1; i < N+1; i++) {
		int num = i;
		int start = 1;
		while (1) {
			if (start > H) break;
			if (num == 1) {
				if (ladder[num][start] == 1) num++;
			}
			else if (num == N) {
				if (ladder[num - 1][start] == 1 ) num--;
			}
			else {
				if (ladder[num - 1][start] == 1) num--;
				else if (ladder[num][start] == 1) num++;
			}
			start++;
		}
		if (num != i) return false;
	}
	return true;
}

void add(vector<vector<int>>& ladder, int i, int j) {
	ladder[i][j] = 1;
	if (N == 2) return;
	if (i == 1) ladder[i + 1][j] = 2;
	else if (i == N - 1) ladder[i - 1][j] = 2;
	else {
		ladder[i + 1][j] = 2;
		ladder[i - 1][j] = 2;
	}
	return;
}


void checkNum(int target, int depth, vector<vector<int>>& ladder, int start_i, int start_j) {
	if (target == 3) {
		cout << depth << endl;
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < H + 1; j++) {
				cout << ladder[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	if (depth == target) {
		if ( !check(ladder) ) return;
		else {
			cout << depth;
			exit(0);
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < H+1; j++) {
			if (i < start_i) continue;
			if ((i!=1 && j!=1) && i == start_i && j <= start_j) continue;
			if (ladder[i][j] == 2 || ladder[i][j]==1) continue;
			vector<vector<int>> ladder_temp(ladder.begin(), ladder.end());
			add(ladder_temp, i, j);
			checkNum(target, depth + 1, ladder_temp, i, j);
		}
	}
	return;

}
int main() {
	int M;
	cin >> N >> M >> H;

	vector<vector<int>> ladder(N, vector<int>(H+1, 0));
	for (int i = 0; i < M; i++) {
		int pos, num;
		cin >> pos >> num;
		ladder[num][pos] = 1; // 1은 사다리
		if (N == 2) continue;
		if (num == 1) ladder[num + 1][pos] = 2; // 2는 사다리 못놓음
		else if (num == N - 1) ladder[num - 1][pos] = 2;
		else {
			ladder[num - 1][pos] = 2;
			ladder[num + 1][pos] = 2;
		}
	}
	int i;
	for (i = 0; i < 4; i++) {
		checkNum(i, 0, ladder, 1, 1);
	}
	cout << -1;
	return 0;
}