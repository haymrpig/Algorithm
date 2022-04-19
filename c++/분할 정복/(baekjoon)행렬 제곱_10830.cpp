#include <iostream>
#include <vector>

using namespace std;
int N;
typedef long long ll;
vector<vector<int>> DotProduct(vector<vector<int>>& matrix_a, vector<vector<int>>& matrix_b) {
	vector<vector<int>> matrix_dst(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				matrix_dst[i][j] += matrix_a[i][k] * matrix_b[k][j];
			}
			matrix_dst[i][j]%=1000;
		}
	}
	return matrix_dst;
}
vector<vector<int>> Calculate(vector<vector<int>>& matrix, ll B) {
	if (B == 1) {
		return matrix;
	}
	vector<vector<int>> matrix_temp;

	if (B % 2 == 0) {
		matrix_temp = Calculate(matrix, B / 2);
		return DotProduct(matrix_temp, matrix_temp);
	}
	else {
		matrix_temp = Calculate(matrix, B / 2);
		matrix_temp = DotProduct(matrix_temp, matrix_temp);
		return DotProduct(matrix_temp, matrix);
	}
}
int main() {
	ll B;
	cin >> N >> B;
	
	vector<vector<int>> matrix(N, vector<int>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}

	matrix = Calculate(matrix, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j]%1000 << " ";
		}
		cout << '\n';
	}
}