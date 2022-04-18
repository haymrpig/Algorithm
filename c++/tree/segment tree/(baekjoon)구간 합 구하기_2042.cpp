#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll init(vector<ll>& tree, vector<ll>& numbers,  int start, int end, int node) {
	if (start == end) {
		// 리프 노드인 경우 
		tree[node] = numbers[start];
		return tree[node];
	}

	int mid = (start + end) / 2;
	tree[node] = init(tree, numbers, start, mid, node * 2) + init(tree, numbers, mid + 1, end, node * 2 + 1);
	// 왼쪽 자식과 오른쪽 자식의 합을 부모 노드에 저장
	return tree[node];
}

void update(vector<ll>& tree, int start, int end, int idx, int node, ll diff) {
	if (start > idx || end < idx) return;
	// 만약 update할 index가 해당 노드의 범위 밖인 경우
	
	tree[node] += diff;
	// 만약 update할 index가 해당 노드 범위 내라면, 차이를 더해준다.

	if (start != end) {
		// 리프 노드가 아닐 경우, 자식 노드 탐색
		int mid = (start + end) / 2;
		update(tree, start, mid, idx, node * 2, diff);
		update(tree, mid + 1, end, idx, node * 2 + 1, diff);
	}
}

ll sum(vector<ll>& tree, int start, int end, int left, int right, int node) {
	if (left > end || right < start) return 0;
	// 만약 범위 밖이라면 더 이상 자식 노드를 탐색하지 않는다.

	if (left <= start && end <= right) return tree[node];
	// 만약 범위 내라면 현재 노드 값 반환 ( 자식 노드도 어차피 범위 안에 속하고, 부모가 자식노드들의 합이므로 더이상 탐색 X )

	int mid = (start + end) / 2;
	return sum(tree, start, mid, left, right, node * 2) + sum(tree, mid + 1, end, left, right, node * 2 + 1);
	// 자식 노드 탐색
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