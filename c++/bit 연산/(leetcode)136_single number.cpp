class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map을 이용한 풀이
        /*
        map<int, int> m;
        for(auto num:nums){
            m[num]++;
        }
        for(auto iter=m.begin();iter!=m.end();iter++){
            if(iter->second==1) return iter->first;
        }
        return 0;
        */
        
        // xor 연산을 이용한 풀이
        int num = nums[0];
        for(int i=1;i<nums.size();i++){
            num = num^nums[i];
        } 
        return num;
    }
};