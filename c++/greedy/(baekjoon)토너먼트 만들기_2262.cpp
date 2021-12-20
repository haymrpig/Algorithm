#include <iostream>
#include <vector>
/*
*	-Logic
*	1. 순위가 가장 낮은 선수를 찾고, 그 선수 양옆 중 낮은 선수와 시합을 한다.
*	2. 계속 반복
*  
*	!!!! 문제 해결시 까다로웠던 부분 !!!!
*	1. 토너먼트이기 때문에 반복문의 완료 조건을 while(--n)으로 주고, 연결리스트에서 연결된 아이들만 검색하기 위해 n번 반복하는 for문을 작성하였는데, 이때, n을 써서 반복이 덜 되었다. -> n말고 t.size()만큼 반복하는 것으로 해결
*	2. n=1일 때, 즉 1명만 존재할 때 연결리스트 연결 시 메모리 참조 오류가 발생하여 따로 예외처리해주었다.
*	3. prev와 next가 존재하지 않을 경우에 대한 조건문이 조금 까다로웠다. 
*  4. 배열로 값을 삭제해가면서 해도 되지만, 삭제하면서 뒤의 값들을 앞으로 당겨야하는 반복에서 비효율적일 것이라 생각하여 연결리스트로 하였다.
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