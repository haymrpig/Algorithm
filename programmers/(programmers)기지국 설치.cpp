#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
    시작 20:19
    종료 21:10
    - logic
    1. 설치된 안테나의 범위를 벗어난 곳에 새로운 안테나를 설치
    2. 최대한 적게 설치해야 하므로 설치 위치는 좌로 w, 우로 w를 커버할 수 있는 중간 위치
*/
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int check = w+1, start, end;
    int index = -1;
    while( check-w <= n ){
        if( ++index < stations.size() ){
            stations[index]-w >= 0 ? start = stations[index]-w: start = 1;
            stations[index]+w <= n ? end = stations[index]+w: end = n;
        }
        else{
            start = n+1;
            end = n+1;
        }
        while( start > check-w ){
            answer++;
            check+=(2*w+1);
        }
        check = end+w+1;
    }
    return answer;
}

/*
* 방법 2. 
* 1. 반복문을 통해 이전의 설치한 안테나가 커버하는 영역을 제외한 영역을 구한 후, 새로운 안테나의 커버 범위로 나눈다. 
* 2. 이때, 나머지가 생기는 경우 안테나를 추가로 설치해야 하므로 ceil()함수 사용
* 3. 기존에 설치한 두 대의 안테나의 범위가 겹치는 경우, a는 음수가 나오므로 max함수를 통해 음수인 경우는 0개 설치하는 것으로 계산
* 4. 기존의 설치한 안테나를 제외한 영역의 계산이 끝난 후, 마지막 안테나에서 끝범위까지 설치할 안테나 수를 추가로 더한다. 
*/
int solution(int n, vector<int> stations, int w)
{
    int ret = 0;
    int prev = 0;
    for (int station : stations) {
        // 이전 안테나가 영향을 미치지 않는 구역의 길이
        int a = (station - w - 1) - prev;
        // 새로운 안테나가 커버할 수 있는 길이를 나눔으로 개수를 구한다. 
        int b = (int)ceil((double)a / (double)(w * 2 + 1));
        // 미리 설치된 안테나의 범위가 겹치는 경우, 그 둘 사이에는 빈 구역이 없으므로
        // a가 음수가 되어 b도 음수가 된다. 
        // 음수일 경우 설치할 필요가 없으므로, max(0,b)를 통해 음수 제거
        ret += max(0, b);
        prev = station + w;
    }
    // 이전에 설치된 마지막 안테나가 포함하지 않는 n까지의 구역에서 설치할 새로운 안테나 개수
    ret += (int)ceil((double)(n - prev) / (double)(w * 2 + 1));
    return ret;
}