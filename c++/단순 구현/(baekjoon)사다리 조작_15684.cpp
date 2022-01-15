#include <iostream>
#include <vector>
/*
*	-Logic
*	1. �ܼ� ���� ������ ����Ž���� ���� �ذ��Ѵ�. 
*	2. ��ٸ��� ���� ��� ������ ladder������ 1�� ǥ��, ��ٸ��� ���� �� ���� ��츦 2�� ǥ��, �������� 0���� ǥ���Ͽ���. 
*	3. DFS�� ���� ��ٸ��� 0��~3������ ���� ��� ������ Ž���Ͽ� ���� ���Ѵ�. 
* 
*	!!! ������ !!!
*	- ���� ��ٸ��� ���� ���ϴ� ��츦 2�� ǥ���Ͽ��µ�, �� ������ �ڵ��� �������� �������� ������ ������. 
*		-> 2�� �ִ� ���, ������ ���տ��� ��ٸ��� ���� ���, ������ Ȯ���ϴ� �ڵ�� �������� ������ �� ����. 
*	- DFS���� ������ ���� �� �ߺ����� ������ ���ϱ� ���ؼ� ���� index�� �˻����� �ʱ� ���� start_i, start_j ������ ���ڷ� �־��־���. 
*		-> ���ǹ��� Ȯ���غ��� 
*		-> if ((i!=1 && j!=1) && i == start_i && j <= start_j) continue; �� �κп��� ������ �߻��߾���. 
*		-> (i!=1 && j!=1) �� �κ��� �������� ���Ͽ� 1,1 ��ġ�� ��ٸ��� ���� �ʰ� �Ǿ� ó�� Ǯ�� �� ���ܰ� �߻��Ͽ���. 
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
		ladder[num][pos] = 1; // 1�� ��ٸ�
		if (N == 2) continue;
		if (num == 1) ladder[num + 1][pos] = 2; // 2�� ��ٸ� ������
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