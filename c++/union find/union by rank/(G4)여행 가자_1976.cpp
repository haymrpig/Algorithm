#include <iostream>
#include <vector>

using namespace std;

int findParents(vector<int>& parents, int idx) {
	if (parents[idx] == idx) return idx;
	return parents[idx] = findParents(parents, parents[idx]);
}

void makeUnion(vector<int>& parents, vector<int>& rank, int a, int b) {
	a = findParents(parents, a);
	b = findParents(parents, b);

	if (a == b) return;
	else if (rank[a] > rank[b]) {
		parents[b] = a;
		rank[a]++;
	}
	else {
		parents[a] = b;
		rank[b]++;
	}
}

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	vector<int> parents(N + 1);
	for (int i = 0; i < N + 1; i++) {
		parents[i] = i;
	}
	vector<int> rank(N + 1, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int check;
			cin >> check;
			if (check) {
				makeUnion(parents, rank, i + 1, j + 1);
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < M; i++) {
		int idx;
		cin >> idx;
		v.push_back(idx);
	}

	int root = findParents(parents, v[0]);
	for (int i = 1; i < M; i++) {
		if (root != findParents(parents, v[i])){
				cout << "NO";
				return 0;
		}
	}
	cout << "YES";
	return 0;
}