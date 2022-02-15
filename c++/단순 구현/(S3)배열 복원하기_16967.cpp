#include <iostream>
#include <vector>
/*
*	- Logic
*	1. X와 Y는 1 이상이므로 처음 B의 좌상단은 항상 A의 값이다.
*	2. 행과 열을 거듭하면서 원래 A의 영역은 그냥 B에서 가져온다.
*	3. 만약 겹치는 부분이 나타나면 B에서 A(이동한 X만큼 역으로 이동한 좌표, 이동한 Y만큼 역으로 이동한 좌표)를 빼준다.
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