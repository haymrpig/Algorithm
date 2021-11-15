#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
*  - logic
* 1. 모든 점을 탐색하기에는 격자의 크기가 10^9*10^9으로 불가능했기에, 목적지부터 역순으로 가능한 격자들을 체크해나간다. 
* 
* 방법1. ( 시간초과 )
* 1. queue를 이용하여 가능한 격자를 count해나갔고, 마지막에 queue에 남아있는 원소의 수가 정답이다 -> queue를 이용하는 경우 시간초과 발생..
* 
* 방법2. ( 성공 )
* 1. 상,하,좌,우로 몇칸씩 이동하도록 되어 있고 만약 매 단계의 목적지가 테두리가 아니라면 가능한 경우의 수는 1이다. 
* 2. 만약 목적지가 테두리에 속한다면 가능한 경우의 수는 여러개이지만, 연속적인 블록의 형태를 띈다. 
        -> 즉, 가능한 경우의 수가 중간index를 건너뛰는 경우는 없다. 
        -> 사각형의 형태를 띈다. 
* 2. queue에 넣는 것이 아닌 row, column의 시작 index, 끝 index를 기록하여 마지막에 row와 column의 길이를 곱한다. ( 사각형의 넓이를 구한다. )
*/
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    long long rowStart = x, rowEnd = x;
    long long colStart = y, colEnd = y;
    for (int i = queries.size() - 1; i >= 0; i--) {
        int dir = queries[i][0];
        int num = queries[i][1];

        if (dir == 0) {
            if (colStart != 0) colStart += num;
            colEnd += num;
            if (colEnd >= m) colEnd = m - 1;
        }
        else if (dir == 1) {
            if (colEnd != m - 1) colEnd -= num;
            colStart -= num;
            if (colStart < 0) colStart = 0;
        }
        else if (dir == 2) {
            if (rowStart != 0) rowStart += num;
            rowEnd += num;
            if (rowEnd >= n) rowEnd = n - 1;
        }
        else if (dir == 3) {
            if (rowEnd != n - 1) rowEnd -= num;
            rowStart -= num;
            if (rowStart < 0) rowStart = 0;
        }
        if (rowEnd < rowStart || colEnd < colStart) return answer;
    }
    answer = (rowEnd - rowStart + 1) * (colEnd - colStart + 1);


    /*
    queue<pair<long, long>> q;
    q.push({x,y});
    for(int i=queries.size()-1;i>=0;i--){
        int size = q.size();
        int dir = queries[i][0];
        int numTemp = queries[i][1];
        for(int j=0;j<size;j++){
            int num = numTemp;
            int px = q.front().first;
            int py = q.front().second;
            q.pop();
            if( dir == 0 ){
                if( py != 0 && py+num < m ) q.push({px, py+num});
                else if( py==0 ){
                    while(num>=0){
                        if( py+num < m ){
                            q.push({px, py+num});
                        }
                        num--;
                    }
                }
            }
            else if( dir == 1 ){
                if( py != m-1 && py-num >= 0 ) q.push({px, py-num});
                else if( py==m-1 ){
                    while(num>=0){
                        if( py-num >=0 ){
                            q.push({px, py-num});
                        }
                        num--;
                    }
                }
            }
            else if( dir == 3 ){
                if( px != n-1 && px-num >= 0 ) q.push({px-num, py});
                else if( px==n-1 ){
                    while(num>=0){
                        if( px-num >=0 ){
                            q.push({px-num, py});
                        }
                        num--;
                    }
                }
            }
            else if( dir == 2 ){
                if( px != 0 && px+num < n ) q.push({px+num, py});
                else if( px==0 ){
                    while(num>=0){
                        if( px+num < n ){
                            q.push({px+num, py});
                        }
                        num--;
                    }
                }
            }
        }

    }
    answer = q.size();
    */
    return answer;
}