class Solution {
public:
    void DFS(vector<int>& nums, vector<vector<int>>& answer, vector<int> temp, int idx){
        answer.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            DFS(nums, answer, temp, i+1);
            temp.erase(temp.end()-1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> temp;
        DFS(nums, answer, temp, 0);
        return answer;
    }
};