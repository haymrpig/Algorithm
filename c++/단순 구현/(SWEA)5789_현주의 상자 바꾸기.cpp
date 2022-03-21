#include<iostream>
#include<vector>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, Q;
        cin >> N >> Q;
        vector<int> box(N+1, 0);
        for(int i=1;i<Q+1;i++){
            int L, R;
            cin >> L >> R;
            for(int j=L;j<=R;j++){
                box[j]=i;
            }
        }
        cout << '#' << test_case << ' ';
        for(int i=1;i<box.size();i++){
            cout << box[i];
            if(i<box.size()-1) cout << ' ';
        }
        cout << endl;
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}