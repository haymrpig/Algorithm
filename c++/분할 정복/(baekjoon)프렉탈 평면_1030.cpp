#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, K, R1, R2, C1, C2;

int CheckBlock(int len, int x, int y) {
	if (len == 1) return 0;
	len /= N;
	if ((len * (N - K) / 2 <= x && x < len * (N + K) / 2) && (len * (N - K) / 2 <= y && y < len * (N + K) / 2)) {
		// 만약 좌표 (x,y)가 중앙에 위치한다면 검정색이다. 
		return 1;
	}
	return CheckBlock(len, x % len, y % len);
	// 만약 좌표 (x,y)가 중앙에 위치하지 않았다면 이전 단계를 확인해봐야한다.
	// 이때 위에서 이미 len에서 N을 나눴기 때문에 그대로 len을 넘겨주고,
	// x,y좌표는 나머지 연산을 취해주는데 그 이유는 전체 길이가 len이였을 때는 x,y가 맞지만
	// 그 이전 단계로 가면 len/N x len/N으로 축소가 된다. 그리고 이 축소된 보드는 중앙을 제외한 8개에 동일하게 위치한다.
	// 예를 들어
	// 000
	// 010
	// 000 이 있으면 이 다음 단계에서 이 3x3블록은 좌상단, 중앙상단, 우상단, 좌측, 우측, 좌하단, 중앙하단, 우하단 이렇게 똑같이 복제가 된다. 그리고 중앙은 검정색으로 채워진다. 
	// 따라서, len/N x len/N으로 축소되었을 때, x,y좌표도 그에 따라 축소가 되어야 하고,
	// x/len, y/len로 크게 9덩이로 구분된 영역에서 몇번째 영역인지 구할 수 있지만, 몇 번째 영역인지는 중요하지 않으니
	// 그 영역에서 index가 어떻게 되는지 알기 위해서는 나머지 연산을 취해야 한다. 
}
int main() {
	int s;
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	int len = 1;
	if (s == 0) {
		cout << 0;
		return 0;
	}
	len = pow(N, s);
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			// 각 포인트마다 분할정복을 통해서 값을 구한다. 
			cout << CheckBlock(len, i, j);
		}
		cout << '\n';
	}


}