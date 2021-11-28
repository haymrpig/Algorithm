#include<iostream>
#include<vector>
#include<algorithm>
#define INF 100000000
using namespace std;

int main(int argc, char** argv)
{
    int railNum = 0, limit = 0, work = 0;
    cin >> railNum >> limit >> work;
    vector<int> weight;
    int temp;
    for (int i = 0; i < railNum; i++) {
        cin >> temp;
        weight.push_back(temp);
    }
    int best = INF;
    sort(weight.begin(), weight.end());

    do {
        int sumWeight = 0;
        int index = 0;
        for (int i = 0; i < work; i++) {
            int tempLimit = limit;
            while (1) {
                tempLimit -= weight[index];
                if (tempLimit < 0) break;
                sumWeight += weight[index++];
                index %= railNum;
            }
        }
        best = min(sumWeight, best);
    } while (next_permutation(weight.begin(), weight.end()));
    cout << best;
    return 0;
}