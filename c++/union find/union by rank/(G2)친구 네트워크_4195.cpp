#include <iostream>
#include <vector>
#include <map>
#include <string>
#define MAX_NUM 200002

/*
*	1. �ܼ��ϰ� �����ؼ� union find�� �����ϸ� �ȴ�. ���� �ð��� �����Ű�� ���� union by rank�� ����ߴ�.
* 
*	- hidden test case�� ��µ� ���� �ɷȴ�;;;
*	1. �ҹ���, �빮�ڸ� �����ؼ� �̸��� �Ǿ��ִ� ���� ���� ��� �ҹ��ڷ� �ٲ��ִ� �۾��� �ߴ�;;
*		-> ��, Bird�� bird���� ���� �̸����� ����ߴµ� �̷��� �ȵȴ�...
*	2. �ð��ʰ��� ����� �����ؼ� �ڵ带 �߰��ϸ� �ذ�ƴ�. 
*/
using namespace std;
int findParents(vector<int>& parents, int a) {
	if (parents[a] == a) return a;
	return parents[a] = findParents(parents, parents[a]);
}

void makeUnion(vector<int>& parents, vector<int>& rank, int a, int b) {
	a = findParents(parents, a);
	b = findParents(parents, b);

	if (a == b) {
		return;
	}
	else if (rank[a] < rank[b]) {
		parents[a] = b;
		rank[b] += rank[a];
	}
	else {
		parents[b] = a;
		rank[a] += rank[b];
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		map<string, int> m;
		vector<int> parents(MAX_NUM);
		vector<int> rank(MAX_NUM, 1);
		int idx = 1;

		for (int i = 0; i < parents.size(); i++) {
			parents[i] = i;
		}

		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			if (m[a]) m[a] = idx++;
			if (!m[b]) m[b] = idx++;
			makeUnion(parents, rank, m[a], m[b]);
			int root = findParents(parents, m[a]);
			cout << rank[root] << '\n';
		}
	}
}