#include <iostream>
#include <vector>
#include <queue>
/*
*	-Logic
*	1. �ܼ��� ���� ����������, ���⼭ �߿��� ���� �ֻ����� ���� ������ ���� �ֻ����� �� ǥ���ϴ� ���̴�.
*	2. �ֻ����� �������� �����ؼ� 1,3,4,5,7,10�� index�� �ֻ����� ���� �Ҵ��� �־���. 
*		-> 4�� �׻� �Ʒ���, 10�� �� ������ �ξ���. 
*		-> ��,���� ���� ���� 1,7�� ������ ���� ���� �̵�������� �Ѵ�.
*		-> ��,������ ���� ���� 3,5�� ������ ���� ���� �̵�������� �Ѵ�.
*	3. �������� ���ǿ� ���� ���ǹ��� �ɾ��־� �ذ��Ͽ���. 
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