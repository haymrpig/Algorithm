/*
* - two pointer의 확장형이라고 생각
* - 앞의 숫자를 고정하고, two pointer진행
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        
        // 미리 변수로 저장하는 이유는 nums.size()는 int형이 아니기 때문에 만약 nums의 사이즈가 0일때, -2를 하면 매우 큰 수가 나온다. 
        int n = nums.size();
        
        // 이 부분은 안넣어도 되지만, 0의 경우 (a, 0, -a) 또는 (0, 0, 0)으로 1개 또는 3개밖에 안쓰이므로, 더 많이 있을 경우 없애는게 runtime을 줄일 수 있다. 
        vector<int> nums_;
        int zero_cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero_cnt++;
                if(zero_cnt > 3) continue;
            }
            nums_.push_back(nums[i]);
        }
        
        n = nums_.size();
        
        vector<vector<int>> answer;

        stable_sort(nums_.begin(), nums_.end());
        
        for(int i=0;i<n-2;i++){
            int l = i+1;
            int h = n-1;
            
            while(l < h){
                int sum = nums_[i]+nums_[l]+nums_[h];
                
                if(sum==0){
                    s.insert({nums_[i], nums_[l], nums_[h]});
                    l++;
                    h--;
                }
                else if(sum > 0){
                    h--;
                }
                else if(sum < 0){
                    l++;
                }
            }
        }    
        
        for(vector<int> x:s){
            answer.push_back(x);
        }

        return answer;
    }
};