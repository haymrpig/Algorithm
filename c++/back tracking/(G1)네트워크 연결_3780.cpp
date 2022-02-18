#include <iostream>
#include <vector>

/*
*	- Logic
*	1. �θ� �����ϴ� ���Ϳ� ����ġ�� �����ϴ� ���͸� �����, ó������ �θ�� ����ġ�� ����Ͽ� �����Ѵ�.
*	2. �Ź� ���� ���ں��� root���� �θ� ����ؼ� Ÿ�� �ö󰡸� ��ȿ�����̹Ƿ�, ���� ���ں��� root���� ã��, 
*		back tracking�ϸ鼭 ����ġ�� �θ� root�� �������ش�. 
*/
using namespace std;

int updateDist(vector<int>& parents, vector<int>& length, int num) {
	/**	root�� ã��, �� �Ʒ� �ڽĵ��� ����ġ�� �θ� �����ϴ� �Լ��̴�. 
	*		root�κ����� �Ÿ��� ���ؾ��ϹǷ�, root�� �ڽĵ��� �ڱ� �ڽ��� �θ���� root������ �Ÿ��� ��� ���ؾ� �Ѵ�. 
	*		����, root������ �Ÿ��� ���ߴٸ�, �ٷ� root�� ������ �־�, �ٽ� �� �Լ��� ȣ�� ���� �� �ߺ����� �Ÿ��� ������ �ʵ��� �Ѵ�. 
	*	
	*	@param		parents		�� ����� �θ� ������ ����
	*	@param		length		�� ���κ��� �θ������ �Ÿ�
	*	@param		num			���� ��� ��ȣ
	* 
	*	@return		root�� ��ȣ
	*/
	if (parents[num] == num) return num;
	int temp;
	temp = updateDist(parents, length, parents[num]);
	length[num] += length[parents[num]];
	parents[num] = temp;
	return parents[num];
}
void makeLink(vector<int>& parents, vector<int>& length, int num1, int num2) {
	/**	�ι�° ���ڸ� ù��° ������ �θ�� �����ϰ�, �Ÿ��� ���Ͽ� �����Ѵ�. 
	*		�ι�° ���ڿ� ù��° ������ �Ÿ��� �־��� ����(abs(n1-n2)mod(1000) )���� ����Ѵ�.
	* 
	*	@param		parents		�� ����� �θ� ������ ����
	*	@param		length		�� ���κ��� �θ������ �Ÿ�
	*	@param		num1		ù��° ����
	*	@param		num2		�ι�° ����
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