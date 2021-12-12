#include <vector>
#include <iostream>
#include <queue>
/*
*  - Logic
*  1. 위상 정렬 문제이다. ( 어떤 작업들을 수행할 때 순서가 정해져 있는 경우 )
*		-> 단방향, 사이클이 존재하지 않는 경우 사용 가능
*		-> 답이 여러개가 존재할 수 있다. 
*	순서
*	1. 현재 자신 노드로 들어오는 간선이 존재하는 경우 간선 개수당 +1
*	2. 모든 노드의 값을 구함
	3. q에 값이 0인 노드를 삽입
*	4. q에서 pop한 노드와 연결된 노드의 값 -1, pop한 노드를 정답 배열에 저장
*		-> 만약 연결된 노드의 값이 0일 될 경우 3번 수행
*	5. 만약 모든 노드를 방문하기 전에 queue가 비어있게 된다면 사이클이 존재하는 문제이므로 return -1
*  6. 정답 배열을 순서대로 출력
*		
*/
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> answer;
	vector<vector<int>> link(N + 1);
	vector<int> weight(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		link[A].push_back(B);
		weight[B] += 1;
	}
	queue<int> q;
	for (int i = 1; i < N+1; i++) {
		if (weight[i] == 0) q.push(i);
	}
	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			cout << "impossible" << endl;
			return -1;
		}

		int pn = q.front();
		q.pop();
		answer.push_back(pn);
		for (auto nn : link[pn]) {
			if (--weight[nn] == 0) {
				q.push(nn);
			}
		}
	}

	for (auto x : answer) cout << x << " ";
	


}