#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    시작 21:28
    종료 21:58
    풀이 1 ( 내가 푼 것 )
    - 어떠한 노드가 다른 모든 노드와의 이기고 지는 관계가 명확해야 한다. 
    - 이중 배열로 이기는 경우 2, 지는 경우 1, 관계가 없는 경우 0으로 초기 setting을 한다. 
    - 1번 노드부터 관계가 있는 노드를 탐색한다. 
        -> 만약 1번이 그 노드를 이겼다면( 2라면 ) 그 노드가 이긴 노드들은 1번과의 관계가 명확해진다. ( 1번이 모두를 이김 )
        -> 만약 1번이 그 노드에게 졌다면( 1이라면 ) 그 노드가 진 노드들은 1번과의 관계가 명확해진다. ( 1번이 모두에게 짐 )
    - 이러한 방식으로 1번부터 n번까지 탐색하고, 그 과정을 n-1번 반복하면 모든 노드들의 관계가 정립된다. 
    - 4중 for문이지만 n의 범위가 100까지이므로 O(n^4)으로 시간안에 해결이 가능하다.

    ****이 풀이보다 좋은 풀이가 있어 아래 설명해 놓았다.****
 */

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> output(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < results.size(); i++) {
        int win = results[i][0];
        int lose = results[i][1];
        output[win][lose] = 2;
        output[lose][win] = 1;
    }

    for (int p = 0; p < n-1; p++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (output[i][j] != 0) {
                    int winLose = output[i][j];
                    for (int k = 1; k < n + 1; k++) {
                        if (k == j || k == i) continue;
                        if (output[j][k] == winLose) output[i][k] = winLose;
                    }
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        int sum = 0;
        for (int j = 1; j < n + 1; j++) {
            if (output[i][j] == 0) sum++;
        }
        if (sum > 1) continue;
        answer++;
    }

    return answer;
}

/*
    풀이 2
    - 플로이드 워샬 알고리즘을 응용한 풀이이다. 
    - 풀이1에서는 이기고 지는 관계를 정의했지만, 여기서는 이기는 관계만 정의한다. 
        -> 플로이드 워샬에서는 거쳐갈 수 있는 모든 노드를 탐색하여 가중치를 저장하지만, 이 경우에는 이기는 경우로만 노드를 탐색한다. 
        -> 즉, 현재 노드가 확실하게 이기는 노드에 대해서만 관계를 정립한 것이다. 
    - 탐색 결과를 output 이중배열에 저장한다. 
    - i번째 노드의  j번째 노드와의 관계 output[i][j] + output[j][i]의 모든 합이 자기자신을 제외한 n-1이라면 순위를 매길 수 있다. 
        -> output[i][j]는 i가 이기는 경우
        -> output[j][i]는 i가 지는 경우
        -> i가 지고 이기고의 관계가 명확하면 순위를 매길 수 있다. 
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> output(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < results.size(); i++) {
        int win = results[i][0];
        int lose = results[i][1];
        output[win][lose] = 1;
    }

    for (int k = 1; k < n + 1; k++) {
        // 거쳐가는 노드 
        for (int i = 1; i < n + 1; i++) {
            // 출발 노드
            for (int j = 1; j < n + 1; j++) {
                // 끝 노드 
                if (output[i][k] && output[k][j]) output[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        int sum = 0;
        for (int j = 1; j < n + 1; j++) {
            sum += (output[i][j] + output[j][i]);
        }
        if (sum == n - 1) answer++;
    }

    return answer;
}