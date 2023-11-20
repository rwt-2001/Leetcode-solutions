class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        
        int travel = 1;
        int curMin = nums[0];
        int ans = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            
            if(curMin > nums[i])
            {
                curMin = nums[i];
                ans+=i;
            }
            
        }
        
        return ans;
    }
};
// 3 2 2 1 1
// 1
    
