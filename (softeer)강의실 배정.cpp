#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
//���� �ð� 20:31
// ó������ ���� ���ظ� �߸��Ͽ� �ð��� ��ġ�� �ʰ� �ϴ� �ּ� ���ǽ� ���� Ǯ���Ͽ� Ʋ�ȴ�.
// �ι�°�� ���۽ð� �������� �������������Ͽ� ���� ���α׷��� ����� ���ؼ� �� ���Ǹ����� ������ �ظ� ���Ϸ� �ߴ�. -> �ð��ʰ�
// ����°�� ���ð��� �������� �������������Ͽ� ���� ���� ���۽ð��� ���簭�� ���ð����� �ʴٸ� cnt�����ϴ� ������� Ǯ���Ͽ���. -> ����
// -> �� ����° ����� ���� �ð��� �ִ��� ����Ͽ� �� ���� ������ �ִ� �����̴�. 
using namespace std;

int main(int argc, char** argv)
{
    vector<pair<int, int>> info;
    int classNum = 0;
    cin >> classNum;
    int start = 0, end = 0;
    while (classNum--) {
        cin >> start >> end;
        info.push_back({ end, start });
    }
    sort(info.begin(), info.end());

    int index = 0;
    int cnt = 1;
    for (int i = index + 1; i < info.size(); i++) {
        if (info[index].first <= info[i].second) {
            index = i;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}