#include <string>
#include <vector>

/*
    ���� 18:00
    ���� 19:00
    - logic
    1. �ڽź��� ����, ������ ���� �� ������ �ּҰ��� �ڽź��� �� �� ���� ���� ���������� ���� ���Ѵ�. 
    ���1.
    -> ���ʰ� �������� �ּҰ����� ���Ѵ�.
    -> ���� ���ڿ� ����, ������ �ּҰ��� ���Ͽ� ���� �� �� ���� ���, ���信�� �����Ѵ�. 
    -> �� ����� ��� �ּҰ��� ���ʿ���, �����ʿ��� ��� ���ؾ� �ϱ� ������ ��ȿ�����̴�. ���2���� stack�� �̿��� ȿ������ �ڵ��̴�. 
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
* ���2
* -> stack�� ������� �ʰ� ���� ���ڰ� stack�� ������ ū ���� �׳� push�Ѵ�. 
* -> stack�� ������� ��� �׳� push�Ѵ�. 
* -> ���� ���ο� ���� stack�� ������ ���� ���, pop�Ѵ�. 
* -> ���⼭ stack�� ���̴� ������ ������ ���ʿ� �ڽź��� ���� ���� �����ϴ� �����̴�. 
* -> ���� ���� ���� ���κ��� ���� ���� pop�� �ϴµ�, �� ���� �������� �� �� �ڽź��� ���� ���� �����ϴ� �ǹ��̹Ƿ� ó�� �����ߴ� logic���, ����, ������ ��� �ڽź��� ���� ���� �����ϴ� ���� �ǹ��Ѵ�. 
* -> ����, pop�� �ϸ鼭 ���信�� �����Ѵ�.
* 
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int solution(vector<int> a) {
    int answer = a.size();
    stack<int> stack;
    // stack�� ����ִ� ������ ó�� �����̰ų�,�ڽź��� ���ʿ� ���� ���� �ִ� ���ڵ��̴�.
    // ���� Ȯ���� ���ڰ� stack�� �ִ� ������ ���� ���, �� ���ڴ� �ڽ��� ����, ������ ��� �ڽź��� ���� ���ڰ� �ִ� ���� ���ı��� ����� ���� �Ұ����ϴ�. 

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