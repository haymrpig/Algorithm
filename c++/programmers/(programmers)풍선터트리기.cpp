#include <string>
#include <vector>

/*
    시작 18:00
    종료 19:00
    - logic
    1. 자신보다 왼쪽, 오른쪽 값들 중 각각의 최소값이 자신보다 둘 다 작은 경우는 마지막까지 남지 못한다. 
    방법1.
    -> 왼쪽과 오른쪽의 최소값들을 구한다.
    -> 현재 숫자와 왼쪽, 오른쪽 최소값을 비교하여 만약 둘 다 작은 경우, 정답에서 제외한다. 
    -> 이 방법의 경우 최소값을 왼쪽에서, 오른쪽에서 모두 구해야 하기 때문에 비효율적이다. 방법2에는 stack을 이용한 효율적인 코드이다. 
*/
using namespace std;

int solution(vector<int> a) {
    int answer = a.size();
    vector<int> smallestLeft(a.size(), 0);
    vector<int> smallestRight(a.size(), 0);
    smallestLeft[0] = a[0];
    smallestRight[a.size() - 1] = a[a.size() - 1];
    for (int i = 1; i < a.size(); i++) {
        smallestLeft[i] = min(a[i], smallestLeft[i - 1]);
    }
    for (int i = a.size() - 2; i >= 0; i--) {
        smallestRight[i] = min(a[i], smallestRight[i + 1]);
    }

    int left, right;
    for (int i = 1; i < a.size() - 1; i++) {
        left = smallestLeft[i - 1];
        right = smallestRight[i + 1];
        if (a[i] > left && a[i] > right) answer--;
    }
    return answer;
}

/*
* 방법2
* -> stack이 비어있지 않고 현재 숫자가 stack의 값보다 큰 경우는 그냥 push한다. 
* -> stack이 비어있을 경우 그냥 push한다. 
* -> 만약 새로운 값이 stack의 값보다 작은 경우, pop한다. 
* -> 여기서 stack에 쌓이는 값들은 본인의 왼쪽에 자신보다 작은 값이 존재하는 값들이다. 
* -> 새로 들어온 값이 본인보다 작은 경우는 pop을 하는데, 이 때는 오른쪽의 값 중 자신보다 작은 값이 존재하는 의미이므로 처음 생각했던 logic대로, 왼쪽, 오른쪽 모두 자신보다 작은 값이 존재하는 것을 의미한다. 
* -> 따라서, pop을 하면서 정답에서 제외한다.
* 
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int solution(vector<int> a) {
    int answer = a.size();
    stack<int> stack;
    // stack에 들어있는 값들은 처음 숫자이거나,자신보다 왼쪽에 작은 값이 있는 숫자들이다.
    // 새로 확인할 숫자가 stack의 있는 값보다 작은 경우, 그 숫자는 자신의 왼쪽, 오른쪽 모두 자신보다 작은 숫자가 있는 경우로 최후까지 남기는 것이 불가능하다. 

    for (int comp : a) {
        while (!stack.empty() && comp < stack.top()) {
            stack.pop();
            if (!stack.empty())
                answer--;
        }
        stack.push(comp);
    }
    return answer;
}
*/