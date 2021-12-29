#include <iostream>
#include <vector>
#define INF 100000000
/*
*	- Logic
*	1. 단순 DFS 문제이다. -> 상하좌우로 움직일 수 있으며 동전을 하나 먼저 떨어트리거나 10번 초과 버튼 클릭 시 종료된다.
* 
*	!! 주의 !!
*	1. 10번 보다 많이 = 10번 초과
*	2. 동전을 하나만 떨어트려야 하므로 조건을 잘 세워야 한다. 
*/
using namespace std;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int N, M;
int answer = INF;
void MoveCoin(vector<vector<char>>& board, vector<pair<int,int>>coin_pos,  int depth) {
	if (depth > 10 || depth >= answer) {
		return;
	}
	int px1 = coin_pos[0].first;
	int py1 = coin_pos[0].second;
	int px2 = coin_pos[1].first;
	int py2 = coin_pos[1].second;

	
	for (int i = 0; i < 4; i++) {
		bool flag1 = false, flag2 = false;
		int nx1 = px1 + dx[i];
		int ny1 = py1 + dy[i];
		int nx2 = px2 + dx[i];
		int ny2 = py2 + dy[i];
		if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M) flag1 = true;
		if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= M) flag2 = true;
		if (flag1 && flag2) continue;
		else if (flag1 || flag2) {
			answer = min(answer, depth);
			return;
		}
		else {
			vector <pair<int, int>> temp;
			if (board[nx1][ny1] == '#') {
				nx1 = px1;
				ny1 = py1;
			}
			if (board[nx2][ny2] == '#') {
				nx2 = px2;
				ny2 = py2;
			}
			temp.push_back({ nx1,ny1 });
			temp.push_back({ nx2,ny2 });
			MoveCoin(board, temp, depth + 1);
		}
	}

}
int main(int* argc, char** argv) {
	N = 0, M = 0;
	cin >> N >> M;
	vector<vector<char>> board(N, vector<char>(M));
	vector<pair<int, int>> coin_pos;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				coin_pos.push_back({ i,j });
			}
		}
	}
	MoveCoin(board, coin_pos, 1);
	answer = answer == INF ? -1 : answer;
	cout << answer;

}