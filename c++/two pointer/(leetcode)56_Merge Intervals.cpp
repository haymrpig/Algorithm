class Solution {
public:
    vector<vector<int>> answer;
    
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] < b[0] ) return true;
        else if(a[0] == b[0]){
            if(a[1]<b[1]) return true;
            else return false;
        }
        else return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int cur = 0;
        int start = intervals[cur][0];
        int end = intervals[cur][1];
        int length = intervals.size();
        while(1){
            cur++;
            if(cur >= length) break;
            if(intervals[cur][0] <= end){
                end = max(end, intervals[cur][1]);
            }
            else{
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                answer.push_back(temp);
                
                start = intervals[cur][0];
                end = intervals[cur][1];
                
            }
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        answer.push_back(temp);
        return answer;
    }
};