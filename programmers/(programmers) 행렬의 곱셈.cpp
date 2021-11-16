#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    for (int j = 0; j < arr1.size(); j++) {
        for (int i = 0; i < arr2[0].size(); i++) {
            for (int k = 0; k < arr1[0].size(); k++) {
                answer[j][i] += arr1[j][k] * arr2[k][i];
            }
        }
    }

    return answer;
}