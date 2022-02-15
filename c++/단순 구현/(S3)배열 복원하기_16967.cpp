#include <iostream>
#include <vector>
/*
*	- Logic
*	1. X�� Y�� 1 �̻��̹Ƿ� ó�� B�� �»���� �׻� A�� ���̴�.
*	2. ��� ���� �ŵ��ϸ鼭 ���� A�� ������ �׳� B���� �����´�.
*	3. ���� ��ġ�� �κ��� ��Ÿ���� B���� A(�̵��� X��ŭ ������ �̵��� ��ǥ, �̵��� Y��ŭ ������ �̵��� ��ǥ)�� ���ش�.
*/
using namespace std;

int main() {
	int H, W, X, Y;
	cin >> H>> W>> X>> Y;

	vector<vector<int>> B(H + X, vector<int>(W + Y));
	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}
	vector<vector<int>> A(H, vector<int>(W));
	vector<vector<int>> A_temp(H, vector<int>(W, 0));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W ; j++) {
			if (i < X) A[i][j] = B[i][j];
			else if (j < Y) A[i][j] = B[i][j];
			else {
				A[i][j] = B[i][j] - A[i - X][j - Y];
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	
	
}