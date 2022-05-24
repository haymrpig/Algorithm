class Solution {
public:
    string convert(string s, int numRows) {
        int len_str = s.size();
        string answer = "";
        
        int base = 2*numRows - 2;
        if(base==0) return s;
        
        int cur_idx = 1;
        int interval[3], temp_idx;
        while(cur_idx <= numRows){
            temp_idx = cur_idx;
            interval[0] = base - 2*(cur_idx-1);
            interval[1] = 2*(cur_idx-1);
            for(int i=0;;i++){
                if(temp_idx > len_str) break;
                answer+=s[temp_idx-1];
                if(cur_idx != 1 && cur_idx != numRows) temp_idx += interval[i%2];
                else temp_idx += base;
            }
            cur_idx++;
        }
        return answer;
    }
};