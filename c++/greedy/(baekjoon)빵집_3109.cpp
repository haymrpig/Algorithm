#include <iostream>
#include <vector>
#include <queue>
/*
*  1. ó������ BFS�� ������ ��, �߰�, �Ʒ� ������ Ž���� �Ϸ� �ߴ�. 
*		-> �� ��� ������ ���� �� �� ���� ���, �߰�, �Ʒ��� Ž������ �ʵ��� ������ �׷� ���, ��ΰ� �����Կ��� ���� �� ã�� �� �ֱ� ������
*		-> BFS�� ����ϱ⿡ �������� �ʾҴ�. 
*  2. DFS�� ������ �ذ��� �� �ð��ʰ��� ���ҷ��� �켱, ��θ� �����Ͽ����� visited�� �״�� 1�� �δ� ���̴�. 
*		-> ���� ��ΰ� �����Ǿ��� ���, �ٽ� back tracking�ؼ� ��θ� Ž������ �ʵ��� flag�� �ϳ� �����־���. 
*		-> �׸��� ��� �������� ���ؼ� DFS�� Ž���� ��� ���� ���� �� �ִ�. 
*		-> greedy�ϰ� Ž���ϱ� ���� ��, �߰�, �Ʒ� ������ Ž���Ѵ�. 
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