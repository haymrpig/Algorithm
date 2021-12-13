#include <iostream>
#include <vector>
#include <queue>
/*
*  1. 처음에는 BFS로 오른쪽 위, 중간, 아래 순으로 탐색을 하려 했다. 
*		-> 이 경우 오른쪽 위로 갈 수 있을 경우, 중간, 아래는 탐색하지 않도록 했지만 그럴 경우, 경로가 존재함에도 길을 못 찾을 수 있기 때문에
*		-> BFS를 사용하기에 적절하지 않았다. 
*  2. DFS로 문제를 해결할 때 시간초과를 면할려면 우선, 경로를 생성하였으면 visited를 그대로 1로 두는 것이다. 
*		-> 또한 경로가 생성되었을 경우, 다시 back tracking해서 경로를 탐색하지 않도록 flag를 하나 정해주었다. 
*		-> 그리고 모든 시작점에 대해서 DFS로 탐색할 경우 답을 구할 수 있다. 
*		-> greedy하게 탐색하기 위해 위, 중간, 아래 순으로 탐색한다. 
*/
using namespace std;
int dx[3] = { -1,0,1 };
int answer = 0;
bool IsConnected;
void DFS(vector<vector<char>>& map, vector<vector<char>>& visited, int px, int py) {
	if (px < 0 || px >= map.size() || py >= map[0].size() || map[px][py] == 'x' || visited[px][py] == 'o') return;
	visited[px][py] = 'o';
	if (py == map[0].size() - 1) {
		answer++;
		IsConnected = true;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (IsConnected) break;
		DFS(map, visited, px + dx[i], py + 1);
	}
	
}
int main() {
	int R, C;
	cin >> R >> C;
	vector<vector<char>> map(R, vector<char>(C));
	vector<vector<char>> visited(map.begin(), map.end());

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			visited[i][j] = 'x';
		}
	}
	
	for (int i = 0; i < R; i++) {
		IsConnected = false;
		DFS(map, visited, i, 0);
	}
	cout << answer;
	
}