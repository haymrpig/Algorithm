#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long 
#define MAXRANGE 1000000001
using namespace std;
/*
*	- Logic
*  1. ó�� vector�� ������ ��, �������� ����ġ�� ���� ������ {���� ��ġ, ���� }, {�� ��ġ, -1*����}�� �����Ѵ�. 
*		-> �� ��, ����ġ�� ���̴� -1�� ���Ͽ� �����ϴ� ������ �� �������� �� ������ ������� ������� �ϹǷ� �ش� ���̸� ã�� �����ϱ� �����̴�. 
*	2. multiset�� �̿��ϴ� ������ ������ġ�� ����ġ�� �ߺ��� �� �� �ֱ� �����̴�. 
*	3. ó�� vector�� ��ġ�� ���� ������������ �����Ѵ�. 
*	4. multiset���� ���̸� �����ϰ�, �ڵ����� �������� ������ �ȴ�. 
*	5. ���� multiset���� ���� ���� ��ġ�� ������ ���� ���Ҵ� ��ġ�� �ٸ��ٸ� ���� ������ �ʿ��ϹǷ� �� ������ x�� ���̸� ����Ѵ�. 
*		-> ���� ���̸� �� ������ ���̷� �����Ѵ�. 
*	6. ���� ���̰� ������ ��ġ�� ã�� �Ǹ�, multiset���� �� ������ ����� ���� ã�� �����Ѵ�. ( �� ������ ������� �������Ƿ� )
*	7. ó���� multiset���� 0�� �����Ѵ�. ( ���� ���̰� ������� ���, ���̴� 0���� ���ŵǾ� �ϹǷ� )
*/
int main() {
	int N = 0;
	cin >> N;
	vector<pair<ll, ll>> v;
	for (int i = 0; i < N; i++) {
		ll start=0, end=0, height=0;
		cin >> start >> height >> end;
		v.push_back({ start, height });
		v.push_back({ end, -height });
	}
	sort(v.begin(), v.end());
	v.push_back({MAXRANGE, -1});
	multiset<ll> ms;
	ms.insert(0);
	ll preHeight = -1;
	ll preX = v[0].first;
	int index = 0;
	ll h = 0;
	while (index < 2 * N) {
		while (preX == v[index].first) {
			// �ݺ����� ����ϴ� ������ ���� ��ġ�� �ִ� �ǹ��� �������� �� �ֱ� �����̴�. 
			h = v[index].second;
			if (h < 0) ms.erase(ms.find(-h));
			else ms.insert(h);
			index++;
		}
		ll heightTemp = *prev(ms.end());
		if (heightTemp != preHeight) {
			cout << preX << " " << heightTemp << " ";
			preHeight = heightTemp;
		}
		preX = v[index].first;
	}
}