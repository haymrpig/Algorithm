#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll init(vector<ll>& tree, vector<ll>& numbers,  int start, int end, int node) {
	if (start == end) {
		// ���� ����� ��� 
		tree[node] = numbers[start];
		return tree[node];
	}

	int mid = (start + end) / 2;
	tree[node] = init(tree, numbers, start, mid, node * 2) + init(tree, numbers, mid + 1, end, node * 2 + 1);
	// ���� �ڽİ� ������ �ڽ��� ���� �θ� ��忡 ����
	return tree[node];
}

void update(vector<ll>& tree, int start, int end, int idx, int node, ll diff) {
	if (start > idx || end < idx) return;
	// ���� update�� index�� �ش� ����� ���� ���� ���
	
	tree[node] += diff;
	// ���� update�� index�� �ش� ��� ���� �����, ���̸� �����ش�.

	if (start != end) {
		// ���� ��尡 �ƴ� ���, �ڽ� ��� Ž��
		int mid = (start + end) / 2;
		update(tree, start, mid, idx, node * 2, diff);
		update(tree, mid + 1, end, idx, node * 2 + 1, diff);
	}
}

ll sum(vector<ll>& tree, int start, int end, int left, int right, int node) {
	if (left > end || right < start) return 0;
	// ���� ���� ���̶�� �� �̻� �ڽ� ��带 Ž������ �ʴ´�.

	if (left <= start && end <= right) return tree[node];
	// ���� ���� ����� ���� ��� �� ��ȯ ( �ڽ� ��嵵 ������ ���� �ȿ� ���ϰ�, �θ� �ڽĳ����� ���̹Ƿ� ���̻� Ž�� X )

	int mid = (start + end) / 2;
	return sum(tree, start, mid, left, right, node * 2) + sum(tree, mid + 1, end, left, right, node * 2 + 1);
	// �ڽ� ��� Ž��
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;

	int tree_h = ceil(log2(N));
	int num_tree = (1 << (tree_h+1));
	vector<ll> tree(num_tree, 0);
	vector<ll> numbers(N);
	
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	init(tree, numbers, 0, N - 1, 1);

	int a, b;
	ll c, diff;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			diff = c - numbers[b - 1];
			numbers[b - 1] = c;
			update(tree, 0, N - 1, b - 1, 1, diff);
		}
		else {
			cout << sum(tree, 0, N - 1, b - 1, c - 1, 1) << '\n';
		}
	}

}