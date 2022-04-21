#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> inorder;
vector<int> postorder;
map<int,int> index;

void MakeTree(int inorder_start, int inorder_end, int postorder_start, int postorder_end) {
	if (inorder_start > inorder_end || postorder_start > postorder_end)
		return;

	int root_index = index[postorder[postorder_end]];
	int left_size = root_index - inorder_start;
	int right_size = inorder_end - root_index;

	cout << inorder[root_index] << ' ';

	MakeTree(inorder_start, root_index - 1, postorder_start, postorder_start + left_size - 1);
	MakeTree(root_index + 1, inorder_end, postorder_start + left_size, postorder_end -1);
}
int main() {
	int n;
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		inorder.push_back(a);
		index[a] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		postorder.push_back(a);
	}

	MakeTree(0, n-1,  0, n-1);
}