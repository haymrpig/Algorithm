#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
//시작 시간 20:31
// 처음에는 문제 이해를 잘못하여 시간이 겹치지 않게 하는 최소 강의실 수로 풀이하여 틀렸다.
// 두번째는 시작시간 기준으로 오름차순정렬하여 동적 프로그래밍 방식을 통해서 각 강의마다의 최적의 해를 구하려 했다. -> 시간초과
// 세번째는 끝시간을 기준으로 오름차순정렬하여 다음 강의 시작시간이 현재강의 끝시간보다 늦다면 cnt증가하는 방식으로 풀이하였다. -> 성공
// -> 위 세번째 방식은 남은 시간을 최대한 길게하여 더 많은 수업을 넣는 원리이다. 
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