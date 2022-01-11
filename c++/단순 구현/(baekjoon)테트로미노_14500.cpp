#include <iostream>
#include <vector>
/*
*	-Logic
*	1. ���� ��� ������ ���� Ǯ����. 
*	2. �� ��� ������ ������ ������ ������ �Ѵٴ� �������� �ִ�. 
* 
*	!!! �ٸ� Ǯ�� !!!
*	- ������ �� 4���� ������� �����Ǿ��ִٴ� ������ DFS�� �̿��Ͽ� depth�� 0���� �����Ͽ� 3������ ���� ���ϴ� ����� �ִ�. 
*	- �ٸ�, '��'����� ���, DFS�δ� ǥ���� �ȵǱ� ������ ���� ����Ͽ��� �Ѵ�. 
*	=> �� ����� �����ϱ⿡ ���� ���� �� ����. ( ȸ���ϴ� �Լ��� ������� �ʿ䰡 ���� )
*/
using namespace std;

void Rotate(int (*tetro)[4]) {
	int temp[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = tetro[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int temp_num = temp[i][j];
			tetro[j][3-i] = temp_num;
		}
	}
	return;
}
int main() {
	int tetro[7][4][4] = { {1,1,1,1,
									0,0,0,0,
									0,0,0,0,
									0,0,0,0},
									
								  {1,1,0,0,
									1,1,0,0,
									0,0,0,0,
									0,0,0,0},
		
								   {1,0,0,0,
									1,0,0,0,
									1,1,0,0,
									0,0,0,0},

								   {0,1,0,0,
									0,1,0,0,
									1,1,0,0,
									0,0,0,0},
		
								  {1,0,0,0,
									1,1,0,0,
									0,1,0,0,
									0,0,0,0},
						
								  {0,1,0,0,
									1,1,0,0,
									1,0,0,0,
									0,0,0,0},
									
								  {1,1,1,0,
									0,1,0,0,
									0,0,0,0,
									0,0,0,0} };

	int N, M;
	cin >> N >> M;
	vector<vector<int>> blocks(N + 6, vector<int>(M + 6, 0));
	for (int i = 3; i < N+3; i++) {
		for (int j = 3; j < M+3; j++) {
			cin >> blocks[i][j];
		}
	}

	int sum, answer=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			Rotate(tetro[j]);
			for (int x = 0; x < N+3; x++) {
				for (int y = 0; y < M+3; y++) {
					sum = 0;
					for (int p = 0; p < 4; p++) {
						for (int q = 0; q < 4; q++) {
							if (tetro[j][p][q] == 0 ) continue;
							sum += blocks[p + x][q + y] * tetro[j][p][q];
						}
					}
					answer = max(answer, sum);
				}
			}
		}
	}
	cout << answer;
}