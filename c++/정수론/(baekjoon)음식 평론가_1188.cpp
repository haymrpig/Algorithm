#include <iostream>
/*
소세지 개수가 몇개든 하나로 봤을 때, M명껄로 나누려면 총 M-1번을 잘라야 한다.
하지만, N개로 나눠져 있을 경우에는 N-1번 이미 잘려져 있기 때문에, 겹치는 잘리는 부분을 제거해줘야 한다. 
M과 N의 최대공약수를 구한 뒤 -1을 해주고 M - 1 - ( GCD(M, N) - 1)을 해준다. 
*/
using namespace std;

int GCD(int a, int b) {
	return a % b == 0 ? b : GCD(b, a % b);
}

int main() {
	int N, M;
	cin >> N >> M;
	if (N % M == 0) cout << 0 << endl;
	else cout << M - 1 - (GCD(M, N) - 1) << endl;
}