#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& cctv){
    bool temp = cctv[0];
    for(int i=1;i<4;i++){
        cctv[i-1]=cctv[i];
    }
    cctv[3]=temp;
    return;
}

void check(vector<vector<int>>& room, vector<vector<bool>>& cctv){
    
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> room(N,vector<int>(N));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> room[i][j];
        }
    }

    vector<vector<bool>> cctv(5, vector<bool>(4,false));
    cctv[0][1]=true;
    cctv[1][1]=true; cctv[1][3]=true;
    cctv[2][0]=true; cctv[2][1]=true; 
    cctv[3][0]=true; cctv[3][1]=true; cctv[3][3]=true;
    cctv[4][0]=true; cctv[4][1]=true; cctv[4][2]=true; cctv[4][3]=true;
    
    vector<bool> temp(4);
    temp = cctv[0];
    temp[0]=true;
    for(auto x: cctv[0]) cout << x;
}