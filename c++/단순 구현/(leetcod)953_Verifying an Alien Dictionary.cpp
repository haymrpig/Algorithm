class Solution {
public:
    map<char, char> m;
    bool isAlienSorted(vector<string>& words, string order) {
        int idx = 0;
        for(auto letter:order){
            m[letter]= 'a'+idx++;
        }
        //0부터 번호 매김
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                words[i][j] = m[words[i][j]];
            }
        }
        
        return is_sorted(words.begin(), words.end());
    }
};