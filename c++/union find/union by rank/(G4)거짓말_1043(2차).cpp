#include <iostream>
#include <vector>

using namespace std;

int findParent(vector<int>& parents, int idx) {
	if (parents[idx] == idx) return idx;
	return parents[idx] = findParent(parents, parents[idx]);
}

bool isSameParent(vector<int>& parents, int a, int b) {
	if (findParent(parents, a) == findParent(parents, b)) return true;
	else return false;
}

void makeUnion(vector<int>& parents, vector<int>& rank, int a, int b) {
	a = findParent(parents, a);
	b = findParent(parents, b);

	if (a == b) return;
	else if (rank[a] < rank[b]) {
		parents[a] = b;
		rank[b]++;
	}
	else {
		parents[b] = a;
		rank[a]++;
	}
	return;
}


int main() {
	int N, M;
	cin >> N >> M;

	vector<int> parents(N + 1, 0);
	vector<int> rank(N + 1, 0);
	vector<vector<int>> party(M);
	for (int i = 0; i < N + 1; i++) {
		parents[i] = i;
	}

	int num_truth, prev, x, root = 0;
	cin >> num_truth;
	for (int i = 0; i < num_truth; i++) {
		cin >> x;
		if (i == 0) {
			root = x;
			prev = x;
			continue;
		}
		makeUnion(parents, rank, x, prev);
		prev = x;
	}


	int num_p;
	for (int i = 0; i < M; i++) {
		cin >> num_p;
		for (int j = 0; j < num_p; j++) {
			int n;
			cin >> n;
			party[i].push_back(n);
			if (j == 0) continue;
			makeUnion(parents, rank, party[i][j - 1], n);
		}
	}

	root = findParent(parents, root);
	int answer = M;
	for (int i = 0; i < M; i++) {
		if (findParent(parents, party[i][0]) == root) answer--;
	}
	cout << answer;

}