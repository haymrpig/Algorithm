#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	long long targetCost = 0;
	int numCoin = 0;
	cin >> numCoin >> targetCost;
	vector<long long> coinCost(numCoin,0);
	for(int i=0;i<numCoin;i++){
		cin >> coinCost[i];
	}
	int leastNum = 0;
	for (int i = numCoin - 1; i >= 0; i--) {
		if (targetCost >= coinCost[i]) {
			leastNum += targetCost / coinCost[i];
			targetCost %= coinCost[i];
			if (targetCost == 0) break;
		}
	}
	cout << leastNum;

}
