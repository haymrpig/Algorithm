#include<iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        map<char, int> m;
        m['S']=0;
        m['D']=1;
        m['H']=2;
        m['C']=3;
        
        string line;
        cin >> line;
        vector<vector<int>> card(4, vector<int> (13,0));
        bool flag = true;
		for(int i=0;i<line.size();i+=3){
        	char c = line[i];
            string num = "";
            num += line[i+1];
            num += line[i+2];
            
            int number = stoi(num)-1;
            int idx = m[c];
            
            card[idx][number]++;
            if(card[idx][number]>=2){
                cout << '#' << test_case << ' ' << "ERROR" << endl;
                flag=false;
                break;
            }
        }
        if(flag){
            cout << '#' << test_case << ' ';
        	for(int i=0;i<4;i++){
            	int cnt=0;
                for(int j=0;j<13;j++){
                	if(card[i][j]==0) cnt++;
                }
                cout << cnt << ' ';
            }
            cout << endl;
        }
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}