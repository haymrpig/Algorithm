#include <iostream>
#include <vector>
/*
*	-Logic
*	1. ������ ���� ���� ������ ã��, �� ���� �翷 �� ���� ������ ������ �Ѵ�.
*	2. ��� �ݺ�
*  
*	!!!! ���� �ذ�� ��ٷο��� �κ� !!!!
*	1. ��ʸ�Ʈ�̱� ������ �ݺ����� �Ϸ� ������ while(--n)���� �ְ�, ���Ḯ��Ʈ���� ����� ���̵鸸 �˻��ϱ� ���� n�� �ݺ��ϴ� for���� �ۼ��Ͽ��µ�, �̶�, n�� �Ἥ �ݺ��� �� �Ǿ���. -> n���� t.size()��ŭ �ݺ��ϴ� ������ �ذ�
*	2. n=1�� ��, �� 1�� ������ �� ���Ḯ��Ʈ ���� �� �޸� ���� ������ �߻��Ͽ� ���� ����ó�����־���.
*	3. prev�� next�� �������� ���� ��쿡 ���� ���ǹ��� ���� ��ٷο���. 
*  4. �迭�� ���� �����ذ��鼭 �ص� ������, �����ϸ鼭 ���� ������ ������ ��ܾ��ϴ� �ݺ����� ��ȿ������ ���̶� �����Ͽ� ���Ḯ��Ʈ�� �Ͽ���.
*/
using namespace std;

struct tree {
	int number;
	struct tree* next;
	struct tree* prev;
	tree(int num) :number(num), next(nullptr), prev(nullptr) {};
};
int main(int * argc, char ** argv) {
	int n;
	cin >> n;

	vector<int> info(n);
	for (int i = 0; i < n; i++) {
		cin >> info[i];	
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector<tree*> t(n);
	for (int i = 0; i < n; i++) t[i] = new tree(info[i]);

	t[0]->next = t[1];
	for (int i = 1; i < n-1; i++) {
		t[i]->prev = t[i - 1];
		t[i]->next = t[i + 1];
	}
	t[n-1]->prev = t[n - 2];

	int sum = 0;
	while (--n) {
		int max_num = 0;
		tree* index = nullptr;
		for (int j=0;j<t.size();j++) {
			tree* i = t[j];
			if (i->next == nullptr && i->prev == nullptr ) continue;
			if (max_num < i->number) {
				max_num = i->number;
				index = i;
			}
		}
		int left_num=257, right_num=257;
		if (index->prev != nullptr && index->next != nullptr) {
			left_num = index->prev->number;
			right_num = index->next->number;

			if (abs(left_num - max_num) > abs(right_num - max_num)) {
				sum += abs(right_num - max_num);
				index->number = right_num;
				tree* temp = index->next->next;
				index->next->prev = nullptr;
				index->next->next = nullptr;

				if (temp != nullptr) {
					temp->prev = index;
					index->next = temp;
				}
				else {
					index->next = nullptr;
				}
			}
			else {
				sum += abs(left_num - max_num);
				index->number = left_num;
				tree* temp = index->prev->prev;
				index->prev->prev = nullptr;
				index->prev->next = nullptr;
				if (temp != nullptr) {
					temp->next = index;
					index->prev = temp;
				}
				else {
					index->prev = nullptr;
				}
			}
		}
		else if (index->next == nullptr) {
			left_num = index->prev->number;
			sum += abs(left_num - max_num);
			index->number = left_num;
			tree* temp = index->prev->prev;
			index->prev->prev = nullptr;
			index->prev->next = nullptr;
			if (temp != nullptr) {
				temp->next = index;
				index->prev = temp;
			}
		}
		else if (index->prev == nullptr) {
			right_num = index->next->number;
			sum += abs(right_num - max_num);
			index->number = right_num;
			tree* temp = index->next->next;
			index->next->prev = nullptr;
			index->next->next = nullptr;
			if (temp != nullptr) {
				temp->prev = index;
				index->next = temp;
			}
		}
	}
	cout << sum;
	for (int i = 0; i < n; i++) {
		delete t[i];
	}
	return 0;
	
}