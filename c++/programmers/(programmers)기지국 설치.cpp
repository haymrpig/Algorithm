#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
    ���� 20:19
    ���� 21:10
    - logic
    1. ��ġ�� ���׳��� ������ ��� ���� ���ο� ���׳��� ��ġ
    2. �ִ��� ���� ��ġ�ؾ� �ϹǷ� ��ġ ��ġ�� �·� w, ��� w�� Ŀ���� �� �ִ� �߰� ��ġ
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
* ��� 2. 
* 1. �ݺ����� ���� ������ ��ġ�� ���׳��� Ŀ���ϴ� ������ ������ ������ ���� ��, ���ο� ���׳��� Ŀ�� ������ ������. 
* 2. �̶�, �������� ����� ��� ���׳��� �߰��� ��ġ�ؾ� �ϹǷ� ceil()�Լ� ���
* 3. ������ ��ġ�� �� ���� ���׳��� ������ ��ġ�� ���, a�� ������ �����Ƿ� max�Լ��� ���� ������ ���� 0�� ��ġ�ϴ� ������ ���
* 4. ������ ��ġ�� ���׳��� ������ ������ ����� ���� ��, ������ ���׳����� ���������� ��ġ�� ���׳� ���� �߰��� ���Ѵ�. 
*/
int solution(int n, vector<int> stations, int w)
{
    int ret = 0;
    int prev = 0;
    for (int station : stations) {
        // ���� ���׳��� ������ ��ġ�� �ʴ� ������ ����
        int a = (station - w - 1) - prev;
        // ���ο� ���׳��� Ŀ���� �� �ִ� ���̸� �������� ������ ���Ѵ�. 
        int b = (int)ceil((double)a / (double)(w * 2 + 1));
        // �̸� ��ġ�� ���׳��� ������ ��ġ�� ���, �� �� ���̿��� �� ������ �����Ƿ�
        // a�� ������ �Ǿ� b�� ������ �ȴ�. 
        // ������ ��� ��ġ�� �ʿ䰡 �����Ƿ�, max(0,b)�� ���� ���� ����
        ret += max(0, b);
        prev = station + w;
    }
    // ������ ��ġ�� ������ ���׳��� �������� �ʴ� n������ �������� ��ġ�� ���ο� ���׳� ����
    ret += (int)ceil((double)(n - prev) / (double)(w * 2 + 1));
    return ret;
}