#include <string>
#include <vector>

using namespace std;
int max_num = 0;
void DFS(vector<vector<int>>& dungeons, vector<bool>& visited, int life, int cnt) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && life >= dungeons[i][0]) {
            visited[i] = true;
            DFS(dungeons, visited, life - dungeons[i][1], cnt + 1);
            visited[i] = false;
        }
    }
    max_num = max(max_num, cnt);
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visited(dungeons.size(), false);
    DFS(dungeons, visited, k, 0);
    answer = max_num;
    return answer;
}