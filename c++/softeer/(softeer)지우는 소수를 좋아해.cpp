#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#define INF 100000000
//���۽ð� 14:35
// ��1. ���ͽ�Ʈ�� �˰��� ����, �켱���� ť�� ������������ �����ϸ� �ð����⵵�� O(NlogN)���� ���� �� �ִ�.
// ��2. �Ҽ�ã�� �˰����� ����� ��, ã���� �ϴ� ������ ū ���� ���������� �������� ���ϴ� ���� �� ȿ�����̴�. 
using namespace std;

bool isPrime(int num) {
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0) return false;
    else {
        for (int i = 3; i <= sqrt(num); i += 2) {
            if (num % i != 0) continue;
            else return false;
        }
        return true;
    }
}
int main(int argc, char** argv)
{
    int gymNum = 0, roadNum = 0;
    cin >> gymNum >> roadNum;
    vector<pair<int, int>> info[10001];
    vector<int> dist(10001, INF);
    while (roadNum--) {
        int start = 0, end = 0, weight = 0;
        cin >> start >> end >> weight;
        info[start].push_back({ end, weight });
        info[end].push_back({ start,weight });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//weight, gym
    pq.push({ 0,1 });
    while (!pq.empty()) {
        int preWeight = pq.top().first;
        int preGym = pq.top().second;
        pq.pop();
        for (int i = 0; i < info[preGym].size(); i++) {
            int nextGym = info[preGym][i].first;
            int nextWeight = info[preGym][i].second;
            nextWeight < preWeight ? nextWeight = preWeight : nextWeight;
            if (dist[nextGym] > nextWeight) {
                dist[nextGym] = nextWeight;
                pq.push({ nextWeight, nextGym });
            }
        }
    }
    //cout << dist[gymNum];
    // ��� �Ҽ� ã�� -> �ð��ʰ�
    /*
    vector<int> prime(INF+1,1);
    prime[1] = 0;
    prime[2] = 1;
    for(int i=4;i<INF+1;i+=2) prime[i]=0;
    for(int i=3;i<=sqrt(INF+1);i++){
        if( i % 2 != 0){
            for(int j=2*i;j<=INF+1;j+=(2*i)){
                prime[j]=0;
            }
        }
    }
    */

    for (int i = dist[gymNum] + 1; i < INF + 1; i++) {
        if (isPrime(i) == true) {
            cout << i;
            break;
        }
    }
    return 0;
}