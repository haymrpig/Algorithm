#include <iostream>
#include <vector>
/*
*	-Logic
*	1. ������ �Ա� ������ ���̴� ü���� �ִ�ġ�� ã�´�.
*	2. �׻� 1�̻��� ü���� ������ �ϹǷ� �ִ�ġ+1�� ����
* 
*	!! ���� !!
*	1. ������ ���� ������ ���������� �� damage�� max_damage�� ���ؼ� ���� ū ������ �ִ�ġ�� ã�Ҵµ�, ���� �߻�
*		-> ������ �ϳ��� ���� �ʴ� ��찡 �߻��� �� �����Ƿ� �Ź� damage�� ���� ������ ������ ���ش�. 
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