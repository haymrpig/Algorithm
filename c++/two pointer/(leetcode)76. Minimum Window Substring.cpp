class Solution {
public:
    bool check(map<char,int>& m){
        for(auto iter=m.begin();iter!=m.end();iter++){
            if(iter->second > 0) return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        
        map<char, int> m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        
        int start = 0;
        string answer = "";
        int min_len = s.size();
        for(int end=0;end<s.size();end++){
            if(m.find(s[end])!=m.end()){
                m[s[end]]--;
            }
            
            while(check(m)){
                if(min_len > end-start){
                    min_len = end-start;
                    answer = s.substr(start, end-start+1);
                }
                if(m.find(s[start])!=m.end()){
                    m[s[start]]++;
                }
                start++;
            }
        }
        
        return answer;
    }
};