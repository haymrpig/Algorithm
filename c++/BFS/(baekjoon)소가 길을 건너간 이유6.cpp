#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, R;
int findNormalRoute(vector<int> &cow, vector<vector<int>>& info, int x, int y) {
	/** find path to other cows without crossing the road
	* 
	* With BFS algorithm,find all possible path to other blocks from the start coordinate.
	* If there is road between previous block and next block, do not push into queue.
	* Or if coordinates are out of list bound keep finding other path.
	* 
	* @param	cow	Positions of cows
	*				info	Information about roads
	*				x		Row Coordinate of beginning cow
	*				y		Col Coordinate of beginning cow
	* 
	* @return	number of cows that the beginning cow can meet without passing any road
	*/
	vector<vector<int>> check(N, vector<int>(N, 0));
	
	queue<pair<int, int>> q;
	q.push({ x, y });
	
	check[x][y] = 1;
	int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
	
	int answer = 0;
	while (!q.empty()) {
		int prex = q.front().first;
		int prey = q.front().second;
		int start = prex * N + prey;
		q.pop();
		if (cow[start] == 1) answer++;
		for (int i = 0; i < 4; i++) {
			int nextx = prex + dx[i];
			int nexty = prey + dy[i];
			
			if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N || check[nextx][nexty] == 1) continue;
			
			int end = nextx * N + nexty;
			int j;
			for (j = 0; j < info[start].size(); j++) {
				if (info[start][j] == end) break;
			}
			if (j != info[start].size()) continue;
			q.push({ nextx, nexty });
			check[nextx][nexty] = 1;
		}
	}

	return answer-1;
}

int main() {
	cin >> N >> K >> R;

	vector<vector<int>> info(N*N);
	vector<int> cow(N*N, 0);

	for (int i = 0; i < R; i++) {
		int x, y, x_1, y_1;
		cin >> x >> y >> x_1 >> y_1;

		int start = (x - 1) * N + (y - 1);
		int end = (x_1 - 1) * N + (y_1 - 1);
		info[start].push_back(end);
		info[end].push_back(start);
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		int index = (x - 1) * N + (y - 1);
		cow[index] = 1;
	}

	int answer = 0;

	for (int i = 0; i < cow.size(); i++) {
		if (cow[i] == 1) {
			int x = i / N;
			int y = i % N;
			answer += findNormalRoute(cow, info, x, y);
		}
	}
	cout << K*(K-1)/2 -  answer / 2 << endl;

}