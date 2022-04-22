class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> umap;
        int l=0,r=0; 
        int res=0, maxi=0;
        while(r<s.length()){
            umap[s[r]]++;
            maxi=max(maxi,umap[s[r]]);
            // 현재 슬라이딩 윈도우에서 가장 빈도가 높은 숫자의 개수 = maxi
            if((r-l+1)-maxi>k){
                // 슬라이딩 윈도우 사이즈 - 슬라이딩 윈도우 내에서 가장 빈도가 높은 숫자 = 바꿔야 하는 숫자의 수
                // 이 수가 k보다 크면 성립이 안된다. 
                umap[s[l]]--;
                l++;
                // 줄어든 숫자 개수 하나 감소
                // 윈도우를 왼쪽을 하나 증가시킨다.
            }
            res = max(maxi,(r-l+1));
            // 
            r++;
        }
        return res;
    }
};