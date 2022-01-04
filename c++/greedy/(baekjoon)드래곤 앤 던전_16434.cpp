#include <iostream>
#include <vector>
/*
*	-Logic
*	1. 포션을 먹기 전까지 깎이는 체력의 최대치를 찾는다.
*	2. 항상 1이상의 체력은 가져야 하므로 최대치+1이 정답
* 
*	!! 주의 !!
*	1. 포션을 먹을 때마다 이전까지의 총 damage와 max_damage를 비교해서 가장 큰 데미지 최대치를 찾았는데, 예외 발생
*		-> 포션을 하나도 먹지 않는 경우가 발생할 수 있으므로 매번 damage를 입을 때마다 갱신을 해준다. 
*/
using namespace std;

int main(int* argc, char** argv) {
	int num_room;
	long long cur_atk;
	cin >> num_room >> cur_atk;

	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < num_room; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back({a,{b,c} });
	}

	long long total_damage = 0;
	long long max_damage = 0;
	for (int i = 0; i < v.size(); i++) {
		int room = v[i].first;
		if (room == 1) {
			int dragon_hp = v[i].second.second;
			int dragon_atk = v[i].second.first;
			int num_damage = dragon_hp % cur_atk == 0 ? dragon_hp / cur_atk - 1 : dragon_hp / cur_atk;
			total_damage += (long long)dragon_atk * (long long)num_damage;
			max_damage = max(max_damage, total_damage);
		}
		else {
			cur_atk += v[i].second.first;
			total_damage -= v[i].second.second;
			if (total_damage < 0) total_damage = 0;
		}
	}
	cout << max_damage+1;
}