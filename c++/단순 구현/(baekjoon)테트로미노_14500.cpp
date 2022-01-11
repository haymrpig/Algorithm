#include <iostream>
#include <vector>
/*
*	-Logic
*	1. 직접 모든 도형을 만들어서 풀었다. 
*	2. 이 경우 일일이 손으로 도형을 만들어야 한다는 불편함이 있다. 
* 
*	!!! 다른 풀이 !!!
*	- 도형의 총 4개의 블록으로 구성되어있다는 점에서 DFS를 이용하여 depth가 0부터 시작하여 3까지의 합을 구하는 방법도 있다. 
*	- 다만, 'ㅜ'모양의 경우, DFS로는 표현이 안되기 때문에 따로 계산하여야 한다. 
*	=> 이 방법이 구현하기에 더욱 편리할 것 같다. ( 회전하는 함수를 만들어줄 필요가 없음 )
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