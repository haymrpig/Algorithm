#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
*  - logic
* 1. ��� ���� Ž���ϱ⿡�� ������ ũ�Ⱑ 10^9*10^9���� �Ұ����߱⿡, ���������� �������� ������ ���ڵ��� üũ�س�����. 
* 
* ���1. ( �ð��ʰ� )
* 1. queue�� �̿��Ͽ� ������ ���ڸ� count�س�����, �������� queue�� �����ִ� ������ ���� �����̴� -> queue�� �̿��ϴ� ��� �ð��ʰ� �߻�..
* 
* ���2. ( ���� )
* 1. ��,��,��,��� ��ĭ�� �̵��ϵ��� �Ǿ� �ְ� ���� �� �ܰ��� �������� �׵θ��� �ƴ϶�� ������ ����� ���� 1�̴�. 
* 2. ���� �������� �׵θ��� ���Ѵٸ� ������ ����� ���� ������������, �������� ����� ���¸� ���. 
        -> ��, ������ ����� ���� �߰�index�� �ǳʶٴ� ���� ����. 
        -> �簢���� ���¸� ���. 
* 2. queue�� �ִ� ���� �ƴ� row, column�� ���� index, �� index�� ����Ͽ� �������� row�� column�� ���̸� ���Ѵ�. ( �簢���� ���̸� ���Ѵ�. )
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