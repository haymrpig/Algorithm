#include<iostream>
#include<vector>
#define INF 1000000000

// 처음 풀었던 방식 -> dp로 풀었을 경우 O(N^2)으로 시간초과 발생
// 두번째 방식 -> 앞에서부터 점점 커지는 값을 저장
//					 -> 뒤에서부터 점점 커지는 값을 저장
//					 ->  이 둘의 합 중 큰 값이 정답 
//					 -> 이 때 배열을 하나 더 생성하여 값을 저장( 오름차순이기 때문에 넣을 값을 이진탐색을 통해 O(logN)으로 찾기 가능

using namespace std;
/*
int main(int argc, char** argv)
{
	int stoneNum = 0;
	cin >> stoneNum;
	vector<int> stoneHeight;
	vector<vector<int>> d(stoneNum, vector<int>(2, 1));
	for (int i = 0; i < stoneNum; i++) {
		int height;
		cin >> height;
		stoneHeight.push_back(height);
	}
	for (int i = 1; i < stoneNum; i++) {
		for (int j = 0; j < i; j++) {
			if (stoneHeight[j] < stoneHeight[i]) d[i][0] = max(d[i][0], d[j][0] + 1);
			else if (stoneHeight[j] > stoneHeight[i]) d[i][1] = max(d[i][1], max(d[j][0] + 1, d[j][1] + 1));
		}
	}
	int ans = 0;
	for (int i = 0; i < stoneNum; i++) {
		ans = max(ans, max(d[i][0], d[i][1]));
	}
	cout << ans << endl;
	return 0;
}
*/


int search(vector<int>& temp, int start, int end,int target){
	int mid=0;
	while(start <= end){
		mid = (start+end)/2;
		if( temp[mid] == target ) return mid;
		else if( temp[mid] < target ){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
	}
	return start;
}
int main(int argc, char** argv)
{
	int stoneNum=0;
	cin >> stoneNum;
	vector<int> stoneHeight;
	for(int i=0;i<stoneNum;i++){
		int height;
		cin >> height;
		stoneHeight.push_back(height);
	}
	vector<int> up;
	vector<int> down;

	vector<int> temp(stoneNum,INF);
	int size=1;
	temp[0]=stoneHeight[0];
	up.push_back(1);
	for(int i=1;i<stoneNum;i++){
		int index=search(temp,0,size,stoneHeight[i]);
		size = max(size,index);
		temp[index]=stoneHeight[i];
		up.push_back(index+1);
	}

	temp.clear();
	for(int i=0;i<stoneNum;i++) temp.push_back(INF);
	size=0;
	temp[0]=stoneHeight[stoneNum-1];
	down.push_back(1);
	for(int i=stoneNum-2;i>=0;i--){
		int index=search(temp,0,size,stoneHeight[i]);
		size=max(size,index);
		temp[index]=stoneHeight[i];
		down.push_back(index+1);
	}
	int ans=0;
	for(int i=0;i<stoneNum;i++){
		ans=max(ans,up[i]+down[stoneNum-i-1]);
	}
	cout << ans-1 << endl;

	return 0;
}
