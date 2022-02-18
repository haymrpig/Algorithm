#include <iostream>
#include <vector>

/*
*	- Logic
*	1. 부모를 저장하는 벡터와 가중치를 저장하는 벡터를 만들고, 처음에는 부모와 가중치를 계산하여 대입한다.
*	2. 매번 현재 숫자부터 root까지 부모를 계속해서 타고 올라가면 비효율적이므로, 현재 숫자부터 root까지 찾고, 
*		back tracking하면서 가중치와 부모를 root로 갱신해준다. 
*/
using namespace std;

int updateDist(vector<int>& parents, vector<int>& length, int num) {
	/**	root를 찾고, 그 아래 자식들의 가중치와 부모를 갱신하는 함수이다. 
	*		root로부터의 거리를 구해야하므로, root의 자식들은 자기 자신의 부모부터 root까지의 거리를 모두 더해야 한다. 
	*		또한, root까지의 거리를 구했다면, 바로 root로 연결해 주어, 다시 이 함수가 호출 됐을 때 중복으로 거리를 더하지 않도록 한다. 
	*	
	*	@param		parents		각 노드의 부모를 저장한 벡터
	*	@param		length		각 노드로부터 부모까지의 거리
	*	@param		num			현재 노드 번호
	* 
	*	@return		root의 번호
	*/
	if (parents[num] == num) return num;
	int temp;
	temp = updateDist(parents, length, parents[num]);
	length[num] += length[parents[num]];
	parents[num] = temp;
	return parents[num];
}
void makeLink(vector<int>& parents, vector<int>& length, int num1, int num2) {
	/**	두번째 숫자를 첫번째 숫자의 부모로 갱신하고, 거리를 구하여 저장한다. 
	*		두번째 숫자와 첫번째 숫자의 거리는 주어진 공식(abs(n1-n2)mod(1000) )으로 계산한다.
	* 
	*	@param		parents		각 노드의 부모를 저장한 벡터
	*	@param		length		각 노드로부터 부모까지의 거리
	*	@param		num1		첫번째 숫자
	*	@param		num2		두번째 숫자
	*/
	parents[num1] = num2;
	length[num1] = abs(num1 - num2) % 1000;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> parents(N + 1);
		for (int i = 0; i < N + 1; i++) parents[i] = i;
		vector<int> length(N + 1, 0);
		while (1) {
			char order;
			cin >> order;
			if (order == 'O') break;
			else if (order == 'E') {
				int num;
				cin >> num;
				updateDist(parents, length, num);
				cout << length[num] << "\n";
			}
			else {
				int num1, num2;
				cin >> num1 >> num2;
				makeLink(parents, length, num1, num2);
			}
		}
	}
}