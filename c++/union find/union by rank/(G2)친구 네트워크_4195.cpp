#include <iostream>
#include <vector>
#include <map>
#include <string>
#define MAX_NUM 200002

/*
*	1. 단순하게 생각해서 union find를 진행하면 된다. 나는 시간을 단축시키기 위해 union by rank를 사용했다.
* 
*	- hidden test case를 잡는데 오래 걸렸다;;;
*	1. 소문자, 대문자를 구분해서 이름이 되어있는 것을 나는 모두 소문자로 바꿔주는 작업을 했다;;
*		-> 즉, Bird랑 bird랑은 같은 이름으로 취급했는데 이러면 안된다...
*	2. 시간초과는 입출력 관련해서 코드를 추가하면 해결됐다. 
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