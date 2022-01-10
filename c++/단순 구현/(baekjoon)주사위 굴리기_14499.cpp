#include <iostream>
#include <vector>
#include <queue>
/*
*	-Logic
*	1. 단순히 구현 문제이지만, 여기서 중요한 것은 주사위를 굴릴 때마다 값을 주사위에 잘 표현하는 것이다.
*	2. 주사위의 전개도를 생각해서 1,3,4,5,7,10번 index에 주사위의 값을 할당해 주었다. 
*		-> 4는 항상 아랫면, 10을 윗 면으로 두었다. 
*		-> 동,서로 굴릴 때는 1,7을 제외한 면의 값을 이동시켜줘야 한다.
*		-> 남,북으로 굴릴 때는 3,5를 제외한 면의 값을 이동시켜줘야 한다.
*	3. 나머지는 조건에 맞춰 조건문을 걸어주어 해결하였다. 
*/
using namespace std;

void RollDice(int direction, vector<int>& dice) {
	int temp;
	switch (direction) {
	case 0:
		temp = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[10];
		dice[10] = dice[3];
		dice[3] = temp;
		break;
	case 1:
		temp = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[10];
		dice[10] = dice[5];
		dice[5] = temp;
		break;
	case 2:
		temp = dice[1];
		dice[1] = dice[10];
		dice[10] = dice[7];
		dice[7] = dice[4];
		dice[4] = temp;
		break;
	case 3:
		temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[7];
		dice[7] = dice[10];
		dice[10] = temp;
		break;
	default:
		break;
	}
	return;
}

int main() {
	int N, M, cur_x, cur_y, num_order;
	cin >> N >> M >> cur_x >> cur_y >> num_order;
	vector<vector<int>> dice_map(N, vector<int> (M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> dice_map[i][j];
		}
	}
	queue<int> order;
	int order_temp;
	for (int i = 0; i < num_order; i++) {
		cin >> order_temp;
		order.push(order_temp);
	}
	vector<int> dice(12, 0);
	int next_x, next_y;
	int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
	int first_try = 0;
	while (!order.empty()) {
		int direction = order.front()-1;
		order.pop();
		next_x = cur_x + dx[direction];
		next_y = cur_y + dy[direction];
		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
			if( first_try ) cout << '\n';
			first_try++;
			RollDice(direction, dice);
			if (dice_map[next_x][next_y] == 0) {
				dice_map[next_x][next_y] = dice[4];
			}
			else {
				dice[4] = dice_map[next_x][next_y];
				dice_map[next_x][next_y] = 0;
			}
			cout << dice[10];
			cur_x = next_x;
			cur_y = next_y;
		}
	}
}