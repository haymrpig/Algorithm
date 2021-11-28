#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long 
#define MAXRANGE 1000000001
using namespace std;
/*
*	- Logic
*  1. 처음 vector에 삽입할 시, 시작점과 끝위치를 각각 나누어 {시작 위치, 높이 }, {끝 위치, -1*높이}로 저장한다. 
*		-> 이 때, 끝위치의 높이는 -1을 곱하여 삽입하는 이유는 끝 지점에서 그 빌딩의 영향력은 사라져야 하므로 해당 높이를 찾아 삭제하기 위함이다. 
*	2. multiset을 이용하는 이유는 시작위치와 끝위치가 중복이 될 수 있기 때문이다. 
*	3. 처음 vector를 위치에 따라 오름차순으로 정렬한다. 
*	4. multiset에는 높이를 삽입하고, 자동으로 오름차순 정렬이 된다. 
*	5. 만약 multiset에서 가장 높은 위치가 이전의 가장 높았던 위치와 다르다면 높이 갱신이 필요하므로 그 지점의 x와 높이를 출력한다. 
*		-> 이전 높이를 그 지점의 높이로 갱신한다. 
*	6. 만약 높이가 음수인 위치를 찾게 되면, multiset에서 그 높이의 양수인 값을 찾아 삭제한다. ( 그 빌딩의 영향력이 끝났으므로 )
*	7. 처음에 multiset에는 0을 삽입한다. ( 빌딩 사이가 비어있을 경우, 높이는 0으로 갱신되야 하므로 )
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
			// 반복문을 사용하는 이유는 같은 위치에 있는 건물이 여러개일 수 있기 때문이다. 
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